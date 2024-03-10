# Driver-for-ADXL343
Develop a driver for a 3-axis Accelerometer (ADXL343) using the I2C communication protocol. The driver should be able to initialize the device, read acceleration data along the X, Y, and Z axes, and configure the accelerometer's range and resolution. Include unit tests to validate the functionality of your driver.  

## Building and Running

### Dependencies
- C++ compiler with C++17 support

### Compiling
- Compile the driver and example application:
  
    ```sh  
    g++ -o program main.cpp i2cDriver.cpp ADXL343Driver.cpp -I. -std=c++17
### Running
- Run the application:  

  ```sh   
  .\program.exe

## Design Approach  
The driver design focuses on simplicity and ease of use, abstracting away the low-level I2C communication details from the user. 
### Key components include:
- ADXL343: The main class representing the accelerometer, providing methods for initialization, data reading, and configuration.
- I2C_Simulator: Simulates I2C communication, which can be replaced with actual hardware communication in a production environment.

## Error Handling  
The driver includes basic error handling, with functions returning a FunctionStatus enum indicating the outcome of operations. It allows users to implement robust applications capable of dealing with communication errors gracefully.  

## Assumptions and Limitations
The I2C_Simulator class is a placeholder and needs to be replaced with actual I2C communication logic for production use.
Error handling in the current implementation focuses on demonstrating the mechanism rather than covering all possible error conditions exhaustively.
The project assumes the ADXL343 device is connected and responds correctly to the I2C address 0x53.
For detailed information on using the ADXL343 accelerometer and I2C communication, refer to the respective datasheets and documentation.

## DATA_FORMAT register
DATA_FORMAT register is used to configure both the measurement range and the resolution.  
The bits in the DATA_FORMAT register that are of interest for setting the range are as follows:  
Bits D1 D0 (bits 1 and 0) determine the range (g-force) as follows:  
| DATA_FORMAT | D1 | Do |
| :---- | :----: | ----: |
| ±2g | 0 | 0 |
| ±4g | 0 | 1 |
| ±8g | 1 | 0 |
| ±16g | 1 | 1 |
