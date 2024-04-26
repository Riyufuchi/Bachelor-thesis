#include "Jack25.h"

using namespace DeviceIO;

Jack25::Jack25() : IConnector("Jack 2.5", new char[2]{32, 33}, 2, Mode::OUT)
{
}

Jack25::~Jack25()
{
}