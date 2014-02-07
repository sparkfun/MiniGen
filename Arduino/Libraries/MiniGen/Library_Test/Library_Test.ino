#include <SPI.h>
#include <MiniGen.h>

MiniGen gen;

void setup()
{
  gen.reset();
  delay(2000);
  gen.setMode(MiniGen::SQUARE);
  delay(3000);
  gen.setMode(MiniGen::SQUARE_2);
  delay(3000);
  gen.setMode(MiniGen::TRIANGLE);
  delay(3000);
  gen.setMode(MiniGen::SINE);
  gen.setFreqAdjustMode(MiniGen::FULL);
}

void loop()
{
  static float frequency = 10.0;
  unsigned long freqReg = gen.freqCalc(frequency);
  gen.adjustFreq(MiniGen::FREQ0, freqReg);
  delay(100);
  frequency += 10.0;
}
