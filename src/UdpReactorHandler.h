#ifndef __UDP_REACTORHANDLER_H__
#define __UDP_REACTORHANDLER_H__

#include "ReactorHandler.h"

class UdpReactorHandler : public ReactorHandler
{
public:
	UdpReactorHandler(DatagramSocket& socket, SocketReactor& reactor);
	
	virtual void onReadable(const AutoPtr<ReadableNotification>& pNf);
	virtual void onWritable(const AutoPtr<WritableNotification>& pNf);
	virtual int doSend(const char *data, int len);

	DatagramSocket getSocket() { return _socket; }
	virtual SocketAddress getAddress() { return _address; }

private:
	DatagramSocket  _socket;
	SocketAddress   _address;
};

#endif
