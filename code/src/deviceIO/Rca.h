#ifndef _RCA_H_
#define _RCA_H_

#include "IConnector.h"

namespace DeviceIO
{
  class Rca : public IConnector
  {
    public:
      Rca();
      ~Rca();
  };
}
#endif
