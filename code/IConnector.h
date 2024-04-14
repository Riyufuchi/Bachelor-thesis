#ifndef _ICONNECTOR_H_
#define _ICONNECTOR_H_

namespace DeviceIO
{
  class IConnector
  {
    public:
      IConnector();
      virtual ~IConnector();
      virtual void sendSignal() = 0;
      virtual bool reciveSignal() = 0;
  };
}
#endif
