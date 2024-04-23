#include "IConnector.h"

using namespace DeviceIO;

IConnector::IConnector(const char* name)
{
  strncpy(this->name, name, sizeof(this->name));
  this->name[sizeof(this->name) - 1] = '\0';
}

IConnector::~IConnector()
{
}

const char* IConnector::getName()
{
  return name;
}
