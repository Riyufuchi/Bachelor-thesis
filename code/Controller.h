#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <Arduino.h>

#include "Display.h"
#include "IConnector.h"
#include "TimeUtils.hpp"
#include "ConOK.h"

namespace Device
{
  class Controller
  {
    private:
      Display dp;
      DeviceIO::IConnector* testIO[3]; // We test 3 cabel types
      TimeUtils::Time tTime;
    public:
      Controller();
      ~Controller();
      void initilize();
      void run();
  };
}
#endif
