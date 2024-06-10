#include "Bosh.h"

using namespace DeviceIO;

Bosh::Bosh() : Bosh(Mode::IN, nullptr)
{
}

Bosh::Bosh(Mode mode, Connector* output) : Connector("Bosh", new char[3]{2, 3, 4}, 3, mode, output)
{
}

Bosh::~Bosh()
{
}
