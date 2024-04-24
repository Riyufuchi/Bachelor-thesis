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
  bool high = false;
  if (mode == Mode::IN)
    high = true;
  char check = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int pinID = 0; pinID < numberOfPins; pinID++)
    {
      digitalWrite(theOntherOne->getPin(pinID), 1);
      if (digitalRead(pins[pinID]) == high)
      {
        check++;
      }
      else
      {
        check = 0;
        break;
      }
    }
    if (check == numberOfPins)
      return true;
  }
  return false;
}
