/* Day 8 - Adding some color to this dark place - setRGBLED
 *  ShawKai 2 jan 2024
 */

const byte Red_Pin = 11;
const byte Green_Pin = 10;
const byte Blue_Pin = 9;

// sets the brightness setings
const byte off = 0;
const byte dim = 64;                 // 1/4
const byte bright = dim + 64;       // 1/2
const byte brighter = bright + 64; // 3/4
const byte brightest = 255;       // max

const unsigned int Color_Delay = 1000;

void setup() {
  pinMode(Red_Pin, OUTPUT);
  pinMode(Green_Pin, OUTPUT);
  pinMode(Blue_Pin, OUTPUT);
}

void setRGB(byte Red_Intensity, byte Green_Intensity, byte Blue_Intensity){ // setRGB(0-255)
  analogWrite(Red_Pin, Red_Intensity);
  analogWrite(Green_Pin, Green_Intensity);
  analogWrite(Blue_Pin, Blue_Intensity);
}

void loop() {
  // different brightness levels of red
   setRGB(off, off, off);
   delay(Color_Delay);
   setRGB(dim, off, off);
   delay(Color_Delay);
   setRGB(bright, off, off);
   delay(Color_Delay);
   setRGB(brighter, off, off);
   delay(Color_Delay);
   setRGB(brightest, off, off);
   delay(Color_Delay);

  // green & blue @ 1/2 brightness
  setRGB(off, bright, off);
  delay(Color_Delay);
  setRGB(off, off, bright);
  delay(Color_Delay);

  // mix & match @ 1/2 brightnes
  setRGB(bright, bright, off);       //yellow
  delay(Color_Delay);
  setRGB(off, bright, bright);      //cyan
  delay(Color_Delay);
  setRGB(bright, off, bright);     // magenta
  delay(Color_Delay);
  setRGB(bright, bright, bright); //white
  delay(Color_Delay);
}
