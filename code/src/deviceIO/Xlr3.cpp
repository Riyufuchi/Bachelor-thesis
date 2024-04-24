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
  setMode(mode);
}

Xlr3::~Xlr3()
{
}

bool Xlr3::testConnector(char& errorCode)
{
  for (int i = 0; i < 3; i++)
  {
    pinCheck = 0;
    for (int pinID = 0; pinID < numberOfPins; pinID++)
    {
      digitalWrite(theOntherOne->getPin(pinID), LOW);
      if (digitalRead(pins[pinID]) == LOW)
      {
        pinCheck++;
      }
      else
      {
        pinCheck = 0;
        errorCode = pins[pinID];
        break;
      }
    }
  }
  return (pinCheck == numberOfPins);
}
