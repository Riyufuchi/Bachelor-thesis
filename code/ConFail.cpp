#include "ConFail.h"

using namespace DeviceIO;

ConFail::ConFail() : IConnector("JACK - Fail")
{
}

ConFail::~ConFail()
{
}

bool ConFail::testConnector()
{
  return false;
}