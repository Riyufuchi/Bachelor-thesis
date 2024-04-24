#include "IConnector.h"

using namespace DeviceIO;

IConnector::IConnector(const char* name) : IConnector(name, 0, 0)
{
}

IConnector::IConnector(const char* name, char pins[], char numberOfPins) : IConnector(name, pins, numberOfPins, 0)
{
}

IConnector::IConnector(const char* name, char pins[], char numberOfPins, IConnector* con)
{
  strncpy(this->name, name, sizeof(this->name));
  this->name[sizeof(this->name) - 1] = '\0';
  this->pins = pins;
  this->numberOfPins = numberOfPins;
  reconnectTo(con);
}

IConnector::~IConnector()
{
  if (pins != nullptr)
    delete[] pins;
}

void IConnector::reconnectTo(IConnector* connector)
{
  output = connector;
  memset(connectionName, 0, sizeof(connectionName));
  strcpy(connectionName, name);
  strcat(connectionName, " - ");
  if (output == nullptr)
    strcat(connectionName, "NONE");
  else
    strcat(connectionName, output->getName());
}

bool IConnector::startTest()
{
  if (output == nullptr)
    return false;
  return testConnector();
}

const char* IConnector::getConnectionName()
{
  return connectionName;
}

const char* IConnector::getName()
{
  return name;
}
