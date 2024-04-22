#ifndef _SPEAKER_H_
#define _SPEAKER_H_

#include <Arduino.h>

#include "IComponent.h" 

namespace Device
{
  class Speaker : public IComponent
  {
    public:
      enum Sound
      {
        SUCCESS,
        ERROR,
        BOOT
      };
      Speaker();
      ~Speaker();
      bool initialize() override;
      void makeSound(Speaker::Sound sound);
  };
}
#endif
