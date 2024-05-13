#ifndef _XLR4_H_
#define _XLR4_H_

#include <Arduino.h>

#include "Connector.h"

namespace DeviceIO
{
  class Xlr4 : public Connector
  {
    public:
      Xlr4();
      Xlr4(Mode mode, Connector* output);
      ~Xlr4();
  };
}
#endif
