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
  static uint8_t hue;
  for(int i = 0; i < NUM_LEDS/2; i++) {   
    // fade everything out
    leds.fadeToBlackBy(40);

    // let's set an led value
    leds[i] = CHSV(hue++,255,255);

    // now, let's first 20 leds to the top 20 leds, 
    leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
    FastLED.delay(33);
  }
}
