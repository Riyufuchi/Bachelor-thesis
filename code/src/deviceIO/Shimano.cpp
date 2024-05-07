#include "Shimano.h"

using namespace DeviceIO;

Shimano::Shimano() : Shimano(Mode::IN, nullptr)
{
}

Shimano::Shimano(Mode mode, IConnector* output) : IConnector("Shimano", nullptr, 3, output, mode)
{
}

Shimano::~Shimano()
{
}
