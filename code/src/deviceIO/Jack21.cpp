#include "Jack21.h"

using namespace DeviceIO;

Jack21::Jack21() : IConnector("Jakc 2.1")
{
}

Jack21::~Jack21()
{
}

bool Jack21::testConnector()
{
  return true;
}
