#include "Jack21.h"

using namespace DeviceIO;

Jack21::Jack21() : IConnector("Jack 2.1", new char[2]{30, 31}, 2, Mode::OUT);
{
}

Jack21::~Jack21()
{
}

bool Jack21::testConnector(char& errorCode)
{
  return false;
}
