// Raine Bradley
// Proof of concept demonstrating a sample smile design for the pandemic mask project
#include "FastLED.h"

#define DATA_PIN 6
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 256
#define BRIGHTNESS 50

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // initial delay
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness
}

// switches off all LEDs
void showProgramCleanUp(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(delayTime);
}


void showSmile(long delayTime) {      
  int b,c;    
  for (int i = (NUM_LEDS / 2) + 3, j = (NUM_LEDS / 2) - 5 ; i < 168; i += 8, j -= 8) {    // Draws smile from middle, i designates LEDs going up the strip (pos. direction)
    leds[i] = CRGB::Red;                                                                  // j designates LEDs going down the strip (neg. direction)
    leds[j] = CRGB::Red;
    leds[j + 1] = CRGB::Red;  // gives thickness of two LEDs
    leds[i + 1] = CRGB::Red;
    FastLED.show();
    b = i;
    c = j;
  }
    b += 7;
    c -= 7;                 // incrementing LEDs to create curve of the smile
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    b += 10;
    c -= 10;
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    b += 5;
    c -= 5;
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    b += 12;
    c -= 12;
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[b + 2] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    leds[c - 1] = CRGB::Red;
    b += 4;
    c -= 4;    
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    leds[b - 1] = CRGB::Red;
    leds[c + 2] = CRGB::Red;

    FastLED.show();


  delay(delayTime);

}

// main program
void loop() {
  showProgramCleanUp(2500); // clean up
  showSmile(15000);
}
