#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Display.h"

namespace Device
{
  class Controller
  {
    private:
      Display dp;
    public:
      Controller();
      ~Controller();
      void initilize();
      void run();
  };
}
#endif
