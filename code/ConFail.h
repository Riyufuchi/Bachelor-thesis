#ifndef _CON_FAIL_H_
#define _CON_FAIL_H_

#include "IConnector.h"

namespace DeviceIO
{
  class ConFail : public IConnector
  {
    public:
    ConFail();
    ~ConFail();
    bool testConnector() override;
  };
}
#endif
