#ifndef SimpleAdvancingPaletteFrameEffect_h
#define SimpleAdvancingPaletteFrameEffect_h

#include "FastLED.h"
#include "FrameEffect.cpp"

class SimpleAdvancingPaletteFrameEffect : public FrameEffect {
  
  private:
    uint8_t colourIndex;
    CRGBPalette16 palette;
  
  public:
    SimpleAdvancingPaletteFrameEffect(CRGB *leds, int numLeds, int ledsPerBar, CRGBPalette16 palette) : FrameEffect(leds, numLeds, ledsPerBar), 
      palette(palette), 
      colourIndex(0) {}
    
    virtual void draw(int frameNumber) {
        for (int i = 0; i < ledsPerBar; i++) {     
//            setPixel(i, ColorFromPalette(palette, colourIndex + i));
            setPixel(0, i, ColorFromPalette(palette, colourIndex + i));
            setPixel(1, i, ColorFromPalette(palette, colourIndex + i));            
        }
        colourIndex++;
    }

};

#endif
