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
  //this->testIO[3] = new DeviceIO::ConFail();
  // Uni - xlr 3, jack 2.1 2.5; rca
  // Bosh
  // Shimano
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
  char part1[20]; 
  char part2[20];
  splitMessage(message, part1, part2, 20);
  // Print the two parts on separate lines
  display.print(2, display.centerText(what));
  display.print(3, display.centerText(part1));
  display.print(4, display.centerText(part2));
}

void Controller::resetMainMenu()
{
  selectedItem = 0;
  display.print(1, display.centerText(_VERSRION));
  //display.print(4, "------00:00:00------");
  display.print(3, display.centerText("C/C++ is the best!"));
  updateMenu();
}

void Controller::initDisplayText()
{
  display.print(1, display.centerText(_VERSRION));
  display.print(3, display.centerText("C/C++ is the best!"));
}

void Controller::initilize()
{
  bool checks[3];
  checks[0] = display.initialize();
  if (!checks[0])
  {
    checks[2] = speaker.initialize();
    if(!checks[2])
      return;
    speaker.makeSound(Speaker::Sound::BOOT);
    speaker.makeSound(Speaker::Sound::ERROR);
  }
  initDisplayText();
  //display.print(2, display.centerText("#"));
  checks[1] = keyboard.initialize();
  if(!checks[1] || keyboard.readInput() != -1) // Also checks for broken buttons
  {
    printErrorMessage("Keyboard", "Input error");
    return;
  }
  //display.print(2, display.centerText("##"));
  checks[2] = speaker.initialize();
  if(!checks[2])
  {
    printErrorMessage("Speaker", "Not connected!");
    return;
  }
  //display.print(2, display.centerText("###"));
  //display.print(4, "------00:00:00------");
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
  memset(lineBuffer, 0, sizeof(lineBuffer));
  strcat(lineBuffer, "Result:");
  code = -100;
  if (testIO[selectedItem]->startTest(code))
  {
    strcat(lineBuffer, " OK");
    display.print(3, display.centerText(lineBuffer));
    speaker.makeSound(Speaker::Sound::SUCCESS);
  }
  else
  {
    memset(errorBuffer, 0, sizeof(errorBuffer));
    switch (code)
    {
      case -1: strcat(errorBuffer, "Only input connector can be tested"); break;
      case -2: strcat(errorBuffer, "NullPtr to the other connector"); break;
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
}

void Controller::run()
{
  switch (keyboard.readInput())
  {
    case 0: testConnector(); break;
    case 1: resetMainMenu(); break;
    case 2: moveMenu(-1);break;
    case 3: moveMenu(1); break;
    case 4: testConnector(); break;
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
