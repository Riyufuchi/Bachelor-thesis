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
        // Text is wider than or equal to the width, return a copy of the original text
        //char* result = new char[textLength + 1];
        //strcpy(result, text);
        return text;
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

void Display::initDisplay()
{
  lcd.begin(); // Inicializace LCD
  lcd.backlight(); // Zapnutí podsvícení
  delay(1000);
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
