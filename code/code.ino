#include "Controller.h"

Device::Controller con;

void setup()
{
  con.initilize();
}

void loop()
{
  con.run();
}
