#include "Arduino.h"
#include "Xlr3.h"

using namespace DeviceIO;

Xlr3::Xlr3() : Xlr3(Mode::IN, 0)
{}

Xlr3::Xlr3(IConnector* output) : Xlr3(Mode::IN, output)
{

}

Xlr3::Xlr3(Mode mode, IConnector* output) : IConnector("XLR 3", 0, 3, output)
{
  this->mode = mode;
  switch (mode)
  {
    case INPUT: this->pins = new char[3]{22, 24, 0}; break;
    case OUTPUT: this->pins = new char[3]{26, 28, 0}; break;
  }
}

Xlr3::~Xlr3()
{
}

bool Xlr3::testConnector()
{
  return true;
}
