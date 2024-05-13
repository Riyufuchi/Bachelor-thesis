#ifndef _RCA_H_
#define _RCA_H_

#include "Connector.h"

namespace DeviceIO
{
  class Rca : public Connector
  {
    public:
      Rca();
      Rca(Mode mode, Connector* otherOne);
      ~Rca();
  };
}
#endif
