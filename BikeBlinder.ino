#include <FastLED.h>
#include "FrameEffect.cpp"
#include "RainbowFrameEffect.cpp"
#include "RandomBlankFrameEffect.cpp"
#include "RandomColourFrameEffect.cpp"
#include "WaveFrameEffect.cpp"

const uint16_t NUM_LEDS = 180;
const uint8_t DATA_PIN = 9;

CRGB leds[NUM_LEDS];

uint8_t frameNumber = 0;

RainbowFrameEffect rainbow(leds, NUM_LEDS);

RandomColourFrameEffect randomColour0(leds, NUM_LEDS, 0);
RandomColourFrameEffect randomColour1(leds, NUM_LEDS, 1);
RandomColourFrameEffect randomColour2(leds, NUM_LEDS, 2);
RandomColourFrameEffect randomColour3(leds, NUM_LEDS, 3);

RandomBlankFrameEffect randomBlank0(leds, NUM_LEDS, 0);
RandomBlankFrameEffect randomBlank1(leds, NUM_LEDS, 1);
RandomBlankFrameEffect randomBlank2(leds, NUM_LEDS, 2);
RandomBlankFrameEffect randomBlank3(leds, NUM_LEDS, 3);

WaveFrameEffect wave(leds, NUM_LEDS);

FrameEffect *effects[] = {
//  &wave,
  &randomColour0,
  &randomColour1,
  &randomColour2,
  &randomColour3,  
//  &rainbow,
//  &randomBlank0,   
//  &randomBlank1,
//  &randomBlank2,
//  &randomBlank3,  

  NULL
};

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
//  Serial.begin(57600);
  LEDS.delay(2000);
}

void loop() {
  int effectIndex = 0;
  while (effects[effectIndex] != NULL) {
    effects[effectIndex++]->draw(frameNumber++);
  }
  LEDS.show();
  LEDS.delay(50);
  memset8(leds, 0, NUM_LEDS * sizeof(CRGB));
  
}

void chase(CRGB colour) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = colour;
    LEDS.show();
    leds[i] = CRGB::Black;
    LEDS.show();
  }  
}

void solid(CRGB colour) {
  LEDS.clear();
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = colour;
  }
  LEDS.show();
  LEDS.delay(10000);  
}

void oneliner() {
  fill_rainbow(FastLED.leds(), FastLED.size(), millis() / 10 );
  FastLED.show();
}


