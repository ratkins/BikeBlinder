#ifndef RandomColourFrameEffect_h
#define RandomColourFrameEffect_h

#include "FastLED.h"
#include "FrameEffect.cpp"

class RandomColourFrameEffect : public FrameEffect {

  private:
    uint8_t currentHue;
    uint8_t remainingFrames;
    uint8_t barIndex;
  
  public:
    RandomColourFrameEffect(CRGB *leds, int numLeds, int ledsPerBar, uint8_t barIndex) 
    : FrameEffect(leds, numLeds, ledsPerBar),
    currentHue(0), 
    barIndex(barIndex) {}

    virtual void draw(int frameNumber) {
      if (remainingFrames > 0) {
        remainingFrames--;
      } else {
        currentHue = random8();
        remainingFrames = random(8, 16);
      }
      fill_solid(leds + (barIndex * ledsPerBar), ledsPerBar, CHSV(currentHue, 255, 255));
    } 
  
};

#endif

