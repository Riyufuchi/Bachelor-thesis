#ifndef _SPEAKER_H_
#define _SPEAKER_H_

#include <Arduino.h>

#include "IComponent.h"
#include "../utils/SOS.h"

namespace Device
{
  class Speaker : public IComponent
  {
    private:
      char plusPin = 36;
      const short SUCCESS_INTERVAL = 125;
      const short BOOT_INTERVAL = 100;
      SignalSOS sos;
    public:
      enum Sound
      {
        SUCCESS,
        ERROR,
        BOOT,
        SOS
      };
      Speaker();
      ~Speaker();
      bool initialize() override;
      void makeSound(Speaker::Sound sound);
      void beep(long interval);
  };
}
#endif
