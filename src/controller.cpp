#include <Arduino.h>
#include "FastLED.h"
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 1
#define NUM_LEDS 50

#define DELAY 16

#define BRIGHTNESS 128
#define HUE 0
#define SPEED 0x04
#define RANGE 0xFF
#define WIDTH 0x04

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}
void loop()
{
  CHSV hsv = {0xFF, 0xFF, 0xFF}; // red
  uint8_t timer = scale16by8(millis(), SPEED);
  // hsv.h += scale8(sin8(timer), 16);

  for (uint8_t i = 0; i < NUM_LEDS; i++)
  {
    hsv.h = scale8(sin8(i * WIDTH + timer), RANGE) + HUE;
    leds[i] = hsv;
  }

  FastLED.show();
  delay(DELAY);
}
