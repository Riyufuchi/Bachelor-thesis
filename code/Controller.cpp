#include "Controller.h"

using namespace Device;
#define _VERSRION "Tester v0.7"

Controller::Controller() : selectedItem(0)
{
  this->testIO[0] = new DeviceIO::ConOK("USB");
  this->testIO[1] = new DeviceIO::ConOK("Serial");
  this->testIO[2] = new DeviceIO::ConOK("JACK");
}

Controller::~Controller()
{
  for (int i = 0; i < NUM_OF_CONNECTORS; i++)
    delete testIO[i];
}

void Controller::printErrorMessage(const char* what, const char* message)
{
  display.print(2, display.centerText(what));
  display.print(3, display.centerText(message));
  // TODO: Ability to print longer messages
}

void Controller::initilize()
{
  bool checks[3];
  checks[0] = display.initialize();
  if (!checks[0])
  {
    // TODO: Add possible warnings to the user
    return;
  }
  display.print(1, display.centerText(_VERSRION));
  display.print(4, display.centerText("C/C++ is the best!"));
  display.print(2, display.centerText("█"));
  checks[1] = keyboard.initialize();
  if(!checks[1] || keyboard.readInput() != -1) // Also checks for broken buttons
  {
    printErrorMessage("Keyboard", "Input error");
    return;
  }
  display.print(2, display.centerText("██"));
  checks[2] = speaker.initialize();
  display.print(2, display.centerText("███"));
  display.print(2, "------00:00:00------");
  updateMenu();
}

void Controller::moveMenu(char right)
{
  selectedItem += right;
  if (selectedItem >= NUM_OF_CONNECTORS)
    selectedItem = 0;
  else if (selectedItem < 0)
    selectedItem = NUM_OF_CONNECTORS - 1;
  updateMenu();
}

void Controller::updateMenu()
{
  display.print(3, display.centerText(testIO[selectedItem]->getName()));
}

void Controller::testConnector()
{
  testIO[selectedItem]->sendSignal();
  if (testIO[selectedItem]->reciveSignal())
  {
    strcpy(lineBuffer, CONNECTOR);
    strcat(lineBuffer, testIO[selectedItem]->getName());
    strcat(lineBuffer, " OK");
    display.print(4, display.centerText(lineBuffer));
  }
}

void Controller::run()
{
  switch (keyboard.readInput())
  {
    case 0: testConnector(); break;
    case 1: break;
    case 2: moveMenu(-1);break;
    case 3: moveMenu(1); break;
    case 4: break;
  }

  TimeUtils::updateTime(actualTime);
  if (actualTime.seconds < 10)
    display.print(12, 2, 0);
  TimeUtils::printTime(actualTime.hours, 6, display);
  TimeUtils::printTime(actualTime.minutes, 9, display);
  TimeUtils::printTime(actualTime.seconds, 12, display);
}
