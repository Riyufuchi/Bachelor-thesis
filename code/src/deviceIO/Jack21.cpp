#include "Jack21.h"

using namespace DeviceIO;

Jack21::Jack21() : IConnector("Jakc 2.1", Mode::OUT)
{
}

Jack21::~Jack21()
{
}

bool Jack21::testConnector(char& errorCode)
{
  return true;
}
