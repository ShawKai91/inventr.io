/*
  Lost in Space Day 2 - It's really dark in here - LED
  
  modified 27 dec 2023
  by ShawKai
*/

#define Cabin_Lights_Pin 12


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(Cabin_Lights_Pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(Cabin_Lights_Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(Cabin_Lights_Pin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for 1/10th a second
}
