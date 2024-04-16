#include "Arduino.h"
#include "Keyboard.h"

using namespace Device;

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::initialize()
{  
  for(int x = 0; x < NUM_OF_BTNS; x++)
  {
    pinMode(button_pins[x], INPUT_PULLUP);
  }
  //digitalWrite(44, HIGH);
}
int Keyboard::readInput()
{
  for(int x = 0; x < NUM_OF_BTNS; x++)
  {
    if (digitalRead(button_pins[x]) == LOW)
    {
      delay(200);
      return x;
    }
  }
  return -1;
}
