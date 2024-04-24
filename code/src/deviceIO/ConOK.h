#ifndef _CON_OK_H_
#define _CON_OK_H_

#include "IConnector.h"

namespace DeviceIO
{
  class ConOK : public IConnector
  {
    public:
    ConOK();
    ~ConOK();
    bool testConnector(char& errorCode) override;
  };
}
#endif
