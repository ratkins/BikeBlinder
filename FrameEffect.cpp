#ifndef FrameEffect_h
#define FrameEffect_h

#include "FastLED.h"

class FrameEffect {
  
  protected:
    CRGB *leds;
    int numLeds;
    
  public:
    FrameEffect(CRGB *leds, int numLeds) : leds(leds), numLeds(numLeds) {}
    
    virtual void draw(int frameNumber) = 0;
    
};

#endif
