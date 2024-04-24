#include "Arduino.h"
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

void IConnector::setMode(Mode mode)
{
  this->mode = mode;
  uint8_t pinSetting = (uint8_t)mode; // input = in = 0; output = out = 1
  if (pins == nullptr || numberOfPins == 0)
    return;
  for (int i = 0; i < numberOfPins; i++)
    pinMode(pins[i], pinSetting);
}

void IConnector::reconnectTo(IConnector* connector)
{
  theOntherOne = connector;
  memset(connectionName, 0, sizeof(connectionName));
  strcpy(connectionName, name);
  strcat(connectionName, " - ");
  if (theOntherOne == nullptr)
    strcat(connectionName, "NONE");
  else
    strcat(connectionName, theOntherOne->getName());
}

bool IConnector::startTest()
{
  if (theOntherOne == nullptr)
    return false;
  return testConnector();
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
