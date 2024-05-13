#ifndef _XLR3_H_
#define _XLR3_H_

#include <Arduino.h>

#include "Connector.h"

namespace DeviceIO
{
  class Xlr3 : public Connector
  {
    public:
      Xlr3(Connector* output);
      Xlr3(Mode mode, Connector* output);
      ~Xlr3();
  };
}
#endif
