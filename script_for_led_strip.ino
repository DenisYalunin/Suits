#include <FastLED.h>

#define LED_PIN     6 
#define NUM_LEDS    60 

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  fadeToBlackBy(leds, NUM_LEDS, 10); 

  CRGB newColor = CHSV(random8(), 255, 255);

  fill_solid(leds, NUM_LEDS, newColor);

  FastLED.show();
  delay(500); 
}