#include "Arduino.h"
#include "display.h"

Display::Display() : lcd(0x27, 20, 4)
{
}

Display::~Display()
{
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