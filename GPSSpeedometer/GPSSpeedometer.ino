//INCLUDE STATEMENTS: these are important because it's what allows us to use new libraries.
#include <SevenSegmentTM1637.h>
//from: https://github.com/bremme/arduino-tm1637
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
  //this function should take in an integer, and print that out to the display. it should only have 3 digits, formatted xx.x.
  //Should return nothing, hence: "void". still needs a return statement. 
  if(speed < 10){
    display.print("00");
    display.setCursor(1,2);
  } else if(speed < 100){
    display.print("0");
    display.setCursor(1,1); 
  }
  //length determination idea gotten from https://forum.arduino.cc/t/how-to-get-the-length-of-integer-numbers/43675/2
  display.print(speed);
  //uncomment the bottom two lines to have it display a zero after the tenth's mark.
  //display.setCursor(1,3);
  //display.print("0");
  Serial.println(speed);
  display.home();
  return;
}

int getMPH(){
  //This function can easily be replaced with just normal code. For some reason the double will output as xx.xx instead of xx.x for decimals, despite the fact that the hundreths is just zeros.
  double tempMPH = gps.speed.mph();
  tempMPH = round(tempMPH*10);
  //round function gotten from user rastapasta from: https://community.particle.io/t/changing-a-result-74-14505494505494-to-one-decimal-place/7337/2
  //round function not ended up being used, as decimals don't play well.
  int tempMPH2 = tempMPH;
  if(tempMPH2 > 999){
    tempMPH2 = 999;
  }
  return tempMPH2;
}

void startGPS(){
  //Patrick: there's some init for this module but I'm not sure. Gotta do more research
  //Upate: yeah no there was like no init haha. It's just starting software serial +  normal serial, which can probably be ommitted. Too lazy to see if that's the case or not.
  //NOTE ON THE SOFTWARESERIAL: this clone of the neo-6 uses 9600 rate rather than the very standard 4800 rate.
  Serial.begin(115200);
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
  //int mph = 0;
  while (ss.available() > 0){
    if (gps.encode(ss.read())){
      //!!!!!!!!!!!!!MPH EQUALS 987 IS JUST FOR TESTING PURPOSES. IT SHOULD NOT BE LIKE THAT IN THE FINAL. THIS IS JUST TO TEST THAT THINGS GET THROUGH.
      //mph = 987;
      //mph = getMPH();
      //printMPH(mph);
      printMPH(getMPH());
      //this can be condensed into printMPH(getMPH()); seperating it because why not lol (^^)
      //update from a day later, i like how it looks better now so i'm condensing it because why not lol (^^)
    }
  }
  
  

}
