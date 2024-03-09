// --------------------------------------------------------------------------------------------------------------------
// Include files
// --------------------------------------------------------------------------------------------------------------------
#include "i2cDriver.h"
#include <chrono>   //to generate time 
#include <iostream>
using namespace std;
using namespace std::chrono;



FunctionStatus I2C_Simulator::i2cWrite(const char* dataToWrite,  size_t length, uint32_t timeout)
{
    auto startTime = steady_clock::now();       // Start time
    if (dataToWrite == NULL)
    {
        return FUNCTION_STATUS_ARGUMENT_ERROR;
    }
    Registers[1] = *dataToWrite;
    // check timeout
    if (((steady_clock::now() - startTime).count() / 1000) > timeout)
    {
        cout << "Failed to write data: Timeout." << endl;
        return FUNCTION_STATUS_TIMEOUT;
    }
    cout << "Data written successfully." << endl;
    return FUNCTION_STATUS_OK;
}

FunctionStatus I2C_Simulator::i2cRead(char* dataToRead, size_t length, uint32_t timeout)
{
	auto startTime = steady_clock::now();       // Start time
    dataToRead =(char*)"Skytree" ;
    cout<< "data read from i2c: " << dataToRead << endl;
    if (dataToRead == NULL)
    {
        cout << "Failed to write data: uninitialized Parameter" << endl;
        return FUNCTION_STATUS_ARGUMENT_ERROR;
    }
    
    cout <<((steady_clock::now() - startTime).count() / 1000) << endl;
	//check timeout
    if (((steady_clock::now() - startTime).count() / 1000) > timeout ) 
    {
        cout << "Failed to write data: Timeout." << endl;
        return FUNCTION_STATUS_TIMEOUT;
    }
    cout << "Data written successfully." << endl;
    return FUNCTION_STATUS_OK;
}
