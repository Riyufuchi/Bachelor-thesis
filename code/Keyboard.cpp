#include "Keyboard.h"

using namespace Device;

Keyboard::Keyboard()
{
  //this->stisk = 0;
}

Keyboard::~Keyboard()
{
}

void Keyboard::initialize()
{  
  for(int x = 0; x < NUM_OF_BTNS; x++)
  {
    pinMode(tlacitka[x], INPUT_PULLUP);
  }
}
int Keyboard::readInput()
{
  for(int x = 0; x < NUM_OF_BTNS; x++)
  {
    //stisk = digitalRead(tlacitka[x]);
    if (digitalRead(tlacitka[x]) == LOW)
    {
      delay(100);
      return x;
    }
  }
  return -1;
}
