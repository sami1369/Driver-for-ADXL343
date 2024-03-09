
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
    int16_t x1, y1, z1;

    I2C_Simulator *i2c_sim;
    i2c_sim = new I2C_Simulator();

    ADXL343 *adx;
    adx = new ADXL343(i2c_sim, ADXL343_Registers::DEVICE_ADDRESS);

    adx->initialize();
    adx->readAcceleration(x1, y1, z1);

    cout << "DATA_X : " << x1 << " DATA_Y : " << y1 << " DATA_Z : " << z1 <<endl;
}