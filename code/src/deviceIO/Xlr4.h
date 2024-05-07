#ifndef _XLR4_H_
#define _XLR4_H_

#include <Arduino.h>

#include "IConnector.h"

namespace DeviceIO
{
  class Xlr4 : public IConnector
  {
    public:
      Xlr4();
      Xlr4(Mode mode, IConnector* output);
      ~Xlr4();
  };
}
#endif
