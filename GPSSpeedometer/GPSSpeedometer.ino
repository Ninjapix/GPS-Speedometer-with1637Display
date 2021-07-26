//INCLUDE STATEMENTS: these are important because it's what allows us to use new libraries.
#include <SevenSegmentTM1637.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

//PIN DEFINITIONS: use these so you don't need to write pin numbers. Makes life easier. Usage: digitalRead(PIN_A), where pin A is a definition for another pin
//TM1637 Pins
#define PIN_CLK 3
#define PIN_DIO 4
//GT-U7 Pins (need to update these)
#define PIN_RX 8
#define PIN_TX 10

//OBJECT INIT: this is where we make objects for classes. This way we can refer back to them later and use their functions.
//Display objects
SevenSegmentTM1637 display(PIN_CLK, PIN_DIO);
//GPS objecs
TinyGPSPlus gps;
SoftwareSerial ss(PIN_RX, PIN_TX);
//USER-MADE FUNCTIONS: These are the ones we're coding :)
void printMPH(double speed){
  //Ben: this function should take in a decimal, and print that out to the display. it should only have 3 digits, formatted xx.x.
  //Should return nothing, hence: "void". still needs a return statement. 
}

double getMPH(){
  double tempMPH = gps.speed.mph();
  tempMPH = round(tempMPH*10)/10;
  return tempMPH;
}

void startGPS(){
  //Patrick: there's some init for this module but I'm not sure. Gotta do more research
  Serial.begin(9600);
  ss.begin(9600);
  return;
}
//ARDINO FUNCTIONS: The board uses these in particular to function. Essential to any and every project.
void setup() {
  startGPS();
  //this is used for setting stuff up
}

void loop() {
  // put your main code here, to run repeatedly:
  double mph = 0;
  while (ss.available() > 0){
    if (gps.encode(ss.read())){
      mph = 98.7;
      mph = getMPH();
      printMPH(mph);
    }
  }
  
  //round function gotten from user rastapasta from: https://community.particle.io/t/changing-a-result-74-14505494505494-to-one-decimal-place/7337
  

}
