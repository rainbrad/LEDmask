// Raine Bradley
#include "smile/a_smiles.h"


void setup() {
  delay(3000); // initial delay
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness

}

void playDemo(long showTime, long cleanTime) {        //showTime: seconds each display will be shown (1000 = 1 second)        cleanTime: time between switching displays  smiles::smileSetup();
  showSmile_1(6,3,0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_2(6,3,0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_3(5, 0, 0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_4();
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_5full(1500,5);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_6(6, 3, 0);
  delay(showTime);
  showProgramCleanUp(cleanTime);

}

void movementDemo(long showTime, long cleanTime) {
  showSmile_1(6,3,0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_1(4,1,5);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_1(2,4,10);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile_1(10,3,0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
}

// main program
void loop() {
  //playDemo(5000, 300);
  //showProgramCleanUp(100);
  showSmile_3(5, 1, -3);
  delay(2500);
  showProgramCleanUp(100);
  showSmile_6(6,3,0);
  delay(2500);
  showProgramCleanUp(100);
  movementDemo(2500,300);
  showProgramCleanUp(100);
  
}
