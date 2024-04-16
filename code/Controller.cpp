#include "Controller.h"

using namespace Device;
#define _VERSRION "Tester v0.6"

Controller::Controller() : selectedItem(0)
{
  testIO[0] = new DeviceIO::ConOK("USB");
  testIO[1] = new DeviceIO::ConOK("Serial");
  testIO[2] = new DeviceIO::ConOK("JACK");
}

Controller::~Controller()
{
}

void Controller::initilize()
{
  dp.initDisplay();
  dp.print(1, dp.centerText(_VERSRION));
  dp.print(2, "------00:00:00------");
  dp.print(3, "");
  dp.print(4, dp.centerText("C/C++ is the best!"));
  keyboard.initialize();
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
  strcpy(lineBuffer, SELECTION_MENU);
  strcat(lineBuffer, testIO[selectedItem]->getName());
  dp.print(3, dp.centerText(lineBuffer));
}

void Controller::testConnector()
{
  testIO[selectedItem]->sendSignal();
  if (testIO[selectedItem]->reciveSignal())
  {
    strcpy(lineBuffer, CONNECTOR);
    strcat(lineBuffer, testIO[selectedItem]->getName());
    strcat(lineBuffer, " OK");
    dp.print(4, dp.centerText(lineBuffer));
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
    dp.print(12, 2, 0);
  TimeUtils::printTime(actualTime.hours, 6, dp);
  TimeUtils::printTime(actualTime.minutes, 9, dp);
  TimeUtils::printTime(actualTime.seconds, 12, dp);
}
