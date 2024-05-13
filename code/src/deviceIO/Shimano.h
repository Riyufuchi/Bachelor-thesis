#ifndef _SHIMANO_H_
#define _SHIMANO_H_

#include "Connector.h"

namespace DeviceIO
{
  class Shimano : public Connector
  {
    public:
    Shimano();
    Shimano(Mode mode, Connector* output);
    ~Shimano();
  };
}
#endif
