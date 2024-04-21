#ifndef _SPEAKER_H_
#define _SPEAKER_H_

#include <Arduino.h>

#include "IComponent.h" 

namespace Device
{
  class Speaker : public IComponent
  {
    public:
      Speaker();
      ~Speaker();
      bool initialize() override;
  };
}
#endif
