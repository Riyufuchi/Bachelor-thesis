#include "ConFail.h"

using namespace DeviceIO;

ConFail::ConFail() : IConnector("Unconnected")
{
}

ConFail::~ConFail()
{
}

bool ConFail::testConnector()
{
  return false;
}