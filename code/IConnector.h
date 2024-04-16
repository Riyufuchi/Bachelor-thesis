#ifndef _ICONNECTOR_H_
#define _ICONNECTOR_H_

#include <string.h>

namespace DeviceIO
{
  class IConnector
  {
    private:
    char name[13];
    public:
      IConnector(const char* name);
      virtual ~IConnector();
      const char* getName();
      // Virtual methods
      virtual void sendSignal() = 0;
      virtual bool reciveSignal() = 0;
  };
}
#endif
