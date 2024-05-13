#include "Arduino.h"
#include "Xlr4.h"

using namespace DeviceIO;

Xlr4::Xlr4() : Xlr4(Mode::OUT, nullptr)
{

}

Xlr4::Xlr4(Mode mode, Connector* output) : Connector("XLR-4", nullptr, 4, mode, output)
{
}

Xlr4::~Xlr4()
{
}