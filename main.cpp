#include <iostream>
#include <vector>
#include <string>
#include "i2cDriver.h"
#include <cstddef>
#include <cstring>
using namespace std;

int main()
{

    I2C_Simulator i2c_sim;
    // i2c_sim = new I2C_Simulator();
    const char *data = "hello";
    char readData[10];
    auto result = i2c_sim.i2cRead(readData, strlen(readData), 700);

    // auto result = i2c_sim.i2cWrite(data, strlen(data), 100);

    // if (result == FUNCTION_STATUS_OK)
    // {
    //     cout << "Data written successfully." << endl;
    // }
    // else if (result == FUNCTION_STATUS_TIMEOUT)
    // {
    //     cout << "Failed to write data: Timeout." << endl;
    // }
    // else
    // {
    //     cout << "Failed to write data: Unknown error." << endl;
    // }


}