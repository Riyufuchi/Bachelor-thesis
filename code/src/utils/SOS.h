#ifndef SOS_H
#define SOS_H

#include <Arduino.h>

class SignalSOS
{
  private:
    const char PIN;
    const short int SHORT_DELAY = 250;
    const short int LONG_DELAY = 500;
    void signal(long interval);
  public:
      SignalSOS(char pin);
      ~SignalSOS();
      //static void confirm();
      void sendSOS();
};
#endif
