/*
 * Raine Bradley
 * Emoji Mask
 * Last Modified: 4.27.21
 * This is the main program for the Emoji Mask. It includes FastLED and push button setup,the runProgram() that the device relies on, as well as a few demo modes to show designs and functionality.
 */

#include "smiles.h"

/*
 * buttonPin = what pin the tactile button is connected to on the Arduino. Must match to function.
 * buttonRead will indicate the signal the Arduino recieves from the button. If the button is not pressed it will be 1, pressed it will be 0.
 * faceNum = the current switch state of runProgram(). Each state will generate a different design. Starts at 0 so no face is show.
 */
int buttonPin = 2;
int buttonRead;
int faceNum = 0;


/*
 * Setup for the FastLEDs and tactile button. Designates LED type, the data pin the LEDs connect to (3), color order, number of LEDs, and brightness.
 * Also sets up the pin number of the button and sets the button as an input.
 * Serial.begin is required to initiate writing to console.
 */
void setup() {
  delay(3000); // initial delay
  Serial.begin(9600); // open the serial port at 9600 bps:
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness
  pinMode(buttonPin, INPUT_PULLUP);
}


/*
 * Main running program.
 * Operates via switch statements based on faceNum. When faceNum = 0 the LEDs will turn off. Each time the button is pressed faceNum increases by 1.
 * Each switch statement generates a predefined visual display up to case 9 at which point faceNum returns to 0 and the cycle can run again.
 */
void runProgram() {
  buttonRead = digitalRead(buttonPin);
  Serial.println(buttonRead);
  if (buttonRead == 0) {
    faceNum++;
    Serial.print("Showing Face: ");
    Serial.println(faceNum);
  }
  switch (faceNum) {
    case 0:
      showProgramCleanUp(300);
      break;
    case 1:
      showProgramCleanUp(300);
      while (buttonRead != 0) {
        showSmile(6, 3, 0);
        buttonRead = digitalRead(buttonPin);
        Serial.print("Button input = : ");
        Serial.println(buttonRead);
        Serial.print("Showing Face: ");
        Serial.println(faceNum);
      }
      break;
    case 2:
      showProgramCleanUp(300);
      while (buttonRead != 0) {
        showFrown(6, 3, 0);
        buttonRead = digitalRead(buttonPin);
        Serial.print("Button input = : ");
        Serial.println(buttonRead);
        Serial.print("Showing Face: ");
        Serial.println(faceNum);
      }
      break;
    case 3:
      showProgramCleanUp(300);
      while (buttonRead != 0) {
        showOpenSmile(5, 0, 0);
        buttonRead = digitalRead(buttonPin);
        Serial.print("Button input = : ");
        Serial.println(buttonRead);
        Serial.print("Showing Face: ");
        Serial.println(faceNum);
      }
      break;
    case 4:
      showProgramCleanUp(300);

      while (buttonRead != 0) {
        showHello();
        buttonRead = digitalRead(buttonPin);
        Serial.print("Button input = : ");
        Serial.println(buttonRead);
        Serial.print("Showing Face: ");
        Serial.println(faceNum);
      }
      break;
    case 5:
      showProgramCleanUp(300);
      while (buttonRead != 0) {
        showSquiggle(1000);
        buttonRead = digitalRead(buttonPin);
        Serial.print("Button input = : ");
        Serial.println(buttonRead);
        Serial.print("Showing Face: ");
        Serial.println(faceNum);
      }
      break;
    case 6:
      showProgramCleanUp(300);

      while (buttonRead != 0) {
        showDimpleSmile(6, 3, 0);
        buttonRead = digitalRead(buttonPin);
        Serial.print("Button input = : ");
        Serial.println(buttonRead);
        Serial.print("Showing Face: ");
        Serial.println(faceNum);
      }
      break;
    case 7:
      showProgramCleanUp(300);
      while (buttonRead != 0) {
        showRound(0);
        buttonRead = digitalRead(buttonPin);
        Serial.print("Button input = : ");
        Serial.println(buttonRead);
        Serial.print("Showing Face: ");
        Serial.println(faceNum);
      }
      break;
    case 8:
      showProgramCleanUp(300);

      while (buttonRead != 0) {
        showKiss(4);
        buttonRead = digitalRead(buttonPin);
        Serial.print("Button input = : ");
        Serial.println(buttonRead);
        Serial.print("Showing Face: ");
        Serial.println(faceNum);
      }
      break;
      case 9:
      faceNum = -1;
  }

}

/*
 * Demo mode for displaying each design without the use of the button.
 * long showTime = the seconds each design will be shown
 * long cleanTime = the time in between display (the screen will be black)
 * 1000 = 1 second
 */
void playDemo(long showTime, long cleanTime) {
  showSmile(6, 3, 0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showFrown(6, 3, 0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showOpenSmile(5, 0, 0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showHello();
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSquiggleDemo(500, 7);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showDimpleSmile(6, 3, 0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showRoundDemo(0, 7);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showKiss(5);
  delay(showTime);
  showProgramCleanUp(cleanTime);

}

/*
 * Demo mode to show the transpoistion and resizing funcitonality of the designs.
 * runs showSmile with various inputs for scaling as well as vertical and horizontal movements.
 * long showTime = the seconds each design will be shown
 * long cleanTime = the time in between display (the screen will be black)
 * 1000 = 1 second
 */
void movementDemo(long showTime, long cleanTime) {
  showSmile(6, 3, 0);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile(4, 1, 5);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile(2, 4, 10);
  delay(showTime);
  showProgramCleanUp(cleanTime);
  showSmile(10, 3, 0);
  delay(showTime);
  showProgramCleanUp(cleanTime);

}

// main program
void loop() {
  runProgram();
}
