#include "ConOK.h"

using namespace DeviceIO;

ConOK::ConOK() : IConnector("USB", Mode::IN)
{
}

ConOK::~ConOK()
{
}

bool ConOK::testConnector(char& errorCode)
{
  return true;
}