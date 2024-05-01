#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

#include "IComponent.h"

namespace Device
{
  class Display : public IComponent
  {
    public:
      static const char DISPLAY_WIDTH = 20;
    private:
      LiquidCrystal_I2C lcd; // Declaration without initialization
      char rowBuffer[DISPLAY_WIDTH];
    public:
      Display();
      ~Display();
      bool initialize() override;
      // Methods
      void setLine(int line); // Sets cursor to given line
      void Display::splitMessage(const char* message, char* part1, char* part2);
      //Functions
      char* centerText(const char* text);
      // Templates
      template <typename T>
      void print(int line, const T& text)
      {
        setLine(line);
        lcd.print(text);
      }
      template <typename T>
      void print(int x, int line, const T& text)
      {
        lcd.setCursor(x, line - 1);
        lcd.print(text);
      }
  };
 }
#endif
