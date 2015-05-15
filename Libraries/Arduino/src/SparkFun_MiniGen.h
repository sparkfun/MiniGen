/****************************************************************
Core header file for MiniGen board support

This code is beerware; if you use it, please buy me (or any other
SparkFun employee) a cold beverage next time you run into one of
us at the local.

2 Jan 2014- Mike Hord, SparkFun Electronics

Code developed in Arduino 1.0.5, on an Arduino Pro Mini 5V.

**Updated to Arduino 1.6.4 5/2015**
****************************************************************/

#ifndef SparkFun_MiniGen_h
#define SparkFun_MiniGen_h

#include <Arduino.h>

class MiniGen
{
  private:
  uint16_t configReg;
  
  uint16_t _FSYNCPin;
  
  void configSPIPeripheral();
  void SPIWrite(uint16_t data);
  
  public:
  enum MODE {TRIANGLE, SINE, SQUARE, SQUARE_2};
  enum FREQREG {FREQ0, FREQ1};
  enum PHASEREG {PHASE0, PHASE1};
  enum FREQADJUSTMODE {FULL, COARSE, FINE};
  
  MiniGen();
  MiniGen(int16_t FSYNCPin);
  
  void reset();
  void setMode(MODE newMode);
  void selectFreqReg(FREQREG reg);
  void selectPhaseReg(PHASEREG reg);
  void setFreqAdjustMode(FREQADJUSTMODE newMode);
  void adjustPhaseShift(PHASEREG reg, uint16_t newPhase);
  void adjustFreq(FREQREG reg, FREQADJUSTMODE mode, uint32_t newFreq);
  void adjustFreq(FREQREG reg, FREQADJUSTMODE mode, uint16_t newFreq);
  void adjustFreq(FREQREG reg, uint32_t newFreq);
  void adjustFreq(FREQREG reg, uint16_t newFreq);
  uint32_t freqCalc(float desiredFrequency);
};

#endif