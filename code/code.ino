#include "display.h"

Display dp;

struct Time
{
  int hours;
  int minutes;
  int seconds; // int will overflow in +-49 days, this program don't account for running longer than day tho 
} tTime;

void printTime(int val, int posBase)
{
  if (val < 10)
    dp.print(posBase + 1, 2, val);
  else
    dp.print(posBase, 2, val);
}

void setup()
{
  dp.initDisplay();
  //      (1, "--------------------");
  dp.print(1, "  Bakalarska prace");
  dp.print(2, "------00:00:00------");
  dp.print(3, "     UPCE  2024");
  dp.print(4, " C/C++ is the best!");
}

void loop()
{
  tTime.seconds = millis() / 1000;
  tTime.hours = tTime.seconds / 3600;
  tTime.minutes = tTime.seconds / 60 - (tTime.hours * 60); //(tTime.hours * 60) % 60;
  tTime.seconds = tTime.seconds % 60;

  if (tTime.seconds < 10)
    dp.print(12, 2, 0);


  printTime(tTime.hours, 6);
  printTime(tTime.minutes, 9);
  printTime(tTime.seconds, 12);
}
