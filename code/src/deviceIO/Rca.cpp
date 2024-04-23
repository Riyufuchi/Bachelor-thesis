#include "Rca.h"

using namespace DeviceIO;

Rca::Rca() : IConnector("RCA")
{
}

Rca::~Rca()
{
}

bool Rca::testConnector()
{
  return true;
}
