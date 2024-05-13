#ifndef _CONNECTOR_H_
#define _CONNECTOR_H_

#include <string.h>
#include "stdint.h"
#include "Arduino.h"

#define _FORMAT "%s -> %s"

namespace DeviceIO
{
  enum Mode
  {
    IN,
    OUT
  };
  class Connector
  {
    private:
      char name[19];
      char connectionName[20];
      virtual bool testConnector(char resultArr[]);
    protected:
      char pinCheck;
      Mode mode;
      Connector* theOtherOne;
      char* pins;
      char numberOfPins;
    public:
      Connector(const char* name, Mode mode);
      Connector(const char* name, char pins[], char numberOfPins, Mode mode, Connector* con = nullptr);
      virtual ~Connector();
      // Utils
      bool startTest(char resultArr[]);
      void reconnectTo(Connector* connector);
      bool isReady() const;
      // Getters
      const char* getName() const;
      const char* getConnectionName() const;
      const char getNumberOfPins() const;
      const char getPin(const char ID) const;
      // Setters
      void setMode(Mode mode);
  };
}
#endif
