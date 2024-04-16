#include "Controller.h"

using namespace Device;
#define _VERSRION "Tester v0.5"

Controller::Controller() : selectedItem(0)
{
  testIO[0] = new DeviceIO::ConOK("1");
  testIO[1] = new DeviceIO::ConOK("2");
  testIO[2] = new DeviceIO::ConOK("3");

}

Controller::~Controller()
{
}

void Controller::initilize()
{
  dp.initDisplay();
  dp.print(1, dp.centerText(_VERSRION));
  dp.print(2, "------00:00:00------");
  dp.print(3, dp.centerText("Cable: NONE"));
  dp.print(4, dp.centerText("C/C++ is the best!"));
  keyboard.initialize();
}

void Controller::moveMenu(bool right)
{
  if (right)
    selectedItem++;
  else
    selectedItem--;
  if (selectedItem >= NUM_OF_CONNECTORS)
    selectedItem = 0;
  else if (selectedItem < 0)
    selectedItem = NUM_OF_CONNECTORS - 1;
  updateMenu();
}

void Controller::updateMenu()
{
  const char* str = "Cable: ";
  strcpy(lineBuffer, str);
  strcat(lineBuffer, testIO[selectedItem]->getName());
  dp.print(3, dp.centerText(lineBuffer));
}

void Controller::run()
{
  switch (keyboard.readInput())
  {
    case 0: break;
    case 1: break;
    case 2: moveMenu(false);break;
    case 3: moveMenu(true); break;
    case 4: break;
  }

  TimeUtils::updateTime(actualTime);
  if (actualTime.seconds < 10)
    dp.print(12, 2, 0);
  TimeUtils::printTime(actualTime.hours, 6, dp);
  TimeUtils::printTime(actualTime.minutes, 9, dp);
  TimeUtils::printTime(actualTime.seconds, 12, dp);
}
