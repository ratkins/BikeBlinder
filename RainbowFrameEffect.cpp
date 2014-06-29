#ifndef RainbowFrameEffect_h
#define RainbowFrameEffect_h

#include "FastLED.h"
#include "FrameEffect.cpp"

class RainbowFrameEffect : public FrameEffect {
  
  private:
    CHSV currentColour;
  
  public:
    RainbowFrameEffect(CRGB *leds, int numLeds, int ledsPerBar) : FrameEffect(leds, numLeds, ledsPerBar), currentColour(0, 255, 255) {}
    
    virtual void draw(int frameNumber) {
      currentColour.hue++;
      fill_solid(leds, numLeds, currentColour);
    }

};

#endif
