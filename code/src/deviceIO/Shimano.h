#ifndef _SHIMANO_H_
#define _SHIMANO_H_

#include "IConnector.h"

namespace DeviceIO
{
  class Shimano : public IConnector
  {
    public:
    Shimano();
    ~Shimano();
    bool testConnector(char& errorCode) override;
  };
}
#endif
