#ifndef CyclingPaletteFrameEffect_h
#define CyclingPaletteFrameEffect_h

#include "FastLED.h"
#include "FrameEffect.cpp"

class CyclingPaletteFrameEffect : public FrameEffect {
  
  private:
    uint8_t colourIndex;
    CRGBPalette16 palette;
  
  public:
    CyclingPaletteFrameEffect(CRGB *leds, int numLeds, int ledsPerBar, CRGBPalette16 palette) : FrameEffect(leds, numLeds, ledsPerBar), 
      palette(palette), 
      colourIndex(0) {}
    
    virtual void draw(int frameNumber) {
      for (int i = 0; i < 45; i++) {     
        setPixel(i, ColorFromPalette(palette, colourIndex));
      }
      colourIndex++;
    }

};

#endif
