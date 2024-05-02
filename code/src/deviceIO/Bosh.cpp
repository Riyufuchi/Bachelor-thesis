#include "Bosh.h"

using namespace DeviceIO;

Bosh::Bosh() : IConnector("Bosh", Mode::OUT)
{
}

Bosh::~Bosh()
{
}

bool Bosh::testConnector(char& errorCode)
{
  return true;
}
