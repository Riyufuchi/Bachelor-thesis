#include "Controller.h"

using namespace Device;

Controller::Controller()
{
  testIO[0] = new DeviceIO::ConOK();
}

Controller::~Controller()
{
}

void Controller::initilize()
{
  dp.initDisplay();
  //      (1, "--------------------");
  dp.print(1, "  Bakalarska prace");
  dp.print(2, "------00:00:00------");
  dp.print(3, "     UPCE  2024");
  dp.print(4, " C/C++ is the best!");
}

void Controller::run()
{
  tTime.seconds = millis() / 1000;
  tTime.hours = tTime.seconds / 3600;
  tTime.minutes = tTime.seconds / 60 - (tTime.hours * 60); //(tTime.hours * 60) % 60;
  tTime.seconds = tTime.seconds % 60;

  if (tTime.seconds < 10)
    dp.print(12, 2, 0);

  TimeUtils::printTime(tTime.hours, 6, dp);
  TimeUtils::printTime(tTime.minutes, 9, dp);
  TimeUtils::printTime(tTime.seconds, 12, dp);
}
