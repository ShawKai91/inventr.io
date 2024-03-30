/*
    guessNum by:
    ShawKai   2024[30 jan, 10 feb, 09 mar, 12 mar, 30 mar]
*/
// setup "drivers" (libraries)
#include <Keypad.h>
#include <Key.h>
const byte ROWS = 4, COLS = 3,
rowPins[ROWS] = {10, 11, 12, 13}, //connect to the row pinouts of the keypad
colPins[COLS] = {6, 7, 8}; //connect to the column pinouts of the keypad
const char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'} // '0' = 48
};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#include <TM1637Display.h>
const byte tm1637_pins[] = {/*clock*/A4, /*DIO*/A5};
TM1637Display display(tm1637_pins[0], tm1637_pins[1]);
