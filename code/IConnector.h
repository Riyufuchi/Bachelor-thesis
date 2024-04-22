#ifndef _ICONNECTOR_H_
#define _ICONNECTOR_H_

#include <string.h>

namespace DeviceIO
{
  class IConnector
  {
    private:
    char name[20];
    public:
      IConnector(const char* name);
      virtual ~IConnector();
      const char* getName();
      // Virtual methods
      virtual bool testConnector() = 0;
  };
}
#endif
