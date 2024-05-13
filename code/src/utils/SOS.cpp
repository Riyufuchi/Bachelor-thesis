#include "SOS.h"

SignalSOS::SignalSOS(char pin) : PIN(pin)
{
	pinMode(PIN, OUTPUT);
}

SignalSOS::~SignalSOS()
{
}

void SignalSOS::signal(long interval)
{
  for (int i = 0; i < 3; i++) 
  {
    digitalWrite(PIN, HIGH);
    delay(interval);
    digitalWrite(PIN, LOW);
    delay(interval);
  }
}

void SignalSOS::sendSOS()
{
  signal(SHORT_DELAY);
  signal(LONG_DELAY);
  signal(SHORT_DELAY);
}
