// --------------------------------------------------------------------------------------------------------------------
// Include files
// --------------------------------------------------------------------------------------------------------------------
#include "i2cDriver.h"
#include <chrono>   //to generate time 
#include <iostream>
using namespace std;



FunctionStatus I2C_Simulator::i2cWrite(const char* dataToWrite,  size_t length, uint32_t timeout)
{
    using namespace std::chrono;
    auto startTime = steady_clock::now();       // Start time

    if (dataToWrite == NULL)
    {
        return FUNCTION_STATUS_ARGUMENT_ERROR;
    }
    //Registers[Address] = *dataToWrite;

    // check timeout
    if (duration_cast<milliseconds>(steady_clock::now() - startTime).count() > timeout)
    {
        cout << "Timeout occurred" <<endl;
        return FUNCTION_STATUS_TIMEOUT;
    }

    return FUNCTION_STATUS_OK;
}