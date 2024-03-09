
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
    data[0] = static_cast<char>(reg);   // Register address
    data[1] = static_cast<char>(value); // Data to write

    FunctionStatus status = i2c->i2cWrite(data, 2, 100); // Example timeout of 100 ms
    if (status != FUNCTION_STATUS_OK)
    {
        return false;
    }

    return true;
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