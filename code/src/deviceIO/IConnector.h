#ifndef _ICONNECTOR_H_
#define _ICONNECTOR_H_

#include <string.h>

namespace DeviceIO
{
  class IConnector
  {
    private:
      char name[19];
      char connectionName[19];
      virtual bool testConnector() = 0;
    protected:
      IConnector* output;
      char* pins;
      char numberOfPins {0};
    public:
      IConnector(const char* name);
      IConnector(const char* name, char pins[], char numberOfPins);
      IConnector(const char* name, char pins[], char numberOfPins, IConnector* con);
      virtual ~IConnector();
      const char* getName();
      const char* getConnectionName();
      void reconnectTo(IConnector* connector);
      bool startTest();
  };
}
#endif
