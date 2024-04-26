#include "Arduino.h"
#include "Controller.h"

using namespace Device;

Controller::Controller()
{
  // Init outpus
  this->outputIO[0] = new DeviceIO::Xlr3(DeviceIO::Mode::OUT, 0);
  this->outputIO[1] = new DeviceIO::Jack21();
  this->outputIO[2] = new DeviceIO::Jack25();
  this->outputIO[3] = new DeviceIO::Rca();
  // Init inputs
  this->selectedItem = 0;
  this->testIO[0] = new DeviceIO::Xlr3(outputIO[0]);
  this->testIO[1] = new DeviceIO::Xlr3(outputIO[1]);
  this->testIO[2] = new DeviceIO::Xlr3(outputIO[2]);
  this->testIO[3] = new DeviceIO::Bosh();
  this->testIO[4] = new DeviceIO::Shimano();
}

Controller::~Controller()
{
  for (int i = 0; i < NUM_OF_CONNECTORS; i++)
    delete testIO[i];
  for (int i = 0; i < NUM_OF_OUTPUS; i++)
    delete outputIO[i];
}

void Controller::splitMessage(const char* message, char* part1, char* part2, int maxLength)
{
    int messageLength = strlen(message);
    if (messageLength <= maxLength)
    {
        strcpy(part1, message);
        part2[0] = '\0';
        return;
    }
    int partLength = 19;
    //while (message[partLength] != ' ' && partLength > 0) 
       // partLength--;
    strncpy(part1, message, partLength);
    part1[partLength + 1] = '\0'; // Null-terminate part1
    strcpy(part2, &message[partLength]);
}


void Controller::printErrorMessage(const char* what, const char* message)
{
  splitMessage(message, errorPart1, errorPart2, 20);
  // Print the two parts on separate lines
  display.print(2, display.centerText(what));
  display.print(3, display.centerText(errorPart1));
  display.print(4, display.centerText(errorPart2));
}

void Controller::initDisplayText()
{
  display.print(1, display.centerText(_VERSRION));
  display.print(3, display.centerText("Test ready!"));
  display.print(4, display.centerText("C/C++ is the best!"));
}

void Controller::initilize()
{
  bool checks[3];
  checks[0] = display.initialize();
  if (!checks[0])
  {
    checks[2] = speaker.initialize();
    if(!checks[2])
      exit(1);
    speaker.makeSound(Speaker::Sound::BOOT);
    speaker.makeSound(Speaker::Sound::ERROR);
  }
  initDisplayText();
  checks[1] = keyboard.initialize();
  if(!checks[1] || keyboard.readInput() != -1) // Also checks for broken buttons
  {
    printErrorMessage("Keyboard", "Input error");
    exit(1);
  }
  checks[2] = speaker.initialize();
  if(!checks[2])
  {
    printErrorMessage("Speaker", "Not connected!");
    exit(1);
  }
  selectedItem = 0;
  updateMenu();
}

void Controller::moveMenu(char right)
{
  selectedItem += right;
  if (selectedItem >= NUM_OF_CONNECTORS)
    selectedItem = 0;
  else if (selectedItem < 0)
    selectedItem = NUM_OF_CONNECTORS - 1;
  updateMenu();
}

void Controller::updateMenu()
{
  display.print(2, display.centerText(testIO[selectedItem]->getConnectionName()));
}

void Controller::testConnector()
{
  code = -100;
  if (testIO[selectedItem]->startTest(code))
  {
    display.print(3, display.centerText("Connection: OK"));
    speaker.makeSound(Speaker::Sound::SUCCESS);
  }
  else
  {
    memset(errorBuffer, 0, sizeof(errorBuffer));
    switch (code)
    {
      case -1: strcat(errorBuffer, "Only input connector can be tested"); break;
      case -2: strcat(errorBuffer, "NullPtr to the other connector"); break;
      case -3: strcat(errorBuffer, "Input can't output current!"); break;
      default: 
        if (code > 0)
          sprintf(errorBuffer, "Error at pin : %d", code);
        else
          sprintf(errorBuffer, "Unknown error code: %d", code);
      break;
    }
    printErrorMessage(display.centerText(testIO[selectedItem]->getConnectionName()), errorBuffer);
    speaker.makeSound(Speaker::Sound::ERROR);
  }
  //while (keyboard.readInput() == -1)
  //{}
  //display.print(3, display.centerText("Test ready!"));
}

void Controller::run()
{
  switch (keyboard.readInput())
  {
    case 0: testConnector(); break; // AUTO
    case 1: initilize(); break; // MENU
    case 2: moveMenu(-1);break; // LEFT
    case 3: moveMenu(1); break; // RIGT
    case 4: testConnector(); break; // POWER_BTN
  }

  if (timeUtils.checkInterval(1000))
  {
    if (printDebugChar)
      display.print(19, 1, "#");
    else
      display.print(19, 1, " ");
    printDebugChar = !printDebugChar;
  }

  /*TimeUtils::updateTime(actualTime);
  if (actualTime.seconds < 10)
    display.print(12, 4, 0);
  TimeUtils::printTime(actualTime.hours, 6, display);
  TimeUtils::printTime(actualTime.minutes, 9, display);
  TimeUtils::printTime(actualTime.seconds, 12, display);*/
}
