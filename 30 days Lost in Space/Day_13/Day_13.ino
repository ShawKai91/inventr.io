/* Day 13 - HERO security 101
 *  ShawKai 7 jan 2024
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

const byte buzzer_Pin = 10;

const byte PINlength = 4;
char currentPIN[PINlength] = {'A', 'B', 'C', 'D'};

bool validatePIN() {
  Serial.println("Enter PIN to continue");

  for (int i = 0; i < PINlength; i++) {
    char btnChar = heroKeypad.waitForKey();
    tone(buzzer_Pin, 880, 100);

    if (currentPIN[i] != btnChar) {
      Serial.println();
      Serial.print("Wrong PIN digit: ");
      Serial.println(btnChar);
      return false;
    }
    Serial.print("*");
  }
  Serial.println();
  Serial.println("Device successfully unlocked");
  return true;
}

void setup() {
  pinMode(buzzer_Pin, OUTPUT);
  
  Serial.begin(9600);
  delay(200);
  Serial.println("Press * to enter new PIN or # to access the system.");
}

void loop() {
char  btnChar = heroKeypad.waitForKey();
//  Serial.println(btnChar);
  tone(buzzer_Pin, 880, 100);

  if (btnChar == '#') {
    bool accessGranted = validatePIN();
    if (accessGranted) {
      Serial.println("Welcome, authorized user. You may now begin using the system.");
    } else {
      Serial.println("Access Denied.");
      Serial.println("\nPress * to enter new PIN or # to access the system.");
    }
  }

  if (btnChar == '*') {
    bool accessGranted = validatePIN();
    if (accessGranted) {
      Serial.println("Welcome, authorized user. Please enter a new PIN: ");

      for (int i = 0; i < PINlength; i++) {
        btnChar = heroKeypad.waitForKey();
        tone(buzzer_Pin, 880, 100);

        currentPIN[i] = btnChar;
        Serial.print("*");
      }

      Serial.println();
      Serial.println("PIN successfully changed!");
    } else {
      Serial.println("Access denied, Cannot change PIN without the old or default.");
      Serial.println("\nPress * to enter new PIN or # to access the system.");
    }
  }
}
