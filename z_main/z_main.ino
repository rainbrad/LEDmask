// Raine Bradley
#include "a_smiles.h"
#include "b_transpose.h"

void setup() {
  delay(3000); // initial delay
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness

}

void playDemo(long showTime, long cleanTime) {        //showTime: seconds each display will be shown (1000 = 1 second)        cleanTime: time between switching displays  smiles::smileSetup();
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
  //playDemo(5000, 300);
  showProgramCleanUp(100);
  leds[transposeHor(10, -1)] = CRGB::Red;
  FastLED.show();
}
