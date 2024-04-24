#include "ConFail.h"

using namespace DeviceIO;

ConFail::ConFail() : IConnector("Unconnected", Mode::IN)
{
}

ConFail::~ConFail()
{
}

bool ConFail::testConnector(char& errorCode)
{
  return false;
}