#include <FastLED.h>

#define LED_PIN   0 // PIN used on Arduino board
#define NUM_LEDS  3 // number of LEDs - constant

CRGB leds[NUM_LEDS];

int brightness = 5;   // brightness of the LEDs 0 (off) - 255 (max) 
int fadeAmount = 5;   // rate of which to fade the LEDs
int ledCount = NUM_LEDS; // total number of LEDs controlled

void setup() {
  // FastLED library call to program WS2812 LEDs
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i <= ledCount; i++) {
  leds[i] = CRGB(150, 255, 0); // set RGB (red, green, blue) color value (0-255)
  FastLED.setBrightness(brightness); // set brightness value
  FastLED.show();
  delay(20); // time in milliseconds
  }
  brightness = brightness + fadeAmount;
  if(brightness <= 5 || brightness >= 255){
    fadeAmount = -fadeAmount; 
  }
}
