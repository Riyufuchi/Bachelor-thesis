#include "ConOK.h"

using namespace DeviceIO;

ConOK::ConOK() : IConnector("USB - OK")
{
}

ConOK::~ConOK()
{
}

bool ConOK::testConnector()
{
  return true;
}
