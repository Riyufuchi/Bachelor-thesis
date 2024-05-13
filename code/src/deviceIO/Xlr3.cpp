#include "Arduino.h"
#include "Xlr3.h"

using namespace DeviceIO;

Xlr3::Xlr3(Connector* output) : Xlr3(Mode::IN, output)
{

}

Xlr3::Xlr3(Mode mode, Connector* output) : Connector("XLR-3", nullptr, 2, mode, output)
{
  switch (mode)
  {
    case OUT: this->pins = new char[2]{22, 24}; break;
    case IN: this->pins = new char[2]{26, 28}; break;
  }
  setMode(mode);
}

Xlr3::~Xlr3()
{
}