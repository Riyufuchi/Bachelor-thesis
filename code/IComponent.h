#ifndef _ICOMPONENT_H_
#define _ICOMPONENT_H_

#include <Arduino.h>

namespace Device
{
  class IComponent
  {
    public:
      IComponent() = default;
      virtual ~IComponent() = default;
      virtual bool initialize() = 0;
  };
}
#endif
