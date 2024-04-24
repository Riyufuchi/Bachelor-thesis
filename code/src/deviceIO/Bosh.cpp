#include "Bosh.h"

using namespace DeviceIO;

Bosh::Bosh() : IConnector("Bosh", Mode::IN)
{
}

Bosh::~Bosh()
{
}

bool Bosh::testConnector(char& errorCode)
{
  return true;
}
