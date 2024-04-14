#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_


#include "Display.h"
#include "IConnector.h"
#include "TimeUtils.hpp"

namespace Device
{
  class Controller
  {
    private:
      Display dp;
      DeviceIO::IConnector* testIO[3];
      TimeUtils::Time tTime;
    public:
      Controller();
      ~Controller();
      void initilize();
      void run();
  };
}
#endif
