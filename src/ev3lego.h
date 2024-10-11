#ifndef EV3LEGO_H
#define EV3LEGO_H
 class ev3lego {

  public:
   ev3lego(int encoder1, int encoder2, int in1, int in2, int ena, int wheel);
   void begin();   //must be called from setup()
   void run();   //must be called from loop()
   long ang();
   void godegrees(int angle);
   double PIDcalc(double inp, int sp, int kp, int ki, int kd);
   void motgo(int speed);
   double gomm(int distance);
 

  private:
   int _encoder1, _encoder2, _in1, _in2, _ena, _wheel;
   double _kp, _ki, _kd;
   bool integralflag = false;
 };
#endif 