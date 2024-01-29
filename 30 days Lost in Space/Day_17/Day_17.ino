#include <TM1637Display.h>

/* Day 17 - H jyfwapj tlzzhnl
    ShawKai 12 jan 2024

    A     SEG_A = 0b00000001
   F B    SEG_B = 0b00000010
    G
   E C
    D
*/

const byte CLK_Pin = 5, DIO_Pin = 6;

const unsigned int displayDelay = 2000;

TM1637Display landerDisplay = TM1637Display(CLK_Pin, DIO_Pin);

const unsigned int validationData[] = {
  'b', 27, "a", 0xad2c, 0b1000110100110100, "eg", 'M'-'6', 'd', "twenty-seven", 0547-6,
  354, 0x3, -27-63821, 'q', 582, 0b1100110100111010, 0432, 0xdf3, 42
};

void setup() {}

void loop() {
  landerDisplay.setBrightness(7);

  landerDisplay.clear();
  delay(displayDelay);

  landerDisplay.showNumberDec(validationData['N'/015]);
  delay(displayDelay);

  landerDisplay.showNumberDec(validationData['Q'/0b1001]);
  delay(displayDelay);

  landerDisplay.showNumberDec(validationData[060-'$']);
  delay(displayDelay);
}
