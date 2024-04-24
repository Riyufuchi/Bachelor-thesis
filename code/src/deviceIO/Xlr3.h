#include "Arduino.h"
#ifndef _XLR3_H_
#define _XLR3_H_

#include "IConnector.h"

namespace DeviceIO
{
  class Xlr3 : public IConnector
  {
    public:
      enum Mode
      {
        IN,
        OUT
      };
    private:
      Mode mode;
      static const char NUM_OF_PINS = 3;
      static const char inputPins[NUM_OF_PINS] = {22, 24, 0};
      static const char outputPins[NUM_OF_PINS] = {22, 24, 0};
      IConnector& output;
    public:
    Xlr3();
    Xlr3(IConnector* output);
    Xlr3(Mode mode, IConnector* output);
    ~Xlr3();
    bool testConnector() override;
  };
}
#endif
