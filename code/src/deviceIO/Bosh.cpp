#include "Bosh.h"

using namespace DeviceIO;

Bosh::Bosh() : Bosh(Mode::IN, nullptr)
{
}

Bosh::Bosh(Mode mode, IConnector* output) : IConnector("Bosh", nullptr, 3, mode, output)
{
}

Bosh::~Bosh()
{
}
