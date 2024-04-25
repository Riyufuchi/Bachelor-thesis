#include "Arduino.h"
#ifndef _TIME_UTILS_H_
#define _TIME_UTILS_H_

#include "../components/Display.h"

namespace Device
{
  class TimeUtils
  {
    private:
    unsigned long previousMillis;
    unsigned long currentMillis;
    public:
    struct Time
    {
      int hours {0};
      int minutes {0};
      int seconds {0}; // int will overflow in +-49 days, this program don't account for running longer than day tho 
    };
    TimeUtils() = default;
    ~TimeUtils() = default;
    bool checkInterval(long interval)
    {
      currentMillis = millis();
      if (currentMillis - previousMillis >= interval)
      {
        previousMillis = currentMillis;
        return true;
      }
      return false;
    }
    static void printTime(int val, int posBase, Display& dp)
    {
      if (val < 10)
        dp.print(posBase + 1, 4, val);
      else
        dp.print(posBase, 4, val);
    }
    static void updateTime(Time& tTime)
    {
      tTime.seconds = millis() / 1000;
      tTime.hours = tTime.seconds / 3600;
      tTime.minutes = tTime.seconds / 60 - (tTime.hours * 60); //(tTime.hours * 60) % 60;
      tTime.seconds = tTime.seconds % 60;
    }
  };
}
#endif
