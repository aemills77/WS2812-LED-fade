#include <FastLED.h>

// Written by Arthur (Damon) Mills
// Date: 1/16/2019
// Released for public use under GPL 2.0 License

// Description: Causes WS2812 LEDs to gradually fade in and out with pre-defined color
// Change number of LEDs with the NUM_LEDS variable
// Change Ardunio PIN to control the LEDs with the LED_PIN variable
// Color is set using CRGB(Red, Green, Blue) command in main program

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
