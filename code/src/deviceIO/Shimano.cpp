#include "Shimano.h"

using namespace DeviceIO;

Shimano::Shimano() : IConnector("Shimano")
{
}

Shimano::~Shimano()
{
}

bool Shimano::testConnector()
{
  return true;
}
