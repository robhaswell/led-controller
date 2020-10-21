#include <Arduino.h>
#include "FastLED.h"
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 1
#define NUM_LEDS 50

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}
void loop()
{
  leds[0] = CRGB::White;
  FastLED.show();
  delay(30);

  leds[0] = CRGB::Black;
  FastLED.show();
  delay(30);
}
