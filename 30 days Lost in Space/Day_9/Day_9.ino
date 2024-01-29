/* Day 9 - A better way to do things
 *  ShawKai 3 jan 2024
 */
const byte photoResistor_Pin = A0;

const byte Red_Pin = 11;
const byte Green_Pin = 10;
const byte Blue_Pin = 9;

const unsigned long batteryCapacity = 50000;

const unsigned int Color_Delay = 1000;

void setRGB(byte Red_Intensity, byte Green_Intensity, byte Blue_Intensity){ // setRGB(0-255, 0-255, 0-255)
  analogWrite(Red_Pin, Red_Intensity);
  analogWrite(Green_Pin, Green_Intensity);
  analogWrite(Blue_Pin, Blue_Intensity);
}

void setup() {
  pinMode(Red_Pin, OUTPUT);
  pinMode(Green_Pin, OUTPUT);
  pinMode(Blue_Pin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  static unsigned long batteryLevel = 0;
  batteryLevel += analogRead(photoResistor_Pin);
  if (batteryLevel > batteryCapacity){
    batteryLevel = batteryCapacity;
  }

  float percentage = ((float)batteryLevel / (float)batteryCapacity) * 100;
  if (percentage >= 50.0){
    setRGB(0, 128, 0);
  }else if (percentage >= 25.0 && percentage < 50.0){
    setRGB(128, 80, 0);
  }else {
    setRGB(0, 0, 0);
    delay(20);
    setRGB(128, 0, 0);
  }

  Serial.print(percentage);
  Serial.println("%");

  delay(100);
}
