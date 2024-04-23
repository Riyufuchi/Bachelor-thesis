#include "Bosh.h"

using namespace DeviceIO;

Bosh::Bosh() : IConnector("Bosh")
{
}

Bosh::~Bosh()
{
}

bool Bosh::testConnector()
{
  return true;
}
