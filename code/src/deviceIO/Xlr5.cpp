#include "Arduino.h"
#include "Xlr5.h"

using namespace DeviceIO;

Xlr5::Xlr5() : Xlr5(Mode::OUT, nullptr)
{

}

Xlr5::Xlr5(Mode mode, IConnector* output) : IConnector("XLR-5", nullptr, 5, mode, output)
{
}

Xlr5::~Xlr5()
{
}