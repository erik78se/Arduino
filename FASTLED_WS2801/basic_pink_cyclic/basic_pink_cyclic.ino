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

// Regulates the speed of the led "movement"
#define SPEED 30

// Declare the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() { 
	int i = 0;
  
  //pink => hue = 250, sat = 180
  int hue = 250;
  int sat = 180;
        
  while ( 1 ) {

    // Define 6 led indexes
    int led_0 = (i) % NUM_LEDS;
    int led_1 = (i+1) % NUM_LEDS;
    int led_2 = (i+2) % NUM_LEDS;
    int led_3 = (i+3) % NUM_LEDS;
    int led_4 = (i+4) % NUM_LEDS;
    int led_5 = (i+5) % NUM_LEDS;

    // Set their color values
    leds[led_0] = CHSV( hue, sat, 25);
    leds[led_1] = CHSV( hue, sat, 50);
    leds[led_2] = CHSV( hue, sat, 100);
    leds[led_3] = CHSV( hue, sat, 150);
    leds[led_4] = CHSV( hue, sat, 200);
    leds[led_5] = CHSV( hue, sat, 225);
                
    FastLED.show();

    //Switch them off
    leds[led_0]   = CRGB::Black;
    leds[led_1]   = CRGB::Black;
    leds[led_2]   = CRGB::Black;
    leds[led_3]   = CRGB::Black;
    leds[led_4]   = CRGB::Black;
    leds[led_5]   = CRGB::Black;

    // delaying regulates the speed of the movement.
    delay(SPEED);


    i++;

  }//while

}//loop

