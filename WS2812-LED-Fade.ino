#include <FastLED.h>

// Author: Arthur (Damon) Mills
// Last Update: 1/18/2019
// Released for public use under GPL 2.0 License
// https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html

// Description: Causes WS2812 LEDs to gradually pulse in a pre-defined color
// Requires the FastLED library (Sketch -> Include Library -> Manage Libraries)
// Change number of LEDs with the NUM_LEDS variable
// Change the Ardunio PIN to control the LEDs with the LED_PIN variable
// Color is set using CRGB(Red, Green, Blue) command in main program

#define LED_PIN   0 // PIN used on Arduino board
#define NUM_LEDS  3 // number of LEDs - constant

CRGB leds[NUM_LEDS];

// initial values for brightness, fade increment/decrement rate, and nuymber of LEDs

int brightness = 5;   // initial brightness value of the LEDs 0 (off) - 255 (max) 
int fadeAmount = 5;   // rate of which to fade the LEDs
int ledCount = NUM_LEDS; // total number of LEDs controlled

// initial RGB values for LEDs

int redValue = 150;   // red value for LEDs (CRGB)
int greenValue = 255; // green value for LEDs (CRGB)
int blueValue = 0;    // blue value for LEDs (CRGB)

// defined values for fade speed, minimum and maximum brightness of LEDs

int milliseconds = 20; // time delay in milliseconds
int minBright = 5;    // minimum brightness value defined (0 is programmable minimum)
int maxBright = 255;  // maximum brightness value defined (255 is programmable maximum)

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);  // FastLED library call to program WS2812 LEDs
}

void loop() {
  for (int i = 0; i <= ledCount; i++) {
  leds[i] = CRGB(redValue, greenValue, blueValue); // set LED RGB (red, green, blue) color value (0-255)
  FastLED.setBrightness(brightness); // set brightness value
  FastLED.show();
  delay(milliseconds); // time in milliseconds
  }
  brightness = brightness + fadeAmount;
  if(brightness <= minBright || brightness >= maxBright){
    fadeAmount = -fadeAmount; // invert fadeAmount to either negative or positive value
  }
}
