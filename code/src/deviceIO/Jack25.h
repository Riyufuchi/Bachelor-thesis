#ifndef _JACK_25_H_
#define _JACK_25_H_

#include "IConnector.h"

namespace DeviceIO
{
  class Jack25 : public IConnector
  {
    public:
    Jack25();
    Jack25(Mode mode, IConnector* otherOne);
    ~Jack25();
  };
}
#endif
