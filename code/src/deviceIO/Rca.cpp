#include "Rca.h"

using namespace DeviceIO;

Rca::Rca() : Rca(Mode::IN, nullptr)
{
}

Rca::Rca(Mode mode, Connector* otherOne) : Connector("RCA", new char[2]{34, 35}, 2, mode, otherOne)
{
}

Rca::~Rca()
{
}
