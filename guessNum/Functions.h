/*
    guessNum by:
    ShawKai   2024[30 jan, 10 feb, 09 mar, 12 mar, 30 mar]
*/
int getInput() {
  char key = keypad.getKey();
  int inputValue = 0;

  while (key != '#') {
    key = keypad.getKey();

    if (key != 0) {
      if (key == '*') {
        inputValue = 0;
      } else if (key != '#') {
        inputValue = (inputValue * 10) + (key - '0');
      }
    }
  }
  
  if (inputValue > 9999 or inputValue < 0) {
    inputValue = -1;
  }
  
  return inputValue;
}

void feedbackLED(byte LED) {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
}
void feedback7seg(bool showLives) {
  if (showLives != true) {
    display.showNumberDec(beingGuessed);
  } else {
    display.showNumberDec(lives);
  }  
}
