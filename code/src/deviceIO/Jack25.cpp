#include "Jack25.h"

using namespace DeviceIO;

Jack25::Jack25() : Jack25(Mode::IN, nullptr)
{
}

Jack25::Jack25(Mode mode, IConnector* otherOne) : IConnector("Jack 2.5", new char[2]{32, 33}, 2, otherOne, mode)
{
}

Jack25::~Jack25()
{
}