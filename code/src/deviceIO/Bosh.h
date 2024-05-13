#ifndef _BOSH_H_
#define _BOSH_H_

#include "Connector.h"

namespace DeviceIO
{
  class Bosh : public Connector
  {
    public:
      Bosh();
      Bosh(Mode mode, Connector* output);
      ~Bosh();
  };
}
#endif
