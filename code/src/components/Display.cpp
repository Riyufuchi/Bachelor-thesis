#include "Arduino.h"
#include "Display.h"

using namespace Device;

Display::Display() : lcd(0x27, DISPLAY_WIDTH, 4)
{
}

Display::~Display()
{
}

void Display::splitMessage(const char* message, char* part1, char* part2)
{
    if (strlen(message) <= DISPLAY_WIDTH)
    {
        strcpy(part1, message);
        part2[0] = '\0';
        return;
    }
    partLength = DISPLAY_WIDTH - 1;
    //while (message[partLength] != ' ' && partLength > 0) 
       // partLength--;
    strncpy(part1, message, partLength);
    part1[partLength] = '\0'; // Null-terminate part1
    strcpy(part2, &message[partLength]);
}

char* Display::centerText(const char* text)
{
    textLength = strlen(text);
    if (textLength >= DISPLAY_WIDTH)
    {
      memset(rowBuffer, 0, sizeof(rowBuffer));
      strncpy(rowBuffer, text, 19);
      return text;
    }

    spacesToAdd = DISPLAY_WIDTH - textLength;
    spacesBefore = spacesToAdd / 2;
    spacesAfter = spacesToAdd - spacesBefore;

    memset(rowBuffer, ' ', spacesBefore);   // Fill spaces before text
    strcpy(rowBuffer + spacesBefore, text); // Copy text
    memset(rowBuffer + spacesBefore + textLength, ' ', spacesAfter); // Fill spaces after text
    rowBuffer[DISPLAY_WIDTH - 1] = '\0'; // Null-terminate the string
    return rowBuffer;
}

void Display::clearLine(int line)
{
  for (int i = 0; i < Display::DISPLAY_WIDTH; i++)
    print(i, line, " ");
}

bool Display::initialize()
{
  lcd.begin(); // Inicializace LCD
  lcd.backlight(); // Zapnutí podsvícení
  delay(200);
  return true;
}

void Display::setLine(int line)
{
  switch (line)
  {
    case 1: lcd.setCursor(0, 0); break;
    case 2: lcd.setCursor(0, 1); break;
    case 3: lcd.setCursor(0, 2); break;
    case 4: lcd.setCursor(0, 3); break;
    default: lcd.setCursor(0, 0); break;
  }
}
