# GPS Speedometer with a TM1637 Display
This is a simple speedometer using a GT-U7 (NEO 6M clone) and a 1637 Display. 

## Install Instructions:
Install the following libraries:
* [Arduino-TM1637 from bremme](https://github.com/bremme/arduino-tm1637)
* [TinyGPS++ from mikalhart](https://github.com/mikalhard/TinyGPSPlus)
	* [Alternative site w/ documentation](http://arduiniana.org/libraries/tinygpsplus/)

(Both libraries are linked in the arduino file itself aswell.)

Afterwards, simply download or clone this repository, and load the file into your IDE. After wiring everything up according to the table below, simply flash the Arduino with the code.

## Pin Layout

Pin Label | Arduino Pin
----------|------------
 CLK (TM1637)| Digital 3
 DIO (TM1637)| Digital 4
 RX (GT-U7)| Digital 8
 TX (GT-U7)| Digital 10
 5V (Both)| 5V
 GND (Both)| GND (Common)

### Important Notes on the GT-U7
The GT-U7 is really weird. For starters, it uses 9600 baud, which is way faster than other GPS modules.  
Another thing I noticed is that the labels on my module for TX and Rx are reversed.  
  
The weirdest, and far more important, thing is that: **The RX and TX pins are 3.3v high**.  
This means that you should use a bidirectional level converter with your module for optimal lifespan.  
Here's the wiring for that:
Pin Label | Module Pin
----------|------------
 HV| 5V (Arduino)
 LV| 3.3V (Arduino)
 GND| GND (Common Ground; Arduino)
 H1| Digital 8 (Arduino)
 L1| TX (GT-U7*) 
 H2| Digital 10 (Arduino)
 L2| RX (GT-U7*)

\* = Remember that the GT-U7 pins are reversed from what they should actually be, since mine were reversed.

## Quick Troubleshooting Tips
1. If you're getting no Serial Monitor output for testing purposes, make sure you're on the right Baud rate.  
1. If you're getting INVALID in Serial Monitor output for both date and location when running the DeviceExample for TinyGPS, try just reversing the pins for the TX and RX pins in the code (you don't need to physically change them).  
1. If you're just getting INVALID for the location, but the date is right, remember that GPSes take a bit to warm up. Please wait warmly.  
	* Also, moving to a window helped speed up the wait for me, as the signal is stronger there.  

 