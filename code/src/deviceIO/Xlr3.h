#ifndef _XLR3_H_
#define _XLR3_H_

#include "IConnector.h"

namespace DeviceIO
{
  class Xlr3 : public IConnector
  {
    public:
    Xlr3();
    ~Xlr3();
    bool testConnector() override;
  };
}
#endif
