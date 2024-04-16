#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <Arduino.h>

namespace Device
{
  class Keyboard
  {
    private:
    static const char NUM_OF_BTNS = 5;
    // 44 - POWER_KEYBOARD
    const int button_pins[NUM_OF_BTNS] = {52, 50, 48, 42, 46};
    public:
      Keyboard();
      ~Keyboard();
      void initialize();
      int readInput();
  };
}
#endif
