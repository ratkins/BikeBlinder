#ifndef FireFrameEffect_h
#define FireFrameEffect_h

#include "FastLED.h"
#include "FrameEffect.cpp"

#define COOLING 55
#define SPARKING 120

class FireFrameEffect : public FrameEffect {
  
  private:
      // Array of temperature readings at each simulation cell
      uint8_t heat[];
      CRGBPalette16 palette;
  
  public:
    FireFrameEffect(CRGB *leds, int numLeds, CRGBPalette16 palette) : FrameEffect(leds, numLeds), palette(palette) {

    }
    
    virtual void draw(int frameNumber) {
        random16_add_entropy(random());

      uint8_t heat[numLeds];
      
      // Step 1.  Cool down every cell a little
      for (int i = 0; i < numLeds; i++) {
        heat[i] = qsub8(heat[i], random8(0, ((COOLING * 10) / numLeds) + 2));
      }
  
      // Step 2.  Heat from each cell drifts 'up' and diffuses a little
      for (int k = numLeds - 3; k > 0; k--) {
        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
      }
    
      // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
     if (random8() < SPARKING ) {
       int y = random8(7);
       heat[y] = qadd8(heat[y], random8(160,255));
     }

     // Step 4.  Map from heat cells to LED colors
     for(int j = 0; j < numLeds; j++) {
      // Scale the heat value from 0-255 down to 0-240
      // for best results with color palettes.
       byte colorindex = scale8(heat[j], 240);
       leds[j] = ColorFromPalette(palette, colorindex);
     }
   }

};

#endif
