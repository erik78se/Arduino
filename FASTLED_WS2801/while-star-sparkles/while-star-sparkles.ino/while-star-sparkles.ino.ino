#include "FastLED.h"

/**   
 *    DESCRIPTION: This produce a cyclic pattern of 6 leds moving along the strip
 *    
 *    PROGRAMMING
 *     
 *    Load with card: ArduinoUNO
 *    Programmer:     AVR ISP
**/

// Board and PIN settings
#define NUM_LEDS 50
#define DATA_PIN 3
#define CLOCK_PIN 13


// Declare the array of leds
CRGBArray<NUM_LEDS> leds;


void setup() { 
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS); 
}



void loop(){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[random(0, NUM_LEDS)] = CRGB::White;
    // fade everything out
    leds.fadeToBlackBy(25);
    FastLED.delay(12);
  }
}

