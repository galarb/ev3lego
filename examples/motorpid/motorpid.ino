/***************************************
      pinout:
        green   - 5v
        red     - GND
        blue    - encoderin1
        yellow  - encoderin2
        black/white - motor terminals
***************************************/
#include "ev3lego.h"
ev3lego mymotor(3, 4, 6, 7, 5, 65); //first argument must be 2 or 3 (IRQ pin)
//ev3lego(encoder1, encoder2, in1, in2, ena, wheel size)


void setup() {
  mymotor.begin();

}

void loop() {
  mymotor.run();//must have it in the background to update motor position
  mymotor.godegrees(720);
  //Serial.println(mymotor.gomm(PI*65));
  
}
