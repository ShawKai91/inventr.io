/* Day 11 - Starting your control panel - keypad
 *  ShawKai 5 jan 2024
 */
#include <Keypad.h>
#include <Key.h>

const byte ROWS = 4, COLS = 4;
const byte ROW_Pins[ROWS] = {5, 4, 3, 2}, COL_Pins[COLS] = {6, 7, 8, 9};

const char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad heroKeypad = Keypad(makeKeymap(buttons), ROW_Pins, COL_Pins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char pressedButton = heroKeypad.waitForKey();
  Serial.println(pressedButton);
}
