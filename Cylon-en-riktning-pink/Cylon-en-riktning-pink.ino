#include "FastLED.h"

// Load with card: ArduinoUNO
// Programmer:     AVR ISP

// How many leds in your strip?
#define NUM_LEDS 50

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
	// FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
        FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);

}

void loop() { 
        
        int hue = 250;
        int sat = 180;
  
	// First slide the led in one direction
	int i = 0;
        while ( 1 ) {
                int led_0 = (i) % NUM_LEDS;
                int led_1 = (i+1) % NUM_LEDS;
                int led_2 = (i+2) % NUM_LEDS;
                int led_3 = (i+3) % NUM_LEDS;
                int led_4 = (i+4) % NUM_LEDS;
                int led_5 = (i+5) % NUM_LEDS;

/*
		leds[led_0] = CHSV( hue, 128, 25);
                leds[led_1] = CHSV( hue, 128, 50);
                leds[led_2] = CHSV( hue, 128, 100);
                leds[led_3] = CHSV( hue, 128, 150);
                leds[led_4] = CHSV( hue, 128, 200);
                leds[led_5] = CHSV( hue, 128, 225);
*/
                leds[led_0] = CHSV( hue, sat, 25);
                leds[led_1] = CHSV( hue, sat, 50);
                leds[led_2] = CHSV( hue, sat, 100);
                leds[led_3] = CHSV( hue, sat, 150);
                leds[led_4] = CHSV( hue, sat, 200);
                leds[led_5] = CHSV( hue, sat, 225);

                FastLED.show();
                leds[led_0]   = CRGB::Black;
                leds[led_1]   = CRGB::Black;
                leds[led_2]   = CRGB::Black;
                leds[led_3]   = CRGB::Black;
                leds[led_4]   = CRGB::Black;
                leds[led_5]   = CRGB::Black;
                i++;
                delay(30);
                }
	}

