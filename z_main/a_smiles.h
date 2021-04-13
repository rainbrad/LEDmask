/*
   Draw Smile functions
*/
#include "FastLED.h"
#include "transpose/b_transpose.h"

#define DATA_PIN 3
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 256
#define BRIGHTNESS 50

CRGB leds[NUM_LEDS];



// switches off all LEDs
void showProgramCleanUp(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(delayTime);
}


void showSmile_1(int scale, int vert, int hor) {    //scale <= 10    vert <= 4
  int i = NUM_LEDS / 2, j = i + 1;
  i = transpose(i, vert, 0);
  j = transpose(j, vert - 1, 0);
  for (int x = 0; x <= scale; x++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    FastLED.show();
    delay(75);
  }
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  FastLED.show();
  delay(75);
  for (int x = 0; x < 2; x++) {
    i = transpose(i, 1, -1);
    j = transpose(j, 1, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    FastLED.show();
    delay(75);
  }
}


void showSmile_2(int scale, int vert, int hor) {
  int i = NUM_LEDS / 2, j = i + 1;
  i = transpose(i, vert, 0);
  j = transpose(j, vert - 1, 0);
  for (int x = 0; x <= scale; x++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    FastLED.show();
    delay(75);
  }
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  FastLED.show();
  delay(75);
  for (int x = 0; x < 2; x++) {
    i = transpose(i, -1, -1);
    j = transpose(j, -1, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    FastLED.show();
    delay(75);
  }
}

void showSmile_3(int size, int vert, int hor) {
  int i = NUM_LEDS / 2, j = i + 1;
  i = transpose(i, 1 + vert, hor);
  j = transpose(j, vert, hor);
  for (int x = 0; x < size; x++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, -1, 0)] = CRGB::Red;
    leds[transpose(j, -1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    FastLED.show();
    delay(50);
  }
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, -1, 0)] = CRGB::Red;
  leds[transpose(j, -1, 0)] = CRGB::Red;
  FastLED.show();
  delay(50);
  for (int x = 0; x < size; x++) {
    i = transpose(i, 1, -1);
    j = transpose(j, 1, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, -1, 0)] = CRGB::Red;
    leds[transpose(j, -1, 0)] = CRGB::Red;
    FastLED.show();
    delay(50);
  }
  while (j > i) {
    i = transpose(i, 0, 1);
    j = transpose(j, 0, -1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, -1, 0)] = CRGB::Red;
    leds[transpose(j, -1, 0)] = CRGB::Red;
    FastLED.show();
    delay(50);
  }
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

void showSmile_5full(int speed, int loop) { // demo mode: (1500, 5)
  for (int i = 0; i < loop; i++) {
    showSmile_5();
    delay(speed);
    showProgramCleanUp(0);
    showSmile_5invert();
    delay(speed);
    showProgramCleanUp(0);
  }
}

void showSmile_6(int scale, int vert, int hor) {
  int i = NUM_LEDS / 2, j = i + 1;
  i = transpose(i, vert, 0);
  j = transpose(j, vert - 1, 0);
  for (int x = 0; x <= scale; x++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    FastLED.show();
    delay(75);
  }
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  FastLED.show();
  delay(75);
  int y = i;
  int z = j;
  for (int x = 0; x < 2; x++) {
    y = transpose(y, -1, -1);
    z = transpose(z, -1, 1);
    leds[y] = CRGB::Red;
    leds[z] = CRGB::Red;
    leds[transpose(y, 1, 0)] = CRGB::Red;
    leds[transpose(z, 1, 0)] = CRGB::Red;
    y = transpose(y, 0, -1);
    z = transpose(z, 0, 1);
    leds[y] = CRGB::Red;
    leds[z] = CRGB::Red;
    leds[transpose(y, 1, 0)] = CRGB::Red;
    leds[transpose(z, 1, 0)] = CRGB::Red;


    i = transpose(i, 1, -1);
    j = transpose(j, 1, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    FastLED.show();
    delay(75);
  }
}
