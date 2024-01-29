/*
  Lost in Space Day 4 - Cabin Lighting - LED & DIP switch
  
  modified 29 dec 2023
  by ShawKai
*/

// sets LED pins
const byte Cabin_Lights_Pin = 10;
const byte Storage_Lights_Pin = 11;
const byte Cockpit_Lights_Pin = 12;

// sets switch pins
const byte Cabin_Lights_Switch_Pin = 2;
const byte Storage_Lights_Switch_Pin = 3;
const byte Cockpit_Lights_Switch_Pin = 4;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(Cabin_Lights_Pin, OUTPUT);
  pinMode(Storage_Lights_Pin, OUTPUT);
  pinMode(Cockpit_Lights_Pin, OUTPUT);
  
  // sets switch pins as input
  pinMode(Cabin_Lights_Switch_Pin, INPUT);
  pinMode(Storage_Lights_Switch_Pin, INPUT);
  pinMode(Cockpit_Lights_Switch_Pin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  // pin switch 1
  if(digitalRead(Cabin_Lights_Switch_Pin)== HIGH){
    digitalWrite(Cabin_Lights_Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else {
    digitalWrite(Cabin_Lights_Pin, LOW);    // turn the LED off by making the voltage LOW
  }

  // switch 2
  if(digitalRead(Storage_Lights_Switch_Pin)== HIGH){
    digitalWrite(Storage_Lights_Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else {
    digitalWrite(Storage_Lights_Pin, LOW);    // turn the LED off by making the voltage LOW
  }

  // switch 3
  if(digitalRead(Cockpit_Lights_Switch_Pin)== HIGH){
    digitalWrite(Cockpit_Lights_Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else {
    digitalWrite(Cockpit_Lights_Pin, LOW);    // turn the LED off by making the voltage LOW
  }
}
