#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <Arduino.h>
#include <string.h>

#include "Display.h"
#include "Keyboard.h"
#include "Speaker.h"
#include "IConnector.h"
#include "TimeUtils.hpp"
#include "ConOK.h"

namespace Device
{
  class Controller
  {
    private:
      // Components
      Display dp;
      Keyboard keyboard;
      Speaker speaker;
      // Test IO
      static const char NUM_OF_CONNECTORS = 3;
      DeviceIO::IConnector* testIO[NUM_OF_CONNECTORS];
      // Help attributes
      char selectedItem;
      char lineBuffer[20];
      const char* CONNECTOR = "Conn: ";
      TimeUtils::Time actualTime;
      // Methods
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
