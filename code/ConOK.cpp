#include "ConOK.h"

using namespace DeviceIO;

ConOK::ConOK(const char* name) : IConnector(name)
{
}

ConOK::~ConOK()
{
}

bool ConOK::testConnector()
{
  return true;
}
