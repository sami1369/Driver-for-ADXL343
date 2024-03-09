   
   #include "ADXL343Driver.h"

    ADXL343::ADXL343(I2C_Simulator *i2c_, uint8_t address_ )
    {
        i2c = i2c_;
        address = address_;
    }

    