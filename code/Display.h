#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

namespace Device
{
  class Display
  {
    private:
      const char DISPLAY_WIDTH;
      char message[20];
      LiquidCrystal_I2C lcd; // Declaration without initialization
    public:
      Display();
      ~Display();
      void initDisplay();
      /**
      This method sets cursor to given line
      */
      void setLine(int line);
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
