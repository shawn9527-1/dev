#ifndef __TCP_ACCEPTOR_H__
#define __TCP_ACCEPTOR_H__

#include "Poco/Net/SocketAcceptor.h"
#include "Poco/Net/StreamSocket.h"
#include "TcpReactorHandler.h"
#include "BFCPServer.h"

using Poco::Net::SocketAcceptor;
using Poco::Net::SocketReactor;
using Poco::Net::StreamSocket;

#if 0
class TcpAcceptor
{
public:
	TcpAcceptor(StreamSocket& socket, SocketReactor& reactor)
	{			
		 BFCPServer bfcpServer;
		 _tcpReactorHandler = new TcpReactorHandler(socket, reactor);
		 _tcpReactorHandler->setObserver(&bfcpServer);
	}

	//ReactorHandler* getTcpReactorHandler() { return _tcpReactorHandler; }

private:
	ReactorHandler *_tcpReactorHandler;
};
#endif

#endif
