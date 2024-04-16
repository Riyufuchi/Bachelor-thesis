#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <Arduino.h>

namespace Device
{
  class Keyboard
  {
    private:
    static const char NUM_OF_BTNS = 5;
    // 52 - AUTO
    // 50 - MENU
    // 48 - LEFT
    // 46 - POWER_BTN 
    // 44 - POWER_KEYBOARD
    // 42 - RIGHT
    const int tlacitka[NUM_OF_BTNS] = {52, 50, 48, 42, 46};
    //int stisk;
    public:
      Keyboard();
      ~Keyboard();
      void initialize();
      int readInput();
  };
}
#endif
