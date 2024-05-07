#ifndef _XLR5_H_
#define _XLR5_H_

#include <Arduino.h>

#include "IConnector.h"

namespace DeviceIO
{
  class Xlr5 : public IConnector
  {
    public:
      Xlr5();
      Xlr5(Mode mode, IConnector* output);
      ~Xlr5();
  };
}
#endif
