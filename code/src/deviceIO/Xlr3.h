#ifndef _XLR3_H_
#define _XLR3_H_

#include <Arduino.h>

#include "IConnector.h"

namespace DeviceIO
{
  class Xlr3 : public IConnector
  {
    public:
      Xlr3(IConnector* output);
      Xlr3(Mode mode, IConnector* output);
      ~Xlr3();
  };
}
#endif
