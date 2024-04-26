#include "Rca.h"

using namespace DeviceIO;

Rca::Rca() : IConnector("RCA", new char[2]{34, 35}, 2, Mode::OUT)
{
}

Rca::~Rca()
{
}
