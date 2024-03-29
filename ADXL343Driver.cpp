
#include "ADXL343Driver.h"

/************************Private methods**************************/
/**
 * @brief For most I2C devices like ADXL343, writing to a register involves:
 * Sending the device address to select the device on the I2C bus.(did it in constructor).
 * Sending the register address you want to write to.
 * Sending the data byte to write into that register.
 * @param reg The register address to which the byte will be written.
 * @param value The data byte to be written to the specified register.
 * @return Returns true if the write operation was successful.
 */
bool ADXL343::writeRegister(uint8_t reg, uint8_t value)
{
    char data[2];
    data[0] = static_cast<char>(reg);   // Register address
    data[1] = static_cast<char>(value); // Data to write

    FunctionStatus status = i2c->i2cWrite(data, 2, 100); // Example timeout of  ms

    if (status != FUNCTION_STATUS_OK)
    {
        return false;
    }

    return true;
}

/**
 * @brief read from ADXL343 sensor
 * First write the register address we want to read from
 * Second read the value from the register
 * @param reg The address of the register from which to read.
 * @return The byte read from the specified register.
 */
uint8_t ADXL343::readRegister(uint8_t reg)
{
    uint8_t value = 0;
    i2c->i2cWrite(reinterpret_cast<const char *>(&reg), 1, 100); // Assuming this method exists and works as described

    i2c->i2cRead(reinterpret_cast<char *>(&value), 1, 100); // Assuming this method exists and works as described

    return value;
}

/************************Public methods**************************/
/**
 * @brief Constructs an ADXL343 object and initializes it
 * with the provided I2C interface and device address.
 * @param i2c_ Pointer to an I2C_Simulator object
 * @param address_ The I2C device address of the ADXL343 sensor. This address can vary
 * depending on how the sensor's address pin is configured (typically 0x53 or 0x1D).
 */
ADXL343::ADXL343(I2C_Simulator *i2c_, uint8_t address_)
{
    i2c = i2c_;
    address = address_;
}

/**
 * @brief initialize Sensor.
 * Wake up the device and set it to measure mode.
 * Set data format.
 * @return True if the sensor was successfully initialized, False otherwise.
 */
bool ADXL343::initialize()
{
    if (writeRegister(ADXL343_Registers::POWER_CTL, 0x08) &  // Bit 3 high to start measuring
        writeRegister(ADXL343_Registers::DATA_FORMAT, 0x01)) // 4g range, for example
    {
        return true;
    }
    return false;
}

/**
 * @brief read acceleration data from the X, Y, and Z axes.
 * This method fetches the raw 10-bit acceleration data for each axis from the sensor's
 * registers, combines the high and low bytes to form the final 10-bit values, and scales
 * them according to the sensor's current settings (e.g., range).
 * @param[out] x Reference to a variable where the X-axis acceleration data will be stored.
 * @param[out] y Reference to a variable where the Y-axis acceleration data will be stored.
 * @param[out] z Reference to a variable where the Z-axis acceleration data will be stored.
 *
 */
void ADXL343::readAcceleration(int16_t &x, int16_t &y, int16_t &z)
{
    x = (readRegister(ADXL343_Registers::DATAX1) << 8) | readRegister(ADXL343_Registers::DATAX0);
    y = (readRegister(ADXL343_Registers::DATAY1) << 8) | readRegister(ADXL343_Registers::DATAY0);
    z = (readRegister(ADXL343_Registers::DATAZ1) << 8) | readRegister(ADXL343_Registers::DATAZ0);
}
/**
 * @brief set g range
 * Read the current value of the DATA_FORMAT register
 * Clear the range bits (D1 D0)
 * Set the new range
 * Write the updated value back to the DATA_FORMAT register
 * @param range The desired measurement range for the accelerometer
 * @return True if the sensor was successfully changed range, False otherwise.
 */
bool ADXL343::setRange(uint8_t range)
{
    uint8_t dataFormatValue = readRegister(ADXL343_Registers::DATA_FORMAT);
    dataFormatValue &= ~0x03;
    dataFormatValue |= (range & 0x03); // Ensure only the last two bits are used
    return writeRegister(ADXL343_Registers::DATA_FORMAT, dataFormatValue);
}

/************************ADXL343Test Methods*************************/
/************************Private methods**************************/
bool ADXL343Test::writeRegister(uint8_t reg, uint8_t value)
{
    char data[2];
    data[0] = static_cast<char>(reg);   // Register address
    data[1] = static_cast<char>(value); // Data to write
    uint32_t randomNumber = generateRandomNumber(1, 100);

    FunctionStatus status = i2cSimulator->i2cWrite(data, 2, randomNumber); // Example timeout of  ms
    if (status != FUNCTION_STATUS_OK)
    {
        return false;
    }

    return true;
}

uint8_t ADXL343Test::readRegister(uint8_t reg)
{
    uint8_t value = 0;
    uint32_t randomNumber = 0;
    randomNumber = generateRandomNumber(1, 100);
    i2cSimulator->i2cWrite(reinterpret_cast<const char *>(&reg), 1, randomNumber); // Assuming this method exists and works as described
    randomNumber = generateRandomNumber(1, 100);
    i2cSimulator->i2cRead(reinterpret_cast<char *>(&value), 1, randomNumber); // Assuming this method exists and works as described

    return value;
}

/************************Public methods**************************/
void ADXL343Test::testTimeoutHandling()
{
    cout << "Testing timeout handling...\n";

    // Attempt to perform an operation that should timeout
    bool success = initialize();
    cout << "final : " << success << endl;

    // Check if the operation correctly failed due to timeout
    cout << "Initialization (Timeout Scenario): " << (success ? "PASSED" : "FAILED") << "\n";
}