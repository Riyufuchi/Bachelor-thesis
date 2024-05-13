#ifndef _JACK_25_H_
#define _JACK_25_H_

#include "Connector.h"

namespace DeviceIO
{
  class Jack25 : public Connector
  {
    public:
    Jack25();
    Jack25(Mode mode, Connector* otherOne);
    ~Jack25();
  };
}
#endif
