/*
    guessNum by:
    ShawKai 30 jan 2024
    ShawKai 10 feb 2024
*/
#include <Keypad.h>
#include <Key.h>
const byte ROWS = 4, COLS = 3;
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 11, 12}; //connect to the column pinouts of the keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#include <TM1637Display.h>
const byte tm1637_pins[] = {/*clock*/4, /*DIO*/5};
TM1637Display display(tm1637_pins[0], tm1637_pins[1]);

const byte LED_pins[] = {/*to high*/A0, /*corect*/A1, /*to low*/A2};

void setup() {
  Serial.begin(9600);

  display.clear();
  display.setBrightness(7);

  for (int i = 0; i < 3; i++) {
    pinMode(LED_pins[i], OUTPUT);
  }
}

void loop() {

  char key = keypad.getKey();
  int value;
  //  value = key - '0'; // '0' = 48

  if (key == '3') {
    feedbackLED(LED_pins[0]);
  }
  if (key == '6') {
    feedbackLED(LED_pins[1]);
  }
  if (key == '9') {
    feedbackLED(LED_pins[2]);
  }
  if (key == '*') {
    value = getInput();
  }

  display.showNumberDec(value);
}

int getInput() {
  char key = keypad.getKey();
  int inputValue = 0;

  while (key != '#') {
    key = keypad.getKey();

    if (key != 0) {
      Serial.println(key);
      if (key == '*') {
        inputValue = 0;
      } else if (key != '#') {
        inputValue = (inputValue * 10) + (key - '0');
      }
    }
  }
  Serial.println(inputValue);
  return inputValue;
}
void feedbackLED(byte LED) {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
}
