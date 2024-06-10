#include "Arduino.h"
#include "Speaker.h"

namespace Device
{
  Speaker::Speaker() : sos(plusPin)
  {}
  Speaker::~Speaker()
  {}
  bool Speaker::initialize()
  {
    pinMode(plusPin, OUTPUT);
    return true;
  }
  void Speaker::beep(long interval)
  {
    digitalWrite(plusPin, HIGH);
    delay(interval);
    digitalWrite(plusPin, LOW);
  }

  void Speaker::makeSound(Speaker::Sound sound)
  {
    switch (sound)
    {
      case SOS: sos.sendSOS(); break;
      case SUCCESS: beep(DEFAULT_INTERVAL); break;
      case ERROR:
        beep(DEFAULT_INTERVAL);
        delay(100);
        beep(DEFAULT_INTERVAL);
        delay(100);
        beep(DEFAULT_INTERVAL);
      break;
      case BOOT: beep(BOOT_INTERVAL); break;
    }
  }

}
