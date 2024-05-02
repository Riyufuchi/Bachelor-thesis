#include "Arduino.h"
#include "Controller.h"

using namespace Device;

Controller::Controller()
{  
  // Init outputs
  this->selectedItem = 0;
  this->outputIO[0] = new DeviceIO::Xlr3(DeviceIO::Mode::OUT, nullptr);
  this->outputIO[1] = new DeviceIO::Bosh();
  this->outputIO[2] = new DeviceIO::Shimano();
  // XLR
  this->inputIO[0] = new DeviceIO::Xlr3(DeviceIO::Mode::IN, outputIO[0]);
  this->inputIO[1] = new DeviceIO::Jack21(DeviceIO::Mode::IN, outputIO[0]);
  this->inputIO[2] = new DeviceIO::Jack25(DeviceIO::Mode::IN, outputIO[0]);
  this->inputIO[3] = new DeviceIO::Rca();
  // Bosh
  this->inputIO[4] = this->outputIO[1] = new DeviceIO::Bosh();
}

Controller::~Controller()
{
  for (int i = 0; i < NUM_OF_INPUTS; i++)
    delete inputIO[i];
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
  checks[0] = display.initialize();
  if (!checks[0])
  {
    checks[2] = speaker.initialize();
    if(!checks[2])
      exit(1);
    speaker.makeSound(Speaker::Sound::BOOT);
    speaker.makeSound(Speaker::Sound::ERROR);
  }
  initDisplayText();
  checks[1] = keyboard.initialize();
  if(!checks[1]) // Also checks for broken buttons
  {
    printErrorMessage("Keyboard", "Failed init or stucked key");
    exit(1);
  }
  checks[2] = speaker.initialize();
  if(!checks[2])
  {
    printErrorMessage("Speaker", "Not connected!");
    exit(1);
  }
  selectedItem = 0;
  updateMenu();
}

void Controller::moveMenu(char right)
{
  selectedItem += right;
  if (selectedItem >= NUM_OF_INPUTS)
    selectedItem = 0;
  else if (selectedItem < 0)
    selectedItem = NUM_OF_INPUTS - 1;
  updateMenu();
}

void Controller::updateMenu()
{
  display.print(2, display.centerText(inputIO[selectedItem]->getConnectionName()));
}

void Controller::testConnector()
{
  code = -100;
  if (inputIO[selectedItem]->startTest(code))
  {
    display.print(3, display.centerText("Connection: OK"));
    speaker.makeSound(Speaker::Sound::SUCCESS);
  }
  else
  {
    memset(errorBuffer, 0, sizeof(errorBuffer));
    switch (code)
    {
      //case -1: strcat(errorBuffer, "Only input connector can be tested"); break;
      case -2: strcat(errorBuffer, "NullPtr to the other connector"); break;
      case -3: strcat(errorBuffer, "Input can't output current!"); break;
      case -4: strcat(errorBuffer, "Can't connect two outputs!"); break;
      default: 
        if (code > 0)
          sprintf(errorBuffer, "Error at pin : %d", code);
        else
          sprintf(errorBuffer, "Unknown error code: %d", code);
      break;
    }
    printErrorMessage(display.centerText(inputIO[selectedItem]->getConnectionName()), errorBuffer);
    speaker.makeSound(Speaker::Sound::ERROR);
  }
  //while (keyboard.readInput() == -1)
  //{}
  //display.print(3, display.centerText("Test ready!"));
}

void Controller::run()
{
  switch (keyboard.readInput())
  {
    case 0: testConnector(); break; // AUTO
    case 1: initilize(); break; // MENU
    case 2: moveMenu(-1);break; // LEFT
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
