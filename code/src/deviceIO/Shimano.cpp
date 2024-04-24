#include "Shimano.h"

using namespace DeviceIO;

Shimano::Shimano() : IConnector("Shimano", Mode::IN)
{
}

Shimano::~Shimano()
{
}

bool Shimano::testConnector(char& errorCode)
{
  return true;
}
