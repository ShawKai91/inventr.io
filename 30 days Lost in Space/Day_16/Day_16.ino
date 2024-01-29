#include <TM1637Display.h>

/* Day 16 - A fancy new display - lcd 7 segment
    ShawKai 11 jan 2024
*/

const byte CLK_Pin = 6, DIO_Pin = 5;

TM1637Display landerDisplay = TM1637Display(CLK_Pin, DIO_Pin);

/*
    A     SEG_A = 0b00000001
   F B    SEG_B = 0b00000010
    G
   E C
    D
*/
const byte allOn[] = {0b11111111, 0b11111111, 0b11111111, 0b11111111};
const byte done[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,
  SEG_C | SEG_E | SEG_G,
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G
};

void setup() {
  landerDisplay.setBrightness(7);
}

void loop() {
  landerDisplay.clear();
  delay(1000);

  landerDisplay.setSegments(allOn);
  delay(1000);

  landerDisplay.clear();
  delay(1000);

  /* .showNumberDecEx()
   *  00:00 (0b01000000)
   */
  for (int i = 0; i < 4; i++) { // blinking 12:00
    landerDisplay.showNumberDecEx(1200, 0b01000000);
    delay(500);
    landerDisplay.clear();
    delay(500);
  }

  for (int i = -100; i <= 100; i++) { // counter from -100 to 100
    landerDisplay.showNumberDec(i);
    delay(50);
  }
  delay(1000);

  landerDisplay.clear();
  delay(1000);

  landerDisplay.setSegments(done);
  delay(10000);
}
