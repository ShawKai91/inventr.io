#include <Arduino.h>
#include <U8g2lib.h>
#include <TM1637Display.h>

const byte CLK = 5, DIO = 4, pinsLED[] = {8, 9, 10};

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
TM1637Display display(CLK, DIO);

                   //0b0GFEDCBA, 0b0GFEDCBA, 0b0GFEDCBA, 0b0GFEDCBA
const byte dOnE[] = {0b01011110, 0b00111111, 0b01010100, 0b01111001};

const int H = 63, W = 127,
pointX[] = {0, H, 0},
pointY[] = {0, 0, H};

void setup() {
  display.setBrightness(0x0f);
  display.clear();
  
  u8g2.begin();
  u8g2.clear();

  for (int i = 0; i < 3; i++) {
    pinMode(pinsLED[i], OUTPUT);
  }
}

void loop() {
  int X = pointX[0], Y = pointY[0];
  
  u8g2.firstPage();    //clear LCD and prepare for data
  for (int count=0; count < 2500; count++) {    
    do {
      int I = random(0, 3);
      
      X = .5 * (X + pointX[I]);
      Y = .5 * (Y + pointY[I]);
      
      drawByte(X, Y);
      display.showNumberDec(count);
      showPointLED(I);
      delay(100);
    } while( u8g2.nextPage() );  
  }
  clearLED();
  display.setSegments(dOnE);
  while(1);
}

void drawByte(int xpos, int ypos) {
  u8g2.setDrawColor(4);
  u8g2.drawPixel(xpos, ypos);
}
void showPointLED(int I) {
  clearLED();
  digitalWrite(pinsLED[I], HIGH);
}
void clearLED() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinsLED[i], LOW);
  }
}
