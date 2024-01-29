/*
 * Day 6 - Time to fix the Battery - photoResister
 * 
 * ShawKai 31 dec 2023
*/

const byte Photoresistor_Pin = A0;

const unsigned int Battery_Capacity = 50000;

void setup() {
  pinMode(Photoresistor_Pin, INPUT);

  Serial.begin(9600);
}

unsigned int Battery_Level = 0;

void printBatteryChargeLevel(){
    if (Battery_Level < Battery_Capacity){
      Serial.print(((double)Battery_Level / (double)Battery_Capacity) * 100);
      Serial.println("%");
    } else {
      Serial.println("Fully Charged");
    }
  }

void loop() {
  if (Battery_Level < Battery_Capacity){
    Battery_Level += analogRead(Photoresistor_Pin);
    if (Battery_Level > Battery_Capacity){
      Battery_Level = Battery_Capacity;
    }
  }
  
  printBatteryChargeLevel();

  delay(100);
}
