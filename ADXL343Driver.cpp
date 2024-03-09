
#include "ADXL343Driver.h"

/************************Private methods**************************/
/**
 * @brief For most I2C devices like ADXL343, writing to a register involves:
 * Sending the device address to select the device on the I2C bus.(did it in constructor).
 * Sending the register address you want to write to.
 * Sending the data byte to write into that register.
 */
bool ADXL343::writeRegister(uint8_t reg, uint8_t value)
{
    char data[2];
    data[0] = static_cast<char>(reg);                    // Register address
    data[1] = static_cast<char>(value);                  // Data to write

    FunctionStatus status = i2c->i2cWrite(data, 2, 100); // Example timeout of 100 ms

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
 */
uint8_t ADXL343::readRegister(uint8_t reg)
{
    uint8_t value = 0;
    i2c->i2cWrite(reinterpret_cast<const char*>(&reg), 1, 100);     // Assuming this method exists and works as described

    i2c->i2cRead(reinterpret_cast<char*>(&value), 1, 100);          // Assuming this method exists and works as described

    return value;

}

/************************Public methods**************************/
/**
 * @brief Constructor
 */
ADXL343::ADXL343(I2C_Simulator *i2c_, uint8_t address_)
{
    i2c = i2c_;
    address = address_;
}

/**
 * @brief initialize Sensor
 * Wake up the device and set it to measure mode
 * Set data format
 */
bool ADXL343::initialize()
{
    // Bit 3 high to start measuring
    // 4g range, for example
    if (writeRegister(ADXL343_Registers::POWER_CTL, 0x08) & writeRegister(ADXL343_Registers::DATA_FORMAT, 0x01))
        return true;
}

void ADXL343::readAcceleration(int16_t &x, int16_t &y, int16_t &z)
{
	x = (readRegister(ADXL343_Registers::DATAX1) << 8) | readRegister(ADXL343_Registers::DATAX0);
	y = (readRegister(ADXL343_Registers::DATAY1) << 8) | readRegister(ADXL343_Registers::DATAY0);
	z = (readRegister(ADXL343_Registers::DATAZ1) << 8) | readRegister(ADXL343_Registers::DATAZ0);
}