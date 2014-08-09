#include <FastLED.h>
#include "FrameEffect.cpp"
#include "RainbowFrameEffect.cpp"
#include "RandomBlankFrameEffect.cpp"
#include "RandomColourFrameEffect.cpp"
#include "FireFrameEffect.cpp"
#include "SimpleAdvancingPaletteFrameEffect.cpp"

const uint16_t NUM_LEDS = 180;
const uint16_t LEDS_PER_BAR = 45;
const uint8_t DATA_PIN = 9;
const uint8_t FRAMES_PER_SECOND = 60;

CRGB leds[NUM_LEDS];

uint8_t frameNumber = 0;

RainbowFrameEffect rainbow(leds, NUM_LEDS, LEDS_PER_BAR);

RandomColourFrameEffect randomColour0(leds, NUM_LEDS, LEDS_PER_BAR, 0);
RandomColourFrameEffect randomColour1(leds, NUM_LEDS, LEDS_PER_BAR, 1);
RandomColourFrameEffect randomColour2(leds, NUM_LEDS, LEDS_PER_BAR, 2);
RandomColourFrameEffect randomColour3(leds, NUM_LEDS, LEDS_PER_BAR, 3);

RandomBlankFrameEffect randomBlank0(leds, NUM_LEDS, LEDS_PER_BAR, 0);
RandomBlankFrameEffect randomBlank1(leds, NUM_LEDS, LEDS_PER_BAR, 1);
RandomBlankFrameEffect randomBlank2(leds, NUM_LEDS, LEDS_PER_BAR, 2);
RandomBlankFrameEffect randomBlank3(leds, NUM_LEDS, LEDS_PER_BAR, 3);

FireFrameEffect fire0(leds, NUM_LEDS, LEDS_PER_BAR, 0, HeatColors_p);
FireFrameEffect fire1(leds, NUM_LEDS, LEDS_PER_BAR, 1, HeatColors_p);
FireFrameEffect fire2(leds, NUM_LEDS, LEDS_PER_BAR, 2, HeatColors_p);
FireFrameEffect fire3(leds, NUM_LEDS, LEDS_PER_BAR, 3, HeatColors_p);

SimpleAdvancingPaletteFrameEffect blackAndWhiteAdvancingEffect(leds, NUM_LEDS, LEDS_PER_BAR, blackToWhitePalette());
SimpleAdvancingPaletteFrameEffect purpleAndGreenAdvancingEffect(leds, NUM_LEDS, LEDS_PER_BAR, purpleAndGreenPalette());
SimpleAdvancingPaletteFrameEffect rainbowAdvancingEffect(leds, NUM_LEDS, LEDS_PER_BAR, RainbowStripeColors_p);
SimpleAdvancingPaletteFrameEffect forestAdvancingEffect(leds, NUM_LEDS, LEDS_PER_BAR, ForestColors_p);
SimpleAdvancingPaletteFrameEffect oceanAdvancingEffect(leds, NUM_LEDS, LEDS_PER_BAR, OceanColors_p);

FrameEffect *fireGroup[] = {
  &fire0, &fire1, &fire2, &fire3, NULL
};

FrameEffect *rainbowGroup[] = {
  &rainbow,
  &randomBlank0, &randomBlank1, &randomBlank2, &randomBlank3,
  NULL
};

FrameEffect *randomColourGroup[] = {
  &randomColour0, &randomColour1, &randomColour2, &randomColour3,  
  &randomBlank0, &randomBlank1, &randomBlank2, &randomBlank3,
  NULL  
};

FrameEffect *blackAndWhiteGroup[] = {
  &blackAndWhiteAdvancingEffect,
  &randomBlank0, &randomBlank1, &randomBlank2, &randomBlank3,
  NULL  
};

FrameEffect *purpleAndGreenGroup[] = {
  &purpleAndGreenAdvancingEffect,
  &randomBlank0, &randomBlank1, &randomBlank2, &randomBlank3,
  NULL  
};

FrameEffect *rainbowAdvancingGroup[] = {
  &rainbowAdvancingEffect,
  &randomBlank0, &randomBlank1, &randomBlank2, &randomBlank3,
  NULL  
};

FrameEffect *forestAdvancingGroup[] = {
  &forestAdvancingEffect,
  &randomBlank0, &randomBlank1, &randomBlank2, &randomBlank3,
  NULL  
};

FrameEffect *oceanAdvancingGroup[] = {
  &oceanAdvancingEffect,
  &randomBlank0, &randomBlank1, &randomBlank2, &randomBlank3,
  NULL  
};

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  LEDS.delay(2000);
}

void loop() {
  int effectIndex = 0;
  while (effects[effectIndex] != NULL) {
    effects[effectIndex++]->draw(frameNumber++);
  }
  LEDS.show();
  LEDS.delay(1000 / FRAMES_PER_SECOND);
  memset8(leds, 0, NUM_LEDS * sizeof(CRGB));  
}

CRGBPalette16 purpleAndGreenPalette() {
  CRGB purple = CHSV( HUE_PURPLE, 255, 255);
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB black  = CRGB::Black;
  
  return CRGBPalette16( 
    green,  green,  black,  black,
    purple, purple, black,  black,
    green,  green,  black,  black,
    purple, purple, black,  black);
}

CRGBPalette16 blackToWhitePalette() {
  CRGB gray0 = CRGB(0, 0, 0);
  CRGB gray1 = CRGB(32, 32, 32);
  CRGB gray2 = CRGB(64, 64, 64);
  CRGB gray3 = CRGB(255, 255, 255);

  return CRGBPalette16(
    gray0, gray0, gray2, gray3,
    gray0, gray0, gray2, gray3,
    gray0, gray0, gray2, gray3,
    gray0, gray0, gray2, gray3    
  );
 }

