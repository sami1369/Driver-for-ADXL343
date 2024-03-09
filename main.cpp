
#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <cstring>


#include "i2cDriver.h"
#include "ADXL343Driver.h"
using namespace std;

int main()
{

    I2C_Simulator *i2c_sim;
    i2c_sim = new I2C_Simulator();

    ADXL343 *adx;
    adx = new ADXL343(i2c_sim, ADXL343_Registers::DEVICE_ADDRESS);





}