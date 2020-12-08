#include <Arduino.h>
#include "FastLED.h"
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 1
#define NUM_LEDS 40


#define DELAY 100

#define BRIGHTNESS 0xFF
#define HUE 0
#define SPEED 0x04
#define RANGE 0xFF
#define WIDTH 0x04

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}
void loop()
{
  CRGB color = {0xFF, 0x77, 0x00};
  FastLED.showColor(color);
  delay(DELAY);
}
