#ifndef _BOSH_H_
#define _BOSH_H_

#include "IConnector.h"

namespace DeviceIO
{
  class Bosh : public IConnector
  {
    public:
      Bosh();
      Bosh(Mode mode, IConnector* output);
      ~Bosh();
  };
}
#endif
