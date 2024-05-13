#ifndef _JACK_21_H_
#define _JACK_21_H_

#include "Connector.h"

namespace DeviceIO
{
  class Jack21 : public Connector
  {
    public:
      Jack21();
      Jack21(Mode mode, Connector* otherOne);
      ~Jack21();
  };
}
#endif
