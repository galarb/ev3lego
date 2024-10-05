#ifndef EV3LEGO_H
#define EV3LEGO_H
 class ev3lego {

  public:
   ev3lego(int encoder1, int encoder2);
   void begin();   //must be called from setup()
   void run();   //must be called from loop()
   long ang();

  private:
   int _encoder1;
   int _encoder2;
 };
#endif 