
#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <cstring>

#include "i2cDriver.h"
#include "ADXL343Driver.h"
#include "utils.h"
using namespace std;

// void testMain();

int main()
{
    int16_t x1, y1, z1;

    I2C_Simulator *i2c_sim;
    i2c_sim = new I2C_Simulator();

    ADXL343 *adx;
    adx = new ADXL343(i2c_sim, ADXL343_Registers::DEVICE_ADDRESS);

    ADXL343Test *adxl343Test;
    adxl343Test = new ADXL343Test(i2c_sim, ADXL343_Registers::DEVICE_ADDRESS);
    
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));
    // adxl343Test->testInitialization();
    for (int i = 0; i < 10; i++)
        adxl343Test->testTimeoutHandling();
}