#include "Shimano.h"

using namespace DeviceIO;

Shimano::Shimano() : IConnector("Shimano", Mode::IN)
{
}

Shimano::~Shimano()
{
}

bool Shimano::testConnector()
{
  return true;
}
