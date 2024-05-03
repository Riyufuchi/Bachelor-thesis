#ifndef _ICONNECTOR_H_
#define _ICONNECTOR_H_

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
  class IConnector
  {
    private:
      char name[19];
      char connectionName[19];
      virtual bool testConnector(char& errorCode);
    protected:
      char pinCheck;
      Mode mode;
      IConnector* theOntherOne;
      char* pins;
      char numberOfPins {0};
    public:
      IConnector(const char* name, Mode mode);
      IConnector(const char* name, char pins[], char numberOfPins, Mode mode);
      IConnector(const char* name, char pins[], char numberOfPins, IConnector* con, Mode mode);
      virtual ~IConnector();
      // Utils
      bool startTest(char& errorCode);
      void reconnectTo(IConnector* connector);
      // Getters
      const char* getName();
      const char* getConnectionName();
      char getPin(const char ID);
      // Setters
      void setMode(Mode mode);
  };
}
#endif
