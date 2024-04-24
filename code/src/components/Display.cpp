#include "Arduino.h"
#include "Display.h"

using namespace Device;

Display::Display() : DISPLAY_WIDTH(20), lcd(0x27, DISPLAY_WIDTH, 4)
{
}

Display::~Display()
{
}

char* Display::centerText(const char* text)
{
    int textLength = strlen(text);
    if (textLength >= DISPLAY_WIDTH)
    {
      memset(message, 0, sizeof(message));
      strncpy(message, text, 19);
      return message;
    }

    int spacesToAdd = DISPLAY_WIDTH - textLength;
    int spacesBefore = spacesToAdd / 2;
    int spacesAfter = spacesToAdd - spacesBefore;

    memset(message, ' ', spacesBefore);   // Fill spaces before text
    strcpy(message + spacesBefore, text); // Copy text
    memset(message + spacesBefore + textLength, ' ', spacesAfter); // Fill spaces after text
    message[DISPLAY_WIDTH - 1] = '\0'; // Null-terminate the string
    return message;
}

bool Display::initialize()
{
  lcd.begin(); // Inicializace LCD
  lcd.backlight(); // Zapnutí podsvícení
  delay(1000);
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
