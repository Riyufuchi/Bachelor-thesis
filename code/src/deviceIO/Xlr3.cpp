#include "Xlr3.h"

using namespace DeviceIO;

Xlr3::Xlr3() : IConnector("XLR 3")
{
}

Xlr3::~Xlr3()
{
}

bool Xlr3::testConnector()
{
  return true;
}
