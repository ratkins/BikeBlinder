#ifndef FrameEffect_h
#define FrameEffect_h

#include "FastLED.h"

class FrameEffect {
  
  protected:
    CRGB *leds;
    int numLeds;
    int ledsPerBar;
    
  public:
    FrameEffect(CRGB *leds, int numLeds, int ledsPerBar) : leds(leds), numLeds(numLeds), ledsPerBar(ledsPerBar) {}
    
    virtual void draw(int frameNumber) = 0;
    
    void setPixel(int index, CRGB colour) {
      setPixel(0, index, colour);
      setPixel(1, index, colour);
      setPixel(2, index, colour);
      setPixel(3, index, colour);
    }
    
    void setPixel(int barIndex, int index, CRGB colour) {
      if (barIndex & 0x01) {
        leds[(barIndex * ledsPerBar) + ledsPerBar - index - 1] = colour;
      } else {
        leds[(barIndex * ledsPerBar) + index] = colour;
      }
    }
    
};

#endif
