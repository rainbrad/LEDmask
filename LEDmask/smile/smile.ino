// Raine Bradley
#include "FastLED.h"

#define DATA_PIN 3
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

void showSmile_1() { // standard smile

  int b,c;    
  int length = 184; // Length of midsection of the smile (before it curves)
  for (int i = (NUM_LEDS / 2) + 3, j = (NUM_LEDS / 2) - 5 ; i < length; i += 8, j -= 8) {    // Draws smile from middle, i designates LEDs going up the strip (pos. direction)         i + 3: NUM_LEDS/2 is on the bottom of the strip, +3 moves to the middle
    leds[i] = CRGB::Red;                                                                  // j designates LEDs going down the strip (neg. direction)                                j - 5: ^^ -5 moves to the middle also
    leds[j] = CRGB::Red;
    leds[j + 1] = CRGB::Red;  // gives thickness of two LEDs
    leds[i + 1] = CRGB::Red;
    delay(50);
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
    delay(75);
    FastLED.show();
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    b += 5;
    c -= 5;
    delay(75);
    FastLED.show();
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    b += 12;
    c -= 12;
    delay(75);
    FastLED.show();
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[b + 2] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    leds[c - 1] = CRGB::Red;
    b += 4;
    c -= 4;    
    delay(75);
    FastLED.show();
    leds[b] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    leds[b - 1] = CRGB::Red;
    leds[c + 2] = CRGB::Red;

    FastLED.show();

}

void showSmile_2() { // standard frown

  int b,c;    
  int length = 184; // Length of midsection of the smile (before it curves)
  for (int i = (NUM_LEDS / 2) + 3, j = (NUM_LEDS / 2) - 5 ; i < length; i += 8, j -= 8) {    // Draws smile from middle, i designates LEDs going up the strip (pos. direction)         i + 3: NUM_LEDS/2 is on the bottom of the strip, +3 moves to the middle
    leds[i] = CRGB::Red;                                                                  // j designates LEDs going down the strip (neg. direction)                                j - 5: ^^ -5 moves to the middle also
    leds[j] = CRGB::Red;
    leds[j + 1] = CRGB::Red;  // gives thickness of two LEDs
    leds[i + 1] = CRGB::Red;
    delay(50);
    FastLED.show();
    b = i;
    c = j;
  }

  
    b += 9;
    c -= 9;                 // incrementing LEDs to create curve of the smile
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    delay(75);
    FastLED.show();
    b += 6;
    c -= 6;
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    delay(75);
    FastLED.show();
    
    b += 11;
    c -= 11;
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[c + 1] = CRGB::Red;

    delay(75);
    FastLED.show();
    
    b += 3;
    c -= 3;
    leds[b] = CRGB::Red;
    leds[c] = CRGB::Red;
    leds[b + 1] = CRGB::Red;
    leds[b + 2] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    leds[c - 1] = CRGB::Red;
    delay(75);
    FastLED.show();
    
    b += 15;
    c -= 15;    
    leds[b] = CRGB::Red;
    leds[c + 1] = CRGB::Red;
    leds[b - 1] = CRGB::Red;
    leds[c + 2] = CRGB::Red;

    FastLED.show();

}

void showSmile_3() {  // mouth open smile :D  Drawn from left and right side simultaniously 
  int length = 224; // Length of upper mouth
  for (int i = NUM_LEDS / 8 + 7, j = 1, k = -1; i < length; j++) {  //top of mouth
  leds[i] = CRGB::Red;
  leds[i+k] = CRGB::Red;        // Adds Mouth thickness
  if  (j % 2 != 0) {            // IF NEXT LED IS 1 AWAY FROM I
      i += 1;
    } else {
      i +=15;
    }
    k = k * (-1);
  }
  int i = NUM_LEDS / 8 + 6;
  leds[i] = CRGB::Red;
  leds[i-1] = CRGB::Red;
  leds[i+4] = CRGB::Red;
  leds[i+5] = CRGB::Red;
  leds[i+179] = CRGB::Red;
  leds[i+180] = CRGB::Red;
  leds[i+175] = CRGB::Red;
  leds[i+174] = CRGB::Red;
  i += 14;               //moving to next section of smile ( Curve of the mouth )
  leds[i] = CRGB::Red;
  leds[i-1] = CRGB::Red;
  leds[i+151] = CRGB::Red;
  leds[i+152] = CRGB::Red;
  i += 8;
  leds[i] = CRGB::Red;
  leds[i+1] = CRGB::Red;
  leds[i+135] = CRGB::Red;
  leds[i+134] = CRGB::Red;
  i += 6;
  leds[i] = CRGB::Red;
  leds[i-1] = CRGB::Red;
  leds[i+123] = CRGB::Red;
  leds[i+124] = CRGB::Red;
  i += 12;
  for ( int j = 1, k = 1; j <= 14; j++){     //drawing bottom of mouth
    leds[i] = CRGB::Red;
    leds[i+k] = CRGB::Red;
    if ( j % 2 != 0) {            // IF NEXT LED IS 1 AWAY FROM I
      i += 3;
    } else {
        i += 13;
      }
    k = k * (-1);
  }
  // Mouth Corners

  FastLED.show();
}

void playDemo(long showTime, long cleanTime){         //showTime: seconds each display will be shown (1000 = 1 second)        cleanTime: time between switching displays
  showSmile_1();
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_2();
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_3();
  delay(showTime);
  showProgramCleanUp(cleanTime);
}
// main program
void loop() {
  playDemo(10000, 3000);
  //showSmile_2();
}
