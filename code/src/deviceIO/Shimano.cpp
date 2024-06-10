#include "Shimano.h"

using namespace DeviceIO;

Shimano::Shimano() : Shimano(Mode::IN, nullptr)
{
}

Shimano::Shimano(Mode mode, Connector* output) : Connector("Shimano", new char[5]{14, 15, 16, 17, 18}, 5, mode, output)
{
}

Shimano::~Shimano()
{
}
