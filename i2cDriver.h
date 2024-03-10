#ifndef I2CDRIVER_H_
#define I2CDRIVER_H_


/******************************************************************************
 * @file           : i2c_drive.h
 * @brief          : I2C Driver Module Interface
 * 
 * This library provides an interface for I2C (Inter-Integrated Circuit) communication. It abstracts the lower-level
 * details of hardware interaction, facilitating communication with I2C peripherals. The module is designed to be
 * portable, efficient, and easy to use, with support for both blocking and non-blocking operations. It includes
 * functions for initializing the I2C bus, reading from and writing to I2C devices, and handling common I2C
 * operations with robust error management.
 *
 * Usage of this module allows for clear, concise, and efficient I2C communication implementations, supporting
 * a wide range of I2C slave devices. It is suitable for projects requiring communication with sensors, memory
 * modules, and other I2C-compatible peripherals.
 * @date           : 2024/03/09
 */

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>            //!< Include to use standard boolean
#include <stdint.h>             //!< Include to use integer types


 /**
 * @enum FunctionStatus
 */
typedef enum
{
    // General rage
    FUNCTION_STATUS_OK = 0,                             //!< The function execution was successful
    FUNCTION_STATUS_ERROR,                              //!< The function execution caused an unspecific error
    FUNCTION_STATUS_NOT_INITIALIZED,                    //!< The function execution was aborted because the module
                                                        //!< instance is not initialized
    FUNCTION_STATUS_ALREADY_INITIALIZED,                //!< The function execution was aborted because the module
                                                        //!< instance is already initialized
    FUNCTION_STATUS_ARGUMENT_ERROR,                     //!< At least one argument of the function was NULL (invalid)
    FUNCTION_STATUS_BOUNDARY_ERROR,                     //!< At least one argument is out of boundary
    FUNCTION_STATUS_TIMEOUT,                            //!< A timeout occurred during function execution
} FunctionStatus;


/**
 * @brief I2C Communication Simulator
 * This class simulates I2C communication for development and testing purposes. It provides
 * interfaces to simulate writing to and reading from an I2C device without requiring actual
 * hardware. This enables testing of I2C device drivers, such as those for the ADXL343 accelerometer,
 * in a controlled environment.
 */
class I2C_Simulator
{
private:
    uint32_t simulatedTimeoutDuration = 0; // in milliseconds
public:
    FunctionStatus i2cWrite(const char *dataToWrite, size_t length, uint32_t simulatedTimeoutDuration);
    FunctionStatus i2cRead(char *dataToRead, size_t length, uint32_t simulatedTimeoutDuration);
};

#endif /*I2CDRIVER_H_ */