#ifndef _ICONNECTOR_H_
#define _ICONNECTOR_H_

namespace DeviceIO
{
  class IConnector
  {
    public:
      IConnector() = default;
      virtual ~IConnector() = default;
      virtual void sendSignal() = 0;
      virtual bool reciveSignal() = 0;
  };
}
#endif
