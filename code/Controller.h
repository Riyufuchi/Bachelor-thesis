#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <Arduino.h>
#include <string.h>

#include "src/components/Display.h"
#include "src/components/Keyboard.h"
#include "src/components/Speaker.h"
#include "src/utils/TimeUtils.hpp"

#include "src/deviceIO/IncludeAllIO.hpp"

#define _VERSRION "Tester v0.32"

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
      static const char NUM_OF_INPUTS = 4;
      static const char NUM_OF_OUTPUS = 3;
      DeviceIO::IConnector* inputIO[NUM_OF_INPUTS];
      DeviceIO::IConnector* outputIO[NUM_OF_OUTPUS];
      // Help attributes
      TimeUtils timeUtils;
      bool printDebugChar;
      char code;
      char selectedItem;
      char rowBuffer[Display::DISPLAY_WIDTH];
      char errorPart2[Display::DISPLAY_WIDTH];
      char errorBuffer[40];
      // Methods
      void moveMenu(char right);
      void updateMenu();
      void initDisplayText();
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
