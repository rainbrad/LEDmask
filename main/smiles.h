/*
   Raine Bradley
   Emoji Mask
   Last Modified: 4.27.21
   smiles.h contains the intitialization of variables for the LED strip setup, clean up program to clear the screen, and 8 Emoji Mask visual designs.
*/
#include "FastLED.h"
#include "transpose.h"

/*
   DATA_PIN = The pin number on the Arduino that the LED strip is connected to.
   LED_TYPE = The LED strip model.
   COLOR_ORDER = Color set to be used with the LED lights.
   NUM_LEDS = Number of LED lights.
   BRIGHTNESS = Brightness of each light.
*/
#define DATA_PIN 3
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 256
#define BRIGHTNESS 50

// Array that represents each LED in the strip.
CRGB leds[NUM_LEDS];
// Delay time.
int dt = 75;



/*
   Sets all LEDs to black, turning them off
   long delayTime = time in seconds the screen will be black before moving to the next call.
*/
void showProgramCleanUp(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(delayTime);
}

/*
   Generates a simple smile similar to ":)"
   int scale = Length of the line before the smile curves up.
   int vert = How far from the bottom of the mask the design will generate.
   int hor = How far from the center of the mask the design will generate. Positive numbers will move it left, negeative will move it right.
   Using FastLED.show() and delays the generation can be made into an animation.
*/
void showSmile(int scale, int vert, int hor) {
  /*
     int i and j are used as points to individual LEDs. Utilizing the transpose functions they can be moved to desired locations and then set to be turned on.
  */
  int i = NUM_LEDS / 2, j = i + 1;
  i = transpose(i, vert, 0);
  j = transpose(j, vert - 1, 0);

  /*
     Length of the smile.
  */
  for (int x = 0; x <= scale; x++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    FastLED.show();
    delay(dt);
  }
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  FastLED.show();
  delay(dt);
  /*
     Upcurve of the smile.
  */
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
    delay(dt);
  }
}

/*
   Generates a simple frown similar to ":("
   int scale = Length of the line before the smile curves up.
   int vert = How far from the bottom of the mask the design will generate.
   int hor = How far from the center of the mask the design will generate. Positive numbers will move it left, negeative will move it right.
   Using FastLED.show() and delays the generation can be made into an animation.
*/
void showFrown(int scale, int vert, int hor) {
  /*
    int i and j are used as points to individual LEDs. Utilizing the transpose functions they can be moved to desired locations and then set to be turned on.
  */
  int i = NUM_LEDS / 2, j = i + 1;
  i = transpose(i, vert, 0);
  j = transpose(j, vert - 1, 0);
  /*
     Length of the frown
  */
  for (int x = 0; x <= scale; x++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    FastLED.show();
    delay(dt);
  }
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  FastLED.show();
  delay(dt);
  /*
     Downcurve of the frown.
  */
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
    delay(dt);
  }
}
/*
   Generates a simple open mouth smile similar to ":D"
   int scale = Length of the line before the smile curves up.
   int vert = How far from the bottom of the mask the design will generate.
   int hor = How far from the center of the mask the design will generate. Positive numbers will move it left, negeative will move it right.
   Using FastLED.show() and delays the generation can be made into an animation.
*/
void showOpenSmile(int size, int vert, int hor) {
  /*
    int i and j are used as points to individual LEDs. Utilizing the transpose functions they can be moved to desired locations and then set to be turned on.
  */
  int i = NUM_LEDS / 2, j = i + 1;
  i = transpose(i, 1 + vert, hor);
  j = transpose(j, vert, hor);
  /*
     Bottom line of the mouth.
  */
  for (int x = 0; x < size; x++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, -1, 0)] = CRGB::Red;
    leds[transpose(j, -1, 0)] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    FastLED.show();
    delay(dt);
  }
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, -1, 0)] = CRGB::Red;
  leds[transpose(j, -1, 0)] = CRGB::Red;
  FastLED.show();
  delay(dt);
  /*
     Upward curve of the smile/mouth.
  */
  for (int x = 0; x < size; x++) {
    i = transpose(i, 1, -1);
    j = transpose(j, 1, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, -1, 0)] = CRGB::Red;
    leds[transpose(j, -1, 0)] = CRGB::Red;
    FastLED.show();
    delay(dt);
  }
  /*
     Top line of the mouth.
  */
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

/*
   Generates the word "HELLO"
   Using FastLED.show() and delays the generation can be made into an animation.
*/
void showHello() {
  int i = NUM_LEDS / 8 * 7;
  int j = transpose(i, 0, 1);
  /*
     Drawing H
  */
  for (int x = 0; x < 8; x ++) {  //vertical line
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 1, 0);
    j = transpose(j, 1, 0);
  }
  i = transpose(i, -4, -1);        //cross line
  j = transpose(i, -1, 0);
  for (int x = 0; x < 2; x++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, -1);
  }
  i = transpose(i, -4, -1);
  j = transpose(i, 0, 1);
  for (int x = 0; x < 8; x ++) {   // vertical line
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 1, 0);
    j = transpose(j, 1, 0);
  }
  FastLED.show();
  delay(dt * 3);
  /*
     Drawing E
  */
  i = transpose(i, -7, -3);
  j = transpose(i, 0, 1);
  for (int x = 0; x < 8; x ++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 1, 0);
    j = transpose(j, 1, 0);
  }
  i = transpose(i, -9, -2);
  j = transpose(i, 0, 1);
  for (int x = 0; x < 3; x ++) {
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 1, 0);
    j = transpose(j, 1, 0);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 2, 0);
    j = transpose(j, 2, 0);
  }
  FastLED.show();
  delay(dt * 3);
  /*
     Drawing L
  */
  i = transpose(i, -1, -3);
  j = transpose(i, 0, 1);
  for (int x = 0; x < 8; x ++) {   // vertical line
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 1, 0);
    j = transpose(j, 1, 0);
  }
  i = transpose(i, -8, -2);
  j = transpose(i, 0, 1);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  FastLED.show();
  delay(dt * 3);
  /*
    Drawing L
  */
  i = transpose(i, 0, -3);
  j = transpose(i, 0, 1);
  for (int x = 0; x < 8; x ++) {   // vertical line
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 1, 0);
    j = transpose(j, 1, 0);
  }
  i = transpose(i, -8, -2);
  j = transpose(i, 0, 1);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  FastLED.show();
  delay(dt * 3);
  /*
     Drawing O
  */
  i = transpose(i, 0, -3);
  j = transpose(i, 0, 1);
  for (int x = 0; x < 8; x ++) {   // vertical line
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 1, 0);
    j = transpose(j, 1, 0);
  }
  i = transpose(i, -1, -2);
  j = transpose(i, 0, 1);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;

  i = transpose(i, -1, 0);
  j = transpose(j, -1, 0);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  i = transpose(i, -5, 0);
  j = transpose(j, -5, 0);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  i = transpose(i, -1, 0);
  j = transpose(j, -1, 0);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  i = transpose(i, 0, -2);
  j = transpose(i, 0, 1);
  for (int x = 0; x < 8; x ++) {   // vertical line
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 1, 0);
    j = transpose(j, 1, 0);
  }
  FastLED.show();
}
/*
   Generates the first half of an animated squiggly mouth. Can represent mouth movement of speaking or a conserned quiver of the mouth.
*/
void showSquiggle_1() {
  int i = NUM_LEDS / 2;
  i = transpose(i, 2, -1);
  int j = transpose(i, 0 , 1);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  for (int x = 0; x < 3; x ++) {
    i = transpose(i, 1, -2);
    j = transpose(j, 1, 2);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    leds[transpose(i, 1, 1)] = CRGB::Red;
    leds[transpose(j, 1, -1)] = CRGB::Red;
    leds[transpose(i, 0, 1)] = CRGB::Red;
    leds[transpose(j, 0, -1)] = CRGB::Red;
  }
  for (int x = 0; x < 3; x ++) {
    i = transpose(i, -1, -2);
    j = transpose(j, -1, 2);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    leds[transpose(i, 1, 1)] = CRGB::Red;
    leds[transpose(j, 1, -1)] = CRGB::Red;
    leds[transpose(i, 0, 1)] = CRGB::Red;
    leds[transpose(j, 0, -1)] = CRGB::Red;
  }
  i = transpose(i, 1, -2);
  j = transpose(j, 1, 2);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  leds[transpose(i, 1, 1)] = CRGB::Red;
  leds[transpose(j, 1, -1)] = CRGB::Red;
  leds[transpose(i, 0, 1)] = CRGB::Red;
  leds[transpose(j, 0, -1)] = CRGB::Red;
  FastLED.show();
}
/*
   Generates the second half of an animated squiggly mouth. Can represent mouth movement of speaking or a conserned quiver of the mouth.
*/
void showSquiggle_2() {
  int i = NUM_LEDS / 2;
  i = transpose(i, 5, -1);
  int j = transpose(i, 0 , 1);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  for (int x = 0; x < 4; x ++) {
    i = transpose(i, -1, -2);
    j = transpose(j, -1, 2);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    leds[transpose(i, 1, 1)] = CRGB::Red;
    leds[transpose(j, 1, -1)] = CRGB::Red;
    leds[transpose(i, 0, 1)] = CRGB::Red;
    leds[transpose(j, 0, -1)] = CRGB::Red;
  }
  for (int x = 0; x < 3; x ++) {
    i = transpose(i, 1, -2);
    j = transpose(j, 1, 2);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    leds[transpose(i, 1, 1)] = CRGB::Red;
    leds[transpose(j, 1, -1)] = CRGB::Red;
    leds[transpose(i, 0, 1)] = CRGB::Red;
    leds[transpose(j, 0, -1)] = CRGB::Red;
  }
  FastLED.show();
}
/*
   Generates the full set of an animated squiggly mouth. Can represent mouth movement of speaking or a conserned quiver of the mouth.
   int speed = the amount of time each half of the squiggle is on screen.
*/
void showSquiggle(int speed) { // demo mode: (1500, 5)
  showSquiggle_1();
  delay(speed);
  showProgramCleanUp(0);
  showSquiggle_2();
  delay(speed);
  showProgramCleanUp(0);
}
/*
   Generates the full of an animated squiggly mouth. Can represent mouth movement of speaking or a conserned quiver of the mouth.
   Demo version for use without tactile button.
   int speed = the amount of time each half of the squiggle is on screen.
   int loop = the number of time the animation will loop before halting. Only necessary for the demo variant of the display.
*/
void showSquiggleDemo(int speed, int loop) { // demo mode: (1500, 5)
  for (int i = 0; i < loop; i++) {
    showSquiggle_1();
    delay(speed);
    showProgramCleanUp(0);
    showSquiggle_2();
    delay(speed);
    showProgramCleanUp(0);
  }
}
/*
   Generates a combination of the smile and frown displays. Creates curves on the edge of the mouth to resemble dimples.
   int scale = Length of the line before the smile curves up.
   int vert = How far from the bottom of the mask the design will generate.
   int hor = How far from the center of the mask the design will generate. Positive numbers will move it left, negeative will move it right.
   Using FastLED.show() and delays the generation can be made into an animation.
*/
void showDimpleSmile(int scale, int vert, int hor) {
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
    delay(dt);
  }
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  FastLED.show();
  delay(dt);
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
    delay(dt);
  }
}
/*
   Generates a simple smile similar to ":o"
   Animates to make the mouth appear to grow or widen.
   int scale = Length of the line before the smile curves up.
   int vert = How far from the bottom of the mask the design will generate.
   int hor = How far from the center of the mask the design will generate. Positive numbers will move it left, negeative will move it right.
   Using FastLED.show() and delays the generation can be made into an animation.
*/
void showRound(int hor) {
  int i = transpose(NUM_LEDS / 2, 3, hor), j = transpose(i, 0, 1);

  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 1, 0)] = CRGB::Red;
  FastLED.show();
  delay(500);
  showProgramCleanUp(0);

  i = transpose(i, -1, 0);
  j = transpose(j, -1, 0);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  i = transpose(i, 0, -1);
  j = transpose(j, 0, 1);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  for (int x = 0; x < 3; x ++) {
    i = transpose(i, 1, 0);
    j = transpose(j, 1 , 0);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
  }
  i = transpose(i, 0, 1);
  j = transpose(j, 0, -1);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  FastLED.show();
  delay(500);
  showProgramCleanUp(0);
  i = transpose(i, 1, 0);
  j = transpose(j, 1, 0);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  for (int x = 0; x < 2; x++) {
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
  }
  for (int x = 0; x < 5; x++) {
    i = transpose(i, -1, 0);
    j = transpose(j, -1, 0);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
  }
  for (int x = 0; x < 2; x++) {
    i = transpose(i, 0, 1);
    j = transpose(j, 0, -1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
  }
  FastLED.show();
  delay(500);
  showProgramCleanUp(0);
}
/*
   Generates a simple smile similar to ":o" Demo variant
   Animates to make the mouth appear to grow or widen.
   int scale = Length of the line before the smile curves up.
   int hor = How far from the center of the mask the design will generate. Positive numbers will move it left, negeative will move it right.
   int loop = the number of times the animation will play before halting. (only necessary for demo).
   Using FastLED.show() and delays the generation can be made into an animation.
*/
void showRoundDemo(int hor, int loop) {
  for (int x = 0; x < loop; x ++) {
    int i = transpose(NUM_LEDS / 2, 3, hor), j = transpose(i, 0, 1);

    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    leds[transpose(i, 1, 0)] = CRGB::Red;
    leds[transpose(j, 1, 0)] = CRGB::Red;
    FastLED.show();
    delay(500);
    showProgramCleanUp(0);

    i = transpose(i, -1, 0);
    j = transpose(j, -1, 0);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    i = transpose(i, 0, -1);
    j = transpose(j, 0, 1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    for (int x = 0; x < 3; x ++) {
      i = transpose(i, 1, 0);
      j = transpose(j, 1 , 0);
      leds[i] = CRGB::Red;
      leds[j] = CRGB::Red;
    }
    i = transpose(i, 0, 1);
    j = transpose(j, 0, -1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    FastLED.show();
    delay(500);
    showProgramCleanUp(0);
    i = transpose(i, 1, 0);
    j = transpose(j, 1, 0);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    for (int x = 0; x < 2; x++) {
      i = transpose(i, 0, -1);
      j = transpose(j, 0, 1);
      leds[i] = CRGB::Red;
      leds[j] = CRGB::Red;
    }
    for (int x = 0; x < 5; x++) {
      i = transpose(i, -1, 0);
      j = transpose(j, -1, 0);
      leds[i] = CRGB::Red;
      leds[j] = CRGB::Red;
    }
    for (int x = 0; x < 2; x++) {
      i = transpose(i, 0, 1);
      j = transpose(j, 0, -1);
      leds[i] = CRGB::Red;
      leds[j] = CRGB::Red;
    }
    FastLED.show();
    delay(500);
    showProgramCleanUp(0);
  }
}
/*
   Generates an animation of a heart appearing. Using in the showKiss() method.
   int hor = How far from the center of the mask the design will generate. Positive numbers will move it left, negeative will move it right.
   Using FastLED.show() and delays the generation can be made into an animation.
*/
void drawHeart(int hor) {
  int i = transpose(NUM_LEDS / 2, 5, hor), j = transpose(i, 0, 1);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  FastLED.show();
  delay(50);
  i = transpose(i, 1, -1);
  j = transpose(j, 1, 1);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  FastLED.show();
  delay(50);
  leds[transpose(i, 0, -1)] = CRGB::Red;
  leds[transpose(j, 0, 1)] = CRGB::Red;
  FastLED.show();
  delay(50);
  i = transpose(i, -1, -2);
  j = transpose(j, -1, 2);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  FastLED.show();
  delay(50);
  i = transpose(i, -1, 0);
  j = transpose(j, -1, 0);
  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  FastLED.show();
  delay(50);
  for (int x = 0; x < 3; x++) {
    i = transpose(i, -1, 1);
    j = transpose(j, -1, -1);
    leds[i] = CRGB::Red;
    leds[j] = CRGB::Red;
    FastLED.show();
    delay(50);
  }
}
/*
   Generates an animation that resimbles the blowing a kiss emoji.
   Animates to make the heart/kiss appear next to the mouth
   int hor = How far from the center of the mask the design will generate. Positive numbers will move it left, negeative will move it right.
   Using FastLED.show() and delays the generation can be made into an animation.
*/
void showKiss(int hor) {
  int i = transpose(NUM_LEDS / 2, 3, hor), j = transpose(i, -1, -1);

  leds[i] = CRGB::Red;
  leds[j] = CRGB::Red;
  leds[transpose(i, 1, 0)] = CRGB::Red;
  leds[transpose(j, 3, 0)] = CRGB::Red;
  j = transpose(j, -1, -1);
  leds[j] = CRGB::Red;
  leds[transpose(j, 5, 0)] = CRGB::Red;
  j = transpose(j, -1, -1);
  leds[j] = CRGB::Red;
  leds[transpose(j, 7, 0)] = CRGB::Red;
  for (int x = 0; x < 4; x++) {
    j = transpose(j, 0, 1);
    leds[j] = CRGB::Red;
    leds[transpose(j, 7, 0)] = CRGB::Red;
  }
  FastLED.show();
  delay(500);

  drawHeart(hor * (-1));
}
