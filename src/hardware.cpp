/****************************************************************
hardware.cpp

Hardware support file for the MiniGen. Change the functions in
this file to use the MiniGen with different hardware.

This code is beerware; if you use it, please buy me (or any other
SparkFun employee) a cold beverage next time you run into one of
us at the local.

2 Jan 2014- Mike Hord, SparkFun Electronics

Code developed in Arduino 1.0.5, on an Arduino Pro Mini 5V.

**Updated to Arduino 1.6.4 5/2015**

****************************************************************/

#include "SparkFun_MiniGen.h"
#include <SPI.h>

// configSPIPeripheral() is an abstraction of the SPI setup code. This
//  minimizes difficulty in porting to a new target: simply change this
//  code to fit the new target.
void MiniGen::configSPIPeripheral()
{
  SPI.setDataMode(SPI_MODE2);  // Clock idle high, data capture on falling edge
  pinMode(_FSYNCPin, OUTPUT);  // Make the FSYCPin an output; this is analogous
                               //  to chip select in most systems.
  pinMode(10, OUTPUT);
  digitalWrite(_FSYNCPin, HIGH);
  SPI.begin();
}

// SPIWrite is optimized for this part. All writes are 16-bits; some registers
//  require multiple writes to update all bits in the registers. The address of
//  the register to be written is embedded in the data; corresponding write
//  functions will properly prepare the data with that information.
void MiniGen::SPIWrite(uint16_t data)
{
  digitalWrite(_FSYNCPin, LOW);
  SPI.transfer((byte)(data>>8));
  SPI.transfer((byte)data);
  digitalWrite(_FSYNCPin, HIGH);
}

