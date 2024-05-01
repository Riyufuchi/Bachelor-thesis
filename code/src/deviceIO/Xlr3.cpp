#include "Arduino.h"
#include "Xlr3.h"

using namespace DeviceIO;

Xlr3::Xlr3(IConnector* output) : Xlr3(Mode::IN, output)
{

}

Xlr3::Xlr3(Mode mode, IConnector* output) : IConnector("XLR-3", nullptr, 2, output, mode)
{
  switch (mode)
  {
    case OUT: this->pins = new char[3]{22, 24, 0}; break;
    case IN: this->pins = new char[3]{26, 28, 0}; break;
  }
  setMode(mode);
}

Xlr3::~Xlr3()
{
}


