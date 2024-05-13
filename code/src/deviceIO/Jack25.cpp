#include "Jack25.h"

using namespace DeviceIO;

Jack25::Jack25() : Jack25(Mode::IN, nullptr)
{
}

Jack25::Jack25(Mode mode, Connector* otherOne) : Connector("Jack 2.5", new char[2]{32, 33}, 2, mode, otherOne)
{
}

Jack25::~Jack25()
{
}