#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <Arduino.h>
#include <string.h>

#include "Display.h"
#include "Keyboard.h"
#include "IConnector.h"
#include "TimeUtils.hpp"
#include "ConOK.h"

namespace Device
{
  class Controller
  {
    private:
      Display dp;
      Keyboard keyboard;
      const char* SELECTION_MENU = "Cable: ";
      const char* CONNECTOR = "Conn: ";
      static const char NUM_OF_CONNECTORS = 3;
      DeviceIO::IConnector* testIO[NUM_OF_CONNECTORS];
      TimeUtils::Time actualTime;
      char selectedItem;
      char lineBuffer[20];
      void moveMenu(char right);
      void updateMenu();
      void testConnector();
    public:
      Controller();
      ~Controller();
      void initilize();
      void run();
  };
}
#endif
