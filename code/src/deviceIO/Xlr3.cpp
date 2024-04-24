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
    case INPUT: this->pins = new char[3]{22, 24, 0}; break;
    case OUTPUT: this->pins = new char[3]{26, 28, 0}; break;
  }
}

Xlr3::~Xlr3()
{
}

bool Xlr3::testConnector()
{
  // Read the input from the pin
  bool pinState = digitalRead(26);
  bool high = false;
  if (mode == Mode::IN)
    high = true;

  // Check if both pins are HIGH
  if (pinState == high) {
      return true; // Pins are connected
  } else {
      return false; // Pins are not connected
  }
}
