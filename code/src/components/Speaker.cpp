#include "Speaker.h"

using namespace Device;

Speaker::Speaker()
{
}

Speaker::~Speaker()
{
}

bool Speaker::initialize()
{
  return true;
}

void Speaker::makeSound(Speaker::Sound sound)
{
  switch (sound)
  {
    case SUCCESS: break;
    case ERROR: break;
    case BOOT: break;
  }
}
