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

bool IConnector::testConnector(char resultArr[])
{
  for (int i = 0; i < 3; i++)
  {
    pinCheck = 0;
    for (int pinID = 0; pinID < numberOfPins; pinID++)
    {
      digitalWrite(theOtherOne->getPin(pinID), LOW);
      if (digitalRead(pins[pinID]) == LOW)
      {
        pinCheck++;
      }
      else
      {
        pinCheck = 0;
        resultArr[pinID + 1] = pinID + 1;
      }
    }
  }
  resultArr[0] = 0; // Test execution was success
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
  theOtherOne = connector;
  memset(connectionName, 0, sizeof(connectionName));
  const char* name2 = (theOtherOne == nullptr) ? "NONE" : theOtherOne->getName();
  if (mode == Mode::OUT)
    snprintf(connectionName, sizeof(connectionName), _FORMAT, name, name2);
  else
    snprintf(connectionName, sizeof(connectionName), _FORMAT, name2, name);
}

bool IConnector::startTest(char resultArr[])
{
  if (theOtherOne == nullptr)
  {
    resultArr[0] = -2;
    return false;
  }
  if (!(isReady() && theOtherOne->isReady()))
  {
    resultArr[0] = -5;
    return false;
  }
  if (mode == Mode::OUT) // This instance should be INPUT
  {
    if (theOtherOne->mode == Mode::OUT)
    {
      resultArr[0] = -4;
      return false;
    }
    return theOtherOne->testConnector(resultArr);
  }
  if (theOtherOne->mode == Mode::IN) // The other one should be OUT in this case
  {
    resultArr[0] = -3;
    return false;
  }
  return testConnector(resultArr);
}

bool IConnector::isReady()
{
  return (numberOfPins != 0 && pins != nullptr);
}

const char IConnector::getNumberOfPins()
{
  return numberOfPins;
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
