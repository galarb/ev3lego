/***************************************
      pinout:
        green   - 5v
        red     - GND
        blue    - encoderin1
        yellow  - encoderin2
        black/white - motor terminals
***************************************/
#include "ev3lego.h"
ev3lego mymotor(3, 4, 5, 6, 9); //first argument must be 2 or 3

void setup() {
  mymotor.begin();

}

void loop() {
  mymotor.run();//must have it in the background for accurate measurement
  mymotor.gorounds(30);
  
}
