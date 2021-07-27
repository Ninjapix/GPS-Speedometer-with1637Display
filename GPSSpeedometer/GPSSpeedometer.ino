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
void printMPH(int speed){
  //Ben: this function should take in a decimal, and print that out to the display. it should only have 3 digits, formatted xx.x.
  //Should return nothing, hence: "void". still needs a return statement. 
}

int getMPH(){
  //This function can easily be replaced with just normal code. For some reason the double will output as xx.xx instead of xx.x for decimals, despite the fact that the hundreths is just zeros.
  double tempMPH = gps.speed.mph();
  tempMPH = round(tempMPH*10);
  //round function gotten from user rastapasta from: https://community.particle.io/t/changing-a-result-74-14505494505494-to-one-decimal-place/7337/2
  //round function not ended up being used, as decimals don't play well.
  int tempMPH2 = tempMPH;
  if(tempMPH2 > 9999){
    tempMPH2 = 9999;
  }
  return tempMPH2;
}

void startGPS(){
  //Patrick: there's some init for this module but I'm not sure. Gotta do more research
  //Upate: yeah no there was like no init haha. It's just starting software serial +  normal serial, which can probably be ommitted. Too lazy to see if that's the case or not.
  Serial.begin(9600);
  ss.begin(9600);
  return;
}
void startDisplay(){
  //serial should be begun now but already doing it in gps init
  display.begin();
  display.setBacklight(100);
  display.setColonOn(true);
  return;
}
//ARDINO FUNCTIONS: The board uses these in particular to function. Essential to any and every project.
void setup() {
  startGPS();
  //this is used for setting stuff up, runs two lines of code so it's just for cleanliness
  startDisplay();
  //same as start GPS, just for cleanliness
}

void loop() {
  // put your main code here, to run repeatedly:
  int mph = 0;
  while (ss.available() > 0){
    if (gps.encode(ss.read())){
      //!!!!!!!!!!!!!MPH EQUALS 987 IS JUST FOR TESTING PURPOSES. IT SHOULD NOT BE LIKE THAT IN THE FINAL. THIS IS JUST TO TEST THAT THINGS GET THROUGH.
      mph = 987;
      mph = getMPH();
      printMPH(mph);
      //this can be condensed into printMPH(getMPH()); seperating it because why not lol (^^)
    }
  }
  
  

}
