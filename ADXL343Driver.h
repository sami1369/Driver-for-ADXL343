#ifndef ADXL343DRIVER_H_
#define ADXL343DRIVER_H_
/******************************************************************************
 * @file           : ADXL343Driver.h
 * @brief          : ADXL343 Driver Module Interface
 *                   This is a library for Simulate ADXL343 Sensor 
 * @date           : 2024/03/09
 ******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "i2cDriver.h"

// ADXL343-specific definitions
namespace ADXL343_Registers {
    const uint8_t DEVICE_ADDRESS        = 0x53; // Assuming SDO/ALT ADDRESS is grounded
    const uint8_t POWER_CTL             = 0x2D;
    const uint8_t DATA_FORMAT           = 0x31;
    const uint8_t DATAX0                = 0x32;
    const uint8_t DATAX1                = 0x33;
    const uint8_t DATAY0                = 0x34;
    const uint8_t DATAY1                = 0x35;
    const uint8_t DATAZ0                = 0x36;
    const uint8_t DATAZ1                = 0x37;
    // Add other registers as needed
}

class ADXL343
{

private:
	I2C_Simulator		*i2c;
    uint8_t             address;

public:
    ADXL343(I2C_Simulator *i2c_, uint8_t address_ );

};


#endif  /*ADXL343DRIVER_H_*/