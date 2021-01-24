#ifndef __TRANSPORT_H__
#define __TRANSPORT_H__

#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"

#include "ReactorHandler.h"

using Poco::Net::DatagramSocket;
using Poco::Net::StreamSocket;
using Poco::Net::SocketAddress;

class BFCPTransport
{
public:
	BFCPTransport(ReactorHandler *reactorHandler);

	int doSend(char *data, int len);

	int doRecv(char *data, int len);

private:
	ReactorHandler *_reactorHandler;	
};

#endif