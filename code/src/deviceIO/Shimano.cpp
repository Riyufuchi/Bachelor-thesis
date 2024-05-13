#include "Shimano.h"

using namespace DeviceIO;

Shimano::Shimano() : Shimano(Mode::IN, nullptr)
{
}

Shimano::Shimano(Mode mode, Connector* output) : Connector("Shimano", nullptr, 3, mode, output)
{
}

Shimano::~Shimano()
{
}
