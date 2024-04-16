#ifndef _CON_OK_H_
#define _CON_OK_H_

#include "IConnector.h"

namespace DeviceIO
{
  class ConOK : public IConnector
  {
    public:
    ConOK(const char* name);
    ~ConOK();
    void sendSignal() override;
    bool reciveSignal() override;
  };
}
#endif
