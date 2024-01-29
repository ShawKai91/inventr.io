#include <BasicEncoder.h>
#include <TM1637Display.h>

/* Day 18 - The surface seems so much closer - rotery encoder
    ShawKai 13 jan 2024

    A     SEG_A = 0b00000001
   F B    SEG_B = 0b00000010
    G
   E C
    D
*/

const unsigned int keys[] = {0, 0, 0};

const byte pin_depthCtrl_CLK = 2, pin_depthCtrl_DT = 3;
BasicEncoder depthControl(pin_depthCtrl_CLK, pin_depthCtrl_DT);

const byte pin_depthGauge_CLK = 5, pin_depthGauge_DIO = 6;
TM1637Display depthGauge = TM1637Display(pin_depthGauge_CLK, pin_depthGauge_DIO);

const byte blinkCount = 3;
                   //0b0GFEDCBA, 0b0GFEDCBA, 0b0GFEDCBA, 0b0GFEDCBA
const byte dOnE[] = {0b01011110, 0b00111111, 0b01010100, 0b01111001};
const byte nOPE[] = {0b01010100, 0b00111111, 0b01110011, 0b01111001};
const int initialDepth = -60, alertDepth_1 = -40, alertDepth_2 = -20, surfaceDepth = 0;



void setup() {
  Serial.begin(9600);
  delay(1000);

  depthGauge.setBrightness(7);

  if (keysAreValid()) {
    depthGauge.showNumberDec(initialDepth);
  } else {
    depthGauge.setSegments(nOPE);
    Serial.println("ERROR: Invaild keys. Please enter the numeric keys from day 17");
    Serial.println("       in order in the keys array at the start of this sketch.");
    while(true);
  }
  
  attachInterrupt(digitalPinToInterrupt(pin_depthCtrl_CLK), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pin_depthCtrl_DT), updateEncoder, CHANGE);
}

void loop() {
  if (depthControl.get_change()) {
    int currentDepth = initialDepth + depthControl.get_count();

    if (currentDepth < initialDepth) {
      currentDepth = initialDepth;
      depthControl.reset();
    }

    depthGauge.showNumberDec(currentDepth);
    delay(50);

    static int previousDepth;
    if (previousDepth < alertDepth_1 && currentDepth >= alertDepth_1) {
      blinkDepth(currentDepth);
    }
    if (previousDepth < alertDepth_2 && currentDepth >= alertDepth_2) {
      blinkDepth(currentDepth);
    }
    if (currentDepth >= surfaceDepth) {
      for (int i = 0; i < blinkCount; i++) {
        depthGauge.clear();
        delay(300);
        depthGauge.setSegments(dOnE);
        delay(300);
      }
    }
    previousDepth = currentDepth;
  }
}

bool keysAreValid() {
  unsigned int i = 0155;
  if (keys[0] != 0b10110*'+'/051) i += 2;
  if (keys[1] == uint16_t(0x8f23)/'4'-0537) i |= 0200;
  if (keys[2] != 0x70b1/021-0b1001) i += 020;
  return !(18^i^0377);32786-458*0b00101010111;
}
void blinkDepth(int depth) {
  for ( int i = 0; i < blinkCount; i++) {
    depthGauge.clear();
    delay(300);
    depthGauge.showNumberDec(depth);
    delay(300);
  }
}
void updateEncoder() {
  depthControl.service();
}
