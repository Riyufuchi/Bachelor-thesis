#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <Arduino.h>
#include <string.h>

#include "src/components/Display.h"
#include "src/components/Keyboard.h"
#include "src/components/Speaker.h"
#include "src/utils/TimeUtils.hpp"

#include "src/deviceIO/IncludeAllIO.hpp"

#define _VERSRION "Tester v0.29"

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
      static const char NUM_OF_CONNECTORS = 5;
      static const char NUM_OF_OUTPUS = 5;
      DeviceIO::IConnector* testIO[NUM_OF_CONNECTORS];
      DeviceIO::IConnector* outputIO[NUM_OF_OUTPUS];
      // Help attributes
      TimeUtils timeUtils;
      bool printDebugChar;
      char code;
      char selectedItem;
      char lineBuffer[20];
      char errorPart1[20]; 
      char errorPart2[20];
      char errorBuffer[40];
      // Methods
      void moveMenu(char right);
      void updateMenu();
      void initDisplayText();
      void testConnector();
      void printErrorMessage(const char* what, const char* message);
      void splitMessage(const char* message, char* part1, char* part2, int maxLength);
    public:
      Controller();
      ~Controller();
      void initilize();
      void run();
  };
}
#endif
