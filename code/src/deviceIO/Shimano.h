#ifndef _SHIMANO_H_
#define _SHIMANO_H_

#include "IConnector.h"

namespace DeviceIO
{
  class Shimano : public IConnector
  {
    public:
    Shimano();
    Shimano(Mode mode, IConnector* output);
    ~Shimano();
  };
}
#endif
