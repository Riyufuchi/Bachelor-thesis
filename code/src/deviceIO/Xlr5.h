#ifndef _XLR5_H_
#define _XLR5_H_

#include <Arduino.h>

#include "Connector.h"

namespace DeviceIO
{
  class Xlr5 : public Connector
  {
    public:
      Xlr5();
      Xlr5(Mode mode, Connector* output);
      ~Xlr5();
  };
}
#endif
