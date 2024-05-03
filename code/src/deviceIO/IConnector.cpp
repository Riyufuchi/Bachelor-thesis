#include "IConnector.h"

using namespace DeviceIO;

IConnector::IConnector(const char* name, Mode mode) : IConnector(name, nullptr, 0, mode)
{
}

IConnector::IConnector(const char* name, char pins[], char numberOfPinsm, Mode mode) : IConnector(name, pins, numberOfPins, nullptr, mode)
{
}

IConnector::IConnector(const char* name, char pins[], char numberOfPins, IConnector* con, Mode mode)
{
  strncpy(this->name, name, sizeof(this->name));
  this->name[sizeof(this->name) - 1] = '\0';
  this->pins = pins;
  this->numberOfPins = numberOfPins;
  reconnectTo(con);
  setMode(mode);
}

IConnector::~IConnector()
{
  if (pins != nullptr)
    delete[] pins;
}

bool IConnector::testConnector(char& errorCode)
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
        errorCode = pinID + 1;
        break;
      }
    }
  }
  return (pinCheck == numberOfPins);
}

void IConnector::setMode(Mode mode)
{
  this->mode = mode;
  if (pins == nullptr || numberOfPins == 0)
    return;
  uint8_t pinOption = 0;
  switch (mode) 
  {
    case IN: pinOption = INPUT_PULLUP; break;
    case OUT: pinOption = OUTPUT; break;
  }
  for (int i = 0; i < numberOfPins; i++)
    pinMode(pins[i], pinOption);   
}

void IConnector::reconnectTo(IConnector* connector)
{
  theOntherOne = connector;
  memset(connectionName, 0, sizeof(connectionName));
  const char* name2 = (theOntherOne == nullptr) ? "NONE" : theOntherOne->getName();
  if (mode == Mode::OUT)
    sprintf(connectionName, _FORMAT, name, name2);
  else
    sprintf(connectionName, _FORMAT, name2, name);
}

bool IConnector::startTest(char& errorCode)
{
  if (theOntherOne == nullptr)
  {
    errorCode = -2;
    return false;
  }
  if (mode == Mode::OUT) // This instance should be INPUT
  {
    if (theOntherOne->mode == Mode::OUT)
    {
      errorCode = -4;
      return false;
    }
    return theOntherOne->testConnector(errorCode);
  }
  if (theOntherOne->mode == Mode::IN) // The other one should be OUT in this case
  {
    errorCode = -3;
    return false;
  }
  return testConnector(errorCode);
}

char IConnector::getPin(const char ID)
{
  return pins[ID];
}

const char* IConnector::getConnectionName()
{
  return connectionName;
}

const char* IConnector::getName()
{
  return name;
}
