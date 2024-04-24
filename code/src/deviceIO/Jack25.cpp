#include "Jack25.h"

using namespace DeviceIO;

Jack25::Jack25() : IConnector("Jack 2.5", Mode::OUT)
{
}

Jack25::~Jack25()
{
}

bool Jack25::testConnector(char& errorCode)
{
  return true;
}
