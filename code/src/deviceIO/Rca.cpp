#include "Rca.h"

using namespace DeviceIO;

Rca::Rca() : IConnector("RCA", Mode::OUT)
{
}

Rca::~Rca()
{
}

bool Rca::testConnector(char& errorCode)
{
  return true;
}
