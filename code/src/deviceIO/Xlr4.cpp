#include "Arduino.h"
#include "Xlr4.h"

using namespace DeviceIO;

Xlr4::Xlr4() : Xlr4(Mode::OUT, nullptr)
{

}

Xlr4::Xlr4(Mode mode, IConnector* output) : IConnector("XLR-4", nullptr, 4, output, mode)
{
}

Xlr4::~Xlr4()
{
}


