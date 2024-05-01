#include "Jack21.h"

using namespace DeviceIO;

Jack21::Jack21() : Jack21(Mode::IN, nullptr)
{
}

Jack21::Jack21(Mode mode, IConnector* otherOne) : IConnector("Jack 2.1", new char[2]{30, 31}, 2, otherOne, mode)
{
}

Jack21::~Jack21()
{
}