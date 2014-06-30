#ifndef RandomBlankFrameEffect_h
#define RandomBlankFrameEffect_h

#include "FastLED.h"
#include "FrameEffect.cpp"

class RandomBlankFrameEffect : public FrameEffect {

  private:
    uint8_t remainingBlankFrames;
    uint8_t barIndex;
  
  public:
    RandomBlankFrameEffect(CRGB *leds, int numLeds, int ledsPerBar, uint8_t barIndex) 
    : FrameEffect(leds, numLeds, ledsPerBar), 
    barIndex(barIndex), 
    remainingBlankFrames(0) {}

    virtual void draw(int frameNumber) {
      if (remainingBlankFrames > 0) {
        remainingBlankFrames--;
        memset8(leds + (barIndex * ledsPerBar), 0, ledsPerBar * sizeof(CRGB));
      } else if (random8() > 224) {
        remainingBlankFrames = random8(3, 10);
      }
    }
  
};

#endif
