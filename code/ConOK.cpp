#include "ConOK.h"

using namespace DeviceIO;

ConOK::ConOK(const char* name) : IConnector(name)
{
}

ConOK::~ConOK()
{
}

void ConOK::sendSignal()
{
}

bool ConOK::reciveSignal()
{
  return true;
}
