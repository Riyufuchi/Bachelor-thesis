#include "Arduino.h"
#include "Controller.h"

using namespace Device;

Controller::Controller()
{  
  this->selectedItem = 0;
  this->menuY = 0;
  // Outputs
  this->outputIO[0] = new DeviceIO::Xlr3(DeviceIO::Mode::OUT, nullptr);
  this->outputIO[1] = new DeviceIO::Xlr4();
  this->outputIO[2] = new DeviceIO::Xlr5();
  // XLR-3
  this->menuIO[0][0] = new DeviceIO::Xlr3(DeviceIO::Mode::IN, outputIO[0]);
  this->menuIO[0][1] = new DeviceIO::Jack21(DeviceIO::Mode::IN, outputIO[0]);
  this->menuIO[0][2] = new DeviceIO::Jack25(DeviceIO::Mode::IN, outputIO[0]);
  this->menuIO[0][3] = new DeviceIO::Rca(DeviceIO::Mode::IN, outputIO[0]);
  // XLR-4
  this->menuIO[1][0] = new DeviceIO::Bosh(DeviceIO::Mode::IN, outputIO[1]);
  // XLR-5
  this->menuIO[2][0] = new DeviceIO::Shimano(DeviceIO::Mode::IN, outputIO[2]);
  // Lenghts
  this->menus[0] = 4;
  this->menus[1] = 1;
  this->menus[2] = 1;
}

Controller::~Controller()
{
  for (int x = 0; x < 3; x++)
    for (int i = 0; i < menus[x]; i++)
      delete menuIO[x][i];
  for (int i = 0; i < NUM_OF_OUTPUS; i++)
    delete outputIO[i];
}

void Controller::printErrorMessage(const char* what, const char* message)
{
  display.splitMessage(message, rowBuffer, errorPart2);
  display.print(2, display.centerText(what));
  display.print(3, display.centerText(rowBuffer));
  display.print(4, display.centerText(errorPart2));
}

void Controller::initDisplayText()
{
  display.print(1, display.centerText(_VERSRION));
  display.print(3, display.centerText("Test ready!"));
}

void Controller::initilize()
{
  bool checks[3];
  checks[2] = speaker.initialize();
  checks[0] = display.initialize();
  if (!checks[0])
  {
    if(!checks[2])
      exit(1);
    speaker.makeSound(Speaker::Sound::BOOT);
    speaker.makeSound(Speaker::Sound::SOS);
  }
  initDisplayText();
  checks[1] = keyboard.initialize();
  if(!checks[1]) // Also checks for broken buttons
  {
    printErrorMessage("Keyboard", "Failed init or stucked key");
    if(checks[2])
      speaker.makeSound(Speaker::Sound::SOS);
    exit(1);
  }
  if(!checks[2])
  {
    printErrorMessage("Speaker", "Not connected!");
    exit(1);
  }
  updateMenu();
  speaker.makeSound(Speaker::Sound::BOOT);
}

void Controller::moveMenu(char right)
{
  clamp(selectedItem, right, 0, menus[menuY]);
  updateMenu();
}

void Controller::clamp(char& dest, char add, char min, char max)
{
  dest += add;
  if (dest >= max)
    dest = min;
  else if (dest < min)
    dest = max - 1;
}

void Controller::updateMenuY()
{
  clamp(menuY, 1, 0, 3);
  selectedItem = 0;
  updateMenu();
  display.print(3, display.centerText("Test ready!"));
  display.print(19, 3, " "); // This prevents chars to get stuck
}

void Controller::updateMenu()
{
  display.print(2, display.centerText(menuIO[menuY][selectedItem]->getConnectionName()));
}

void Controller::printTestResults()
{
  memset(errorBuffer, 0, sizeof(errorBuffer));
  strcpy(errorBuffer, "Error at pins: ");
  for (int i = 1; i <= menuIO[menuY][selectedItem]->getNumberOfPins(); i++)
  {
    if (result[i] != -100) // -100 is default value in the array
    {
      sprintf(errorPart2, "%d", result[i]);
      strcat(errorBuffer, errorPart2);
      strcat(errorBuffer, ",");
    }
  }
  errorBuffer[strlen(errorBuffer) - 1] = '\0'; // Removes last ','
}

void Controller::testConnector()
{
  memset(result, -100, sizeof(result));
  if (menuIO[menuY][selectedItem]->startTest(result))
  {
    display.print(3, display.centerText("Connection is OK"));
    speaker.makeSound(Speaker::Sound::SUCCESS);
  }
  else
  {
    memset(errorBuffer, 0, sizeof(errorBuffer));
    switch (result[0])
    {
      case 0: printTestResults(); break;
      case -2: strcat(errorBuffer, "NullPtr to the other connector"); break; // Error code -1 is no longer used
      case -3: strcat(errorBuffer, "Input can't output current!"); break;
      case -4: strcat(errorBuffer, "Can't connect two outputs!"); break;
      case -5: strcat(errorBuffer, "Connectors not implemented!"); break;
      default: sprintf(errorBuffer, "Unknown error code: %d", result[0]); break;
    }
    printErrorMessage(display.centerText(menuIO[menuY][selectedItem]->getConnectionName()), errorBuffer);
    speaker.makeSound(Speaker::Sound::ERROR);
  }
}

void Controller::run()
{
  switch (keyboard.readInput())
  {
    case 0: testConnector(); break; // AUTO
    case 1: updateMenuY(); break; // MENU
    case 2: moveMenu(-1); break; // LEFT
    case 3: moveMenu(1); break; // RIGT
    case 4: testConnector(); break; // POWER_BTN
  }

  if (timeUtils.checkInterval(1000))
  {
    if (printDebugChar)
      display.print(19, 1, "#");
    else
      display.print(19, 1, " ");
    printDebugChar = !printDebugChar;
  }
}
