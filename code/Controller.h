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
#include "ConFail.h"

#define _VERSRION "Tester v0.17"

namespace Device
{
  class Controller
  {
    private:
      // Components
      Display display;
      Keyboard keyboard;
      Speaker speaker;
      // Test IO
      static const char NUM_OF_CONNECTORS = 3;
      DeviceIO::IConnector* testIO[NUM_OF_CONNECTORS];
      // Help attributes
      char selectedItem;
      char lineBuffer[20];
      TimeUtils::Time actualTime;
      // Methods
      void moveMenu(char right);
      void updateMenu();
      void initDisplayText();
      void resetMainMenu();
      void testConnector();
      void printErrorMessage(const char* what, const char* message);
    public:
      Controller();
      ~Controller();
      void initilize();
      void run();
  };
}
#endif
