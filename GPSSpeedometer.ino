
//PIN DEFINITIONS: use these so you don't need to write pin numbers. Makes life easier. Usage: digitalRead(PIN_A), where pin A is a definition for another pin
#define PIN_CLK 3
#define PIN_DIO 4
void setup() {
  startGPS()
  //this is used for setting stuff up
}

void loop() {
  // put your main code here, to run repeatedly:

}

void printMPH(mph){
  //Ben: this function should take in a decimal, and print that out to the display. it should only have 3 digits, formatted xx.x.
  //Should return nothing, hence: "void". still needs a return statement. 
}

float getMPH(){
  // Patrick: should use TinyGPS++ to obtain the MPH. Might not even need a seperate function but it's useful for oraganization.
}

void startGPS(){
  //Patrick: there's some init for this module but I'm not sure. Gotta do more research
}
