#include "Jack21.h"

using namespace DeviceIO;

Jack21::Jack21() : Jack21(Mode::IN, nullptr)
{
}

Jack21::Jack21(Mode mode, Connector* otherOne) : Connector("Jack 2.1", new char[2]{10, 9}, 2, mode, otherOne)
{
}

Jack21::~Jack21()
{
}