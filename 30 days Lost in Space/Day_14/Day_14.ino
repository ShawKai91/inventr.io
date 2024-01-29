/* Day 14 - Advanced security panel
 *  ShawKai 8 jan 2024
 */
#include <Keypad.h>
#include <Key.h>

const byte PINlength = 4;
char currentPIN[PINlength] = {'A', 'B', 'C', 'D'};

const byte buzzer_Pin = 12;

const byte R_Pin = 11, G_Pin = 10, B_Pin = 9;

const byte ROWS = 4, COLS = 4;
const byte ROW_Pins[ROWS] = {5, 4, 3, 2}, COL_Pins[COLS] = {6, 7, 8, 13};
const char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
Keypad heroKeypad = Keypad(makeKeymap(buttons), ROW_Pins, COL_Pins, ROWS, COLS);

bool validatePIN() {
  bool PINcheck = true;
  
  Serial.println("Enter PIN to continue");

  for (int i = 0; i < PINlength; i++) {
    char btnChar = heroKeypad.waitForKey();

    if (currentPIN[i] != btnChar) {
      PINcheck = false;
    }
    if (i < (PINlength - 1)) {
      giveInputFeedback();
    }
    Serial.print("*");
  }
  if (PINcheck != true) {
    giveErrorFeedback();
     Serial.println();
     Serial.println("Wrong PIN entered");
     return false;
  }
  
  giveSuccessFeedback();
  Serial.println();
  Serial.println("Device successfully unlocked");
  return true;
}

void setRGB(byte redValue, byte greenValue, byte blueValue) {
  analogWrite(R_Pin, redValue);
  analogWrite(G_Pin, greenValue);
  analogWrite(B_Pin, blueValue);
}

void giveInputFeedback()   {
  setRGB(0, 0, 0);
  tone(buzzer_Pin, 880, 200);
  delay(200);
  setRGB(0, 0, 128);
}
void giveSuccessFeedback() {
  setRGB(0, 0, 0);
  tone(buzzer_Pin, 300, 200);
  delay(200);

  tone(buzzer_Pin, 500, 500);
  delay(500);
  setRGB(0, 128, 0);
}
void giveErrorFeedback()   {
  setRGB(0, 0, 0);
  tone(buzzer_Pin, 300, 200);
  delay(200);

  tone(buzzer_Pin, 200, 500);
  delay(500);
  setRGB(128, 0, 0);
}

void setup() {
  pinMode(buzzer_Pin, OUTPUT);
  pinMode(R_Pin, INPUT);
  pinMode(G_Pin, INPUT);
  pinMode(B_Pin, INPUT);

  setRGB(128, 0, 0);
  Serial.begin(9600);
  Serial.println("Press * to enter new PIN or # to access the system.");
}

void loop() {
char  btnChar = heroKeypad.waitForKey();

  if (btnChar == '#') {
    giveInputFeedback();
    bool accessGranted = validatePIN();
    if (accessGranted) {
      Serial.println("Welcome, authorized user. You may now begin using the system.");
    } else {
      Serial.println("Access Denied.");
      Serial.println("\nPress * to enter new PIN or # to access the system.");
    }
  }

  if (btnChar == '*') {
    giveInputFeedback();
    bool accessGranted = validatePIN();
    
    if (accessGranted) {
      setRGB(128, 80, 0);
      Serial.println("Welcome, authorized user. Please enter a new PIN: ");

      for (int i = 0; i < PINlength; i++) {
        currentPIN[i] = heroKeypad.waitForKey();
        
        if ( i < (PINlength - 1)) {
          giveInputFeedback();
          setRGB(128, 80, 0);
        }
        Serial.print("*");
      }

      Serial.println();
      Serial.println("PIN successfully changed!");
      giveSuccessFeedback();
    } else {
      Serial.println("Access denied, Cannot change PIN without the old or default.");
      Serial.println("\nPress * to enter new PIN or # to access the system.");
    }
  }
}
