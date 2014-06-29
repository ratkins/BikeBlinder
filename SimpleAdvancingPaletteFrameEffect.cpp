#ifndef SimpleAdvancingPaletteFrameEffect_h
#define SimpleAdvancingPaletteFrameEffect_h

#include "FastLED.h"
#include "FrameEffect.cpp"

class SimpleAdvancingPaletteFrameEffect : public FrameEffect {
  
  private:
    uint8_t colourIndex;
    CRGBPalette16 palette;
  
  public:
    SimpleAdvancingPaletteFrameEffect(CRGB *leds, int numLeds, CRGBPalette16 palette) : FrameEffect(leds, numLeds), palette(palette), colourIndex(0) {}
    
    virtual void draw(int frameNumber) {
      colourIndex++;
      for (int i = 0; i < 45; i++) {      
        leds[i] = ColorFromPalette(palette, colourIndex);
        colourIndex += 3;
      }
    }

};

#endif
