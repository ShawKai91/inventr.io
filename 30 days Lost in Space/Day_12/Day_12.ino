/* Day 12 - Can you hear us - buzzzer
 *  ShawKai 6 jan 2024
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

const unsigned int tones[ROWS][COLS] = {
  {31,     93,  147, 208},
  {247,   311,  370, 440},
  {523,   587,  698, 880},
  {1397, 2637, 3729,   0}
};

const byte buzzer_Pin = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  char pressedButton = heroKeypad.waitForKey();
  
  unsigned int toneFrequency = 0;
  for (byte i = 0; i < ROWS; i++) {
    for (byte j = 0; j < COLS; j++) {
      if (pressedButton == buttons[i][j]) {
        toneFrequency = tones[i][j];
      }
    }
  }

  Serial.print("Key: ");
  Serial.print(pressedButton);
  Serial.print("  Freq: ");
  Serial.println(toneFrequency);

  if (toneFrequency > 0){
    tone(buzzer_Pin, toneFrequency);
  } else {
    Serial.println("stop tone");
    noTone(buzzer_Pin);
  }
}
