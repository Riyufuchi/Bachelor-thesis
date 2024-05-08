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
      char connectionName[20];
      virtual bool testConnector(char resultArr[]);
    protected:
      char pinCheck;
      Mode mode;
      IConnector* theOtherOne;
      char* pins;
      char numberOfPins;
    public:
      IConnector(const char* name, Mode mode);
      IConnector(const char* name, char pins[], char numberOfPins, Mode mode);
      IConnector(const char* name, char pins[], char numberOfPins, Mode mode, IConnector* con);
      virtual ~IConnector();
      // Utils
      bool startTest(char resultArr[]);
      void reconnectTo(IConnector* connector);
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
