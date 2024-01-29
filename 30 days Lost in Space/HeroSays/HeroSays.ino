#include <Keypad.h>
 
int buzzer = 12;                // Where the buzzer signal (S) is wired
int led_red = A3;               // Where the red LED is wired
int led_green = A2;             // Where the green LED is wired
int led_blue = A1;              // Where the blue LED is wired
int led_yellow = A0;            // Where the yellow LED is wired
const byte ROWS = 4;
const byte COLS = 4;
const int winningAmount = 7;    // How many rounds of remembering - 1
long sequence[winningAmount];   // Array to hold sequence
int count = 0;                  // Sequence counter
long input = 5;                 // Button indicator
int wait = 500;                 // Variable delay as sequence gets longer
char customKey = 'X';           // Temp variable for keypad input
 
char buttons[ROWS][COLS] = {
  {'R', 'G', 'B', 'Y'},
  {'R', 'G', 'B', 'Y'},
  {'R', 'G', 'B', 'Y'},
  {'R', 'G', 'B', 'Y'}
};
 
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
 
Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS); 
 
/*
  playtone function taken from Oomlout sample
  takes a tone variable that is half the period of desired frequency
  and a duration in milliseconds
  */
  void playtone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone *2) {
      digitalWrite(buzzer, HIGH);
      delayMicroseconds(tone);
      digitalWrite(buzzer, LOW);
      delayMicroseconds(tone);
    }
}
 
 
/*
  functions to flash LEDs and play corresponding tones
  very simple - turn LED on, play tone for .5s, turn LED off
*/
void flash_red() {
  digitalWrite(led_red, HIGH);
  playtone(2273,wait);             // low A
  digitalWrite(led_red, LOW);
}
 
void flash_blue() {
  digitalWrite(led_blue, HIGH);
  playtone(1700,wait);             // D
  digitalWrite(led_blue, LOW);
}
 
void flash_yellow() {
  digitalWrite(led_yellow, HIGH);
  playtone(1275,wait);             // G
  digitalWrite(led_yellow, LOW);
}
 
void flash_green() {
  digitalWrite(led_green, HIGH);
  playtone(1136,wait);             // high A
  digitalWrite(led_green, LOW);
}
 
// a simple test function to flash all of the LEDs in turn
void runtest() {
  flash_red();
  flash_green();
  flash_yellow();
  flash_blue();  
}
 
/* a function to flash the LED corresponding to what is held
  in the sequence
*/
void squark(long led) {
  switch (led) {
      case 0:
        flash_red();
        break;
      case 1:
        flash_green();
        break;
      case 2:
        flash_yellow();
        break;
      case 3:
        flash_blue();
        break;
    }
    delay(50);
}
 
// function to congratulate winning sequence
void congratulate() {
  digitalWrite(led_red, HIGH);       // turn all LEDs on
  digitalWrite(led_green, HIGH);
  digitalWrite(led_yellow, HIGH);
  digitalWrite(led_blue, HIGH);
  playtone(1014,250);                // play a jingle
  delay(25);    
  playtone(1014,250);
  delay(25);    
  playtone(1014,250);
  delay(25);    
  playtone(956,500);
  delay(25);    
  playtone(1014,250);
  delay(25);
  playtone(956,500);
  delay(2000);  
  digitalWrite(led_red, LOW);        // turn all LEDs off
  digitalWrite(led_green, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_blue, LOW);
  resetCount();                      // reset sequence
}
 
// function to reset after winning or losing
void resetCount() {
  count = 0;
  wait = 500;
}
 
// function to build and play the sequence
void playSequence() {
  sequence[count] = random(4);       // add a new value to sequence
  for (int i = 0; i < count; i++) {  // loop for sequence length
    squark(sequence[i]);             // flash/beep
  }
  wait = 500 - (count * 15);         // vary delay
  count++;                           // increment sequence length
}
 
// function to read sequence from player
void readSequence() {
 for (int i=1; i < count; i++) {               // loop for sequence length
    while (input==5){           // wait until button pressed
      customKey = customKeypad.getKey();
      if (customKey == 'R') {   // Red button
        input = 0;
      }
      if (customKey == 'G') {   // Green button
        input = 1;
      }
      if (customKey == 'Y') {   // Yellow button
        input = 2;
      }
      if (customKey == 'B') {   // Blue button
        input = 3;
      }
    }
    if (sequence[i-1] == input) {              // was it the right button?
      squark(input);                           // flash/buzz
      if (i + 1 == winningAmount) {            // check for correct sequence of "winningAmount"
        congratulate();                        // congratulate the winner
      }
    }
      else {
        playtone(4545,1000);                   // low tone for fail
        squark(sequence[i-1]);                 // double flash for the right colour
        squark(sequence[i-1]);
        resetCount();                          // reset sequence
    }
  input = 5;                                   // reset input
  customKey = 'X';
  }
}  
 
// standard sketch setup function
void setup() {
  pinMode(led_red, OUTPUT);      // configure LEDs and buzzer on outputs
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  randomSeed(analogRead(5));     // random seed for sequence generation
  Serial.begin(9600);
  //runtest();
}
 
// standard sketch loop function
void loop() {
  playSequence();  // play the sequence
  readSequence();  // read the sequence
  delay(1000);     // wait a sec
}
