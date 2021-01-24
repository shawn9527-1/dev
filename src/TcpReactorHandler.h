#ifndef __TCP_REACTORHANDLER_H__
#define __TCP_REACTORHANDLER_H__

#include "ReactorHandler.h"
#include "Poco/Net/ServerSocket.h"

using Poco::Net::ServerSocket;

class TcpReactorHandler : public ReactorHandler
{
public:
	TcpReactorHandler(StreamSocket& socket, SocketReactor& reactor);	

	virtual void onReadable(const AutoPtr<ReadableNotification>& pNf);
	virtual void onWritable(const AutoPtr<WritableNotification>& pNf);
	virtual int doSend(const char *data, int len);
	
	void setStreamSocket(StreamSocket socket) { _socket = socket; }

private:
	StreamSocket _socket;
};

#endif
