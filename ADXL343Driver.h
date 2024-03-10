#ifndef ADXL343DRIVER_H_
#define ADXL343DRIVER_H_
/******************************************************************************
 * @file           : ADXL343Driver.h
 * @brief          : Header file for the ADXL343 Accelerometer Driver
 * 
 * This library provides an interface for interacting with the ADXL343 accelerometer
 * using I2C communication. It supports initializing the sensor, reading acceleration
 * data from the X, Y, and Z axes, and configuring the measurement range. Designed
 * for ease of use, this driver abstracts away the low-level details of sensor
 * communication, offering a simple API for sensor data acquisition and configuration.
 * 
 * The implementation assumes use of an I2C_Simulator for I2C transactions, which can
 * be replaced with actual I2C communication routines in a production environment.
 *
 * @note This driver does not cover all functionalities of the ADXL343 sensor. It focuses
 * on essential features for basic sensor operation. Further development may be
 * required for advanced sensor features and configurations.
 * @date           : 2024/03/09
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include "i2cDriver.h"

/**
 * @brief ADXL343-specific definitions
 */
namespace ADXL343_Registers {
    const uint8_t DEVICE_ADDRESS        = 0x53;     // Assuming SDO/ALT ADDRESS is grounded
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

/**
 * @brief Used with register 0x31 (ADXL3XX_REG_DATA_FORMAT) to set g range 
 */
typedef enum {
  ADXL343_RANGE_16_G    = 0b11,     // +/- 16g 
  ADXL343_RANGE_8_G     = 0b10,     // +/- 8g
  ADXL343_RANGE_4_G     = 0b01,     // +/- 4g 
  ADXL343_RANGE_2_G     = 0b00,     // +/- 2g (default value)
}adxl34x_range_t;

/**
 * @brief Driver for interfacing with the ADXL343 accelerometer sensor.
 * This class provides methods for initializing the ADXL343 sensor, configuring its measurement
 * range, and reading acceleration data along the X, Y, and Z axes. It utilizes an I2C_Simulator
 * object for I2C communication, abstracting the lower-level details of sensor data transactions.
 */
class ADXL343
{

private:
	I2C_Simulator		*i2c;
    uint8_t             address;
    bool     writeRegister(uint8_t reg, uint8_t value);
    uint8_t  readRegister(uint8_t reg);

public:
    ADXL343(I2C_Simulator *i2c_, uint8_t address_ );

    bool    initialize();
    void    readAcceleration(int16_t& x, int16_t& y, int16_t& z);
    bool    setRange(uint8_t range);
};


#endif  /*ADXL343DRIVER_H_*/