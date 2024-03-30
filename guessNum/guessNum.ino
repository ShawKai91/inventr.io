/*
    guessNum by:
    ShawKai   2024[30 jan, 10 feb, 09 mar, 12 mar, 30 mar]
*/
#include "Drivers.h"
// setup pins to be used
const byte LED_pins[] = {/*to High*/A0, /*corect*/A1, /*to Low*/A2};

//setup variables to be used
const byte toHigh = 0, correct = 1, toLow = 2;
int beingGuessed, toBeGuessed, lives = 5;

#include "Functions.h"
// setup default behavear for functions
void feedback7seg(bool showLives = 0);

void setup() {
  randomSeed(analogRead(0));
  toBeGuessed = random(1, 10000);
  beingGuessed = toBeGuessed;
  
  display.setBrightness(7);
  display.clear();

  for (int i = 0; i < 3; i++) {
    pinMode(LED_pins[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  while (lives > 0) {
    char key = keypad.getKey();

    switch (key) {
      case '3': feedbackLED(LED_pins[toHigh]);   break;
      case '6': feedbackLED(LED_pins[correct]); break;
      case '9': feedbackLED(LED_pins[toLow]);  break;
      case '*': beingGuessed = getInput();      break;
      default:  break;
    }

    feedback7seg();
  }
}
