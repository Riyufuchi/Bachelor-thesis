#ifndef _TIME_UTILS_H_
#define _TIME_UTILS_H_

#include "Display.h"

namespace Device
{
  class TimeUtils
  {
    public:
    struct Time
    {
      int hours;
      int minutes;
      int seconds; // int will overflow in +-49 days, this program don't account for running longer than day tho 
    };
    TimeUtils();
    ~TimeUtils();
    static void printTime(int val, int posBase, Display& dp)
    {
      if (val < 10)
        dp.print(posBase + 1, 2, val);
      else
        dp.print(posBase, 2, val);
    }
  };
}
#endif
