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

void showSmile_1(int scale) { // standard smile

  int b, c;
  int length = 184 + (16 * scale); // Length of midsection of the smile (before it curves)
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

void showSmile_2(int scale ) { // standard frown

  int b, c;
  int length = 184 + (16 * scale); // Length of midsection of the smile (before it curves)
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
    leds[i + k] = CRGB::Red;      // Adds Mouth thickness
    if  (j % 2 != 0) {            // IF NEXT LED IS 1 AWAY FROM I (Due to zig zagging)
      i += 1;
    } else {
      i += 15;
    }
    k = k * (-1);

  }
  int i = NUM_LEDS / 8 + 6;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[i + 4] = CRGB::Red;
  leds[i + 5] = CRGB::Red;
  leds[i + 179] = CRGB::Red;
  leds[i + 180] = CRGB::Red;
  leds[i + 175] = CRGB::Red;
  leds[i + 174] = CRGB::Red;
  i += 14;               //moving to next section of smile ( Curve of the mouth )
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[i + 151] = CRGB::Red;
  leds[i + 152] = CRGB::Red;
  i += 8;
  leds[i] = CRGB::Red;
  leds[i + 1] = CRGB::Red;
  leds[i + 135] = CRGB::Red;
  leds[i + 134] = CRGB::Red;
  i += 6;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[i + 123] = CRGB::Red;
  leds[i + 124] = CRGB::Red;
  i += 12;
  for ( int j = 1, k = 1; j <= 14; j++) {    //drawing bottom of mouth
    leds[i] = CRGB::Red;
    leds[i + k] = CRGB::Red;
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

void showSmile_4() {  // HELLO
  int iSaver;
  for ( int i = NUM_LEDS / 8 * 7 + 15, j = 0; j < 16; i--, j ++ ) {                      //Drawing H
    leds[i] = CRGB::Red;
    iSaver = i;
  }
  int i = iSaver - 4;                          //Cross on H
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 8;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 5;
  iSaver = i;
  for (int i = iSaver, j = 0; j < 16; i--, j++) {             //End of H
    leds[i] = CRGB::Red;
    iSaver = i;
  }

  delay(250);
  FastLED.show();

  for (int i = iSaver - 9, j = 0; j < 16; i--, j ++) {                  //Drawing E
    leds[i] = CRGB::Red;
    iSaver = i;
  }
  i = iSaver - 1;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 3;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 3;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 2;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 3;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 3;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;

  delay(250);
  FastLED.show();

  iSaver = i - 10;
  for (int i = iSaver, j = 0; j < 16; i--, j++) {            // Drawing L #2
    leds[i] = CRGB::Red;
    iSaver = i;
  }
  i = iSaver - 1;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 15;
  leds[i] = CRGB::Red;
  leds[i + 1] = CRGB::Red;
  iSaver = i - 9;

  delay(250);
  FastLED.show();

  for (int i = iSaver, j = 0; j < 16; i--, j++) {            // Drawing L #2
    leds[i] = CRGB::Red;
    iSaver = i;
  }
  i = iSaver - 7;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 2;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;

  delay(250);
  FastLED.show();

  iSaver = i - 16;
  for (int i = iSaver, j = 0; j < 16; i--, j++) {           // Drawing O
    leds[i] = CRGB::Red;
    iSaver = i;
  }
  i = iSaver - 1;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 6;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 2;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  i -= 6;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  iSaver = i - 2;
  for (int i = iSaver, j = 0; j < 16; i--, j++) {           // Drawing O
    leds[i] = CRGB::Red;
    iSaver = i;
  }

  delay(250);
  FastLED.show();
}

void showSmile_5() {
  int iSaver, jSaver, i, j;
  for (int i = NUM_LEDS / 2 + 3, j = NUM_LEDS / 2 - 4, k = 9; k > 5; i += k, j -= k, k--) {
    leds[i] = CRGB::Red;
    leds[i - 1] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[j + 1] = CRGB::Red;
    iSaver = i;
    jSaver = j;
  }
  i = iSaver + 10;
  j = jSaver - 10;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 5;
  j -= 5;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 12;
  j -= 12;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 5;
  j -= 5;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 10;
  j -= 10;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  iSaver = i;
  jSaver = j;

  for (int i = iSaver, j = jSaver, k = 7; k < 11; i += k , j -= k, k ++) {
    leds[i] = CRGB::Red;
    leds[i - 1] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[j + 1] = CRGB::Red;
    iSaver = i;
    jSaver = j;
  }
  i = iSaver;
  j = jSaver;
  i = iSaver + 6;
  j = jSaver - 6;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 9;
  j -= 9;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 8;
  j -= 8;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;

  FastLED.show();

}

void showSmile_5invert() {
  int iSaver, jSaver;
  int i = NUM_LEDS / 2 + 6, j = NUM_LEDS / 2 - 7;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 5;
  j -= 5;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 10;
  j -= 10;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  iSaver = i;
  jSaver = j;
  for (int i = iSaver, j = jSaver, k = 7; k < 11; i += k, j -= k, k++) {
    leds[i] = CRGB::Red;
    leds[i - 1] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[j + 1] = CRGB::Red;
    iSaver = i;
    jSaver = j;
  }

  i = iSaver + 6;
  j = jSaver - 6;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 11;
  j -= 11;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 4;
  j -= 4;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 11;
  j -= 11;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  i += 6;
  j -= 6;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  iSaver = i;
  jSaver = j;
  for (int i = iSaver, j = jSaver, k = 9; k > 5; i += k, j -= k, k--) {
    leds[i] = CRGB::Red;
    leds[i - 1] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[j + 1] = CRGB::Red;
    iSaver = i;
    jSaver = j;
  }
  i = iSaver + 10;
  j = jSaver - 10;
  leds[i] = CRGB::Red;
  leds[i - 1] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[j + 1] = CRGB::Red;
  
  FastLED.show();

}

void showSmile_5full(int speed, int delayRatio, int loop) { // demo mode: (1500, 10, 5)
  for (int i = 0; i < loop; i++) {
    showSmile_5();
  delay(speed);
  showProgramCleanUp(0);
  delay(speed/delayRatio);
  showSmile_5invert();
  delay(speed);
  showProgramCleanUp(0);
  delay(speed/delayRatio);
  }
}

void playDemo(long showTime, long cleanTime) {        //showTime: seconds each display will be shown (1000 = 1 second)        cleanTime: time between switching displays
  showSmile_1(0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_2(0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_3();
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_4();
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_5full(1500, 10, 5);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  
}

// main program
void loop() {
  playDemo(5000, 300);
  showProgramCleanUp(100);
  
}
