/*

          LEGO EV3 and NXT motor hacked

      A Simple Interface for managing the encoder
      utilizing arduino's interrupts 

       pinout:
        green   - 5v
        red     - GND
        blue    - encoderin1
        yellow  - encoderin2
        black/white - motor terminals         
             

*/
#include "ev3lego.h"
#include "Arduino.h"

volatile long degrees;
static int encoderPin1;  // Static variables to hold encoder pin values
static int encoderPin2;

ev3lego::ev3lego(int encoder1, int encoder2) {
  _encoder1 = encoder1;
  _encoder2 = encoder2;
}

void countDegrees() {
  if(digitalRead(encoderPin1) == digitalRead(encoderPin2)) {
    degrees++;
  } else {
    degrees--;
  }
}

void ev3lego::begin() {
  Serial.begin(115200);
  Serial.println("\nenjoy using lego motor!");
  
  pinMode(_encoder1, INPUT);
  pinMode(_encoder2, INPUT);
  
  // Assign the static variables to the instance values
  encoderPin1 = _encoder1;
  encoderPin2 = _encoder2;
  
  degrees = 0;
  
  attachInterrupt(digitalPinToInterrupt(_encoder1), countDegrees, CHANGE);
}

void ev3lego::run() {
  static long deg = 0;
  if(deg != degrees){
    deg = degrees;
  }
}

long ev3lego::ang() {
  return degrees;
}
