// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
#include "FastLED.h"

#define DATA_PIN 6
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 256
#define BRIGHTNESS 50

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // initial delay of a few seconds is recommended
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

// switches on all LEDs. Each LED is shown in random color.
// numIterations: indicates how often LEDs are switched on in random colors
// delayTime: indicates for how long LEDs are switched on.
void showProgramRandom(int numIterations, long delayTime) {
  for (int iteration = 0; iteration < numIterations; ++iteration) {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CHSV(random8(), 255, 255); // hue, saturation, value
    }
    FastLED.show();
    delay(delayTime);
  }
}

// Shifts a single pixel from the start of strip to the end.
// crgb: color of shifted pixel
// delayTime: indicates how long the pixel is shown on each LED
void showProgramShiftSinglePixel(CRGB crgb, long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = crgb;
    FastLED.show();
    delay(delayTime);
    leds[i] = CRGB::Black;
  }
}

// Shifts multiple pixel from the start of strip to the end. The color of each pixel is randomized.
// delayTime: indicates how long the pixels are shown on each LED
void showProgramShiftMultiPixel(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    for (int j = i; j > 0; --j) {
      leds[j] = leds[j - 1];
    }
    CRGB newPixel = CHSV(random8(), 255, 255);
    leds[0] = newPixel;
    FastLED.show();
    delay(delayTime);
  }
}

void showSmile(long delayTime) {
  int b,c;
  for (int i = (NUM_LEDS / 2) + 3, j = (NUM_LEDS / 2) - 5 ; i < 168; i += 8, j -= 8) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[j + 1] = CRGB::Red;
    leds[i + 1] = CRGB::Red;
    FastLED.show();
    b = i;
    c = j;
  }
    b += 7;
    c -= 7;
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
