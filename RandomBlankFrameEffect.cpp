#ifndef RandomBlankFrameEffect_h
#define RandomBlankFrameEffect_h

#include "FastLED.h"
#include "FrameEffect.cpp"

class RandomBlankFrameEffect : public FrameEffect {

  private:
    uint8_t remainingBlankFrames;
    uint8_t barIndex;
    static const uint8_t ledsPerBar = 45;
  
  public:
    RandomBlankFrameEffect(CRGB *leds, int numLeds, uint8_t barIndex) 
    : FrameEffect(leds, numLeds), 
    barIndex(barIndex), 
    remainingBlankFrames(0) {}

    virtual void draw(int frameNumber) {
      if (remainingBlankFrames > 0) {
        remainingBlankFrames--;
        memset8(leds + (barIndex * ledsPerBar), 0, ledsPerBar * sizeof(CRGB));
      } else if (random8() > 216) {
        remainingBlankFrames = random8(1, 5);
      }
    }
  
};

#endif
