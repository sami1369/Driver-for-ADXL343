// --------------------------------------------------------------------------------------------------------------------
// Include files
// --------------------------------------------------------------------------------------------------------------------
#include "i2cDriver.h"
#include <chrono> //to generate time
#include <iostream>
using namespace std;
using namespace std::chrono;

/************************Public methods**************************/
/**
 * @brief  Simulates writing data to an I2C device.
 * This method simulates the process of writing data over the I2C bus to a device. It is designed
 * to mimic the behavior of an actual I2C write operation, including error handling for invalid 
 * arguments and operation timeouts. 
 * @param dataToWrite Pointer to the data buffer containing the bytes to be written. 
 * @param length The number of bytes in the data buffer to write. 
 * @param timeout The maximum duration (in milliseconds) the method will attempt to write before 
 * timing out. This simulation checks the timeout but does not implement a real delay.
 *
 * @return Returns FunctionStatus based on the enum defined to error handling
 */
FunctionStatus I2C_Simulator::i2cWrite(const char *dataToWrite, size_t length, uint32_t timeout)
{
	auto startTime = steady_clock::now(); // Start time
	if (dataToWrite == NULL)
	{
		return FUNCTION_STATUS_ARGUMENT_ERROR;
	}
	// check timeout
	cout << "estimate." << ((steady_clock::now() - startTime).count() / 1000) << endl;
	if (((steady_clock::now() - startTime).count() / 1000) > timeout)
	{
		cout << "Failed to write data: Timeout." << endl;
		return FUNCTION_STATUS_TIMEOUT;
	}
	cout << "Data written successfully." << endl;
	return FUNCTION_STATUS_OK;
}

/**
 * @brief Simulates reading data from an I2C device.
 *
 * This method simulates the process of reading data over the I2C bus from a device. It's designed
 * to mimic the behavior of an actual I2C read operation, including handling for uninitialized 
 * parameters and operation timeouts. For demonstration purposes, this simulation assigns a fixed 
 * string to the dataToRead buffer.
 * @param dataToRead Pointer to a buffer where the read data will be stored. 
 * @param length The number of bytes to read. Note that the simulation currently assigns a fixed
 * string, so 'length' doesn't affect the output in this implementation.
 * @param timeout The maximum duration (in milliseconds) the method will attempt the read before 
 * timing out. This simulation checks the timeout but does not implement a real delay.
 *
 * @return Returns FunctionStatus based on the enum defined to error handling
 */
FunctionStatus I2C_Simulator::i2cRead(char *dataToRead, size_t length, uint32_t timeout)
{
	auto startTime = steady_clock::now(); // Start time
	dataToRead = (char *)"Skytree";
	cout << "data read from i2c: " << dataToRead << endl;
	if (dataToRead == NULL)
	{
		cout << "Failed to write data: uninitialized Parameter" << endl;
		return FUNCTION_STATUS_ARGUMENT_ERROR;
	}

	cout << ((steady_clock::now() - startTime).count() / 1000) << endl;
	// check timeout
	if (((steady_clock::now() - startTime).count() / 1000) > timeout)
	{
		cout << "Failed to write data: Timeout." << endl;
		return FUNCTION_STATUS_TIMEOUT;
	}
	cout << "Data written successfully." << endl;
	return FUNCTION_STATUS_OK;
}
