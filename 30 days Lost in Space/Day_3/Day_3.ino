/*
  Lost in Space Day 3 - I'm worried about your battery levels - DIP switch
  
  modified 28 dec 2023
  by ShawKai
*/

#define Cabin_Lights_Pin 12
#define Cabin_Lights_Switch_Pin 2

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(Cabin_Lights_Pin, OUTPUT);
  pinMode(Cabin_Lights_Switch_Pin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(Cabin_Lights_Switch_Pin)== HIGH){
    digitalWrite(Cabin_Lights_Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else {
    digitalWrite(Cabin_Lights_Pin, LOW);    // turn the LED off by making the voltage LOW
  }
}
