#include "Shimano.h"

using namespace DeviceIO;

Shimano::Shimano() : IConnector("Shimano", Mode::OUT)
{
}

Shimano::~Shimano()
{
}

bool Shimano::testConnector(char& errorCode)
{
  return true;
}
