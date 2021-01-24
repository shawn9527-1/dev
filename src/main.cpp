#include <string.h>

#include "Log.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketAcceptor.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Runnable.h"
#include "Poco/Thread.h"
#include "TcpAcceptor.h"
#include "UdpReactorHandler.h"

#include "NormalServiceAgent.h"
#include "BFCPServer.h"

using Poco::Net::ServerSocket;
using Poco::Net::SocketAcceptor;
using Poco::Net::DatagramSocket;
using Poco::Net::SocketAddress;
using Poco::Thread;

#define UDP_HELLO "hello udp client\n"

BFCPServer bfcpServer;
NormalServiceAgent serviceAgent(&bfcpServer);

class TestUdp : public Poco::Runnable
{
public:
	TestUdp(BFCPServer& bfcpServer) 
		: _bfcpServer(bfcpServer)
	{

	}

	void run()
	{
		char cmd[24] = { 0 };
		
		while (1)
		{
			bzero(cmd, sizeof(cmd));
			fgets(cmd, sizeof(cmd), stdin);
			cmd[strlen(cmd) - 1] = '\0';
			LOG("cmd:%s", cmd);
			if (0 == strcmp(cmd, "send"))
			{
				LOG("Enter");
				_bfcpServer.sendAll((char *)UDP_HELLO, strlen(UDP_HELLO));
			}
			else if (0 == strcmp(cmd, "invite"))
			{
				serviceAgent.invite();
			}
			else if (0 == strcmp(cmd, "notify"))
			{
				LOG("Enter");
				serviceAgent.notifyShareStart(1);
			}
		}
	}

private:
	BFCPServer _bfcpServer;
};

class TcpAcceptor
{
public:
	TcpAcceptor(StreamSocket& socket, SocketReactor& reactor)
	{			
		LOG("Enter");
		
		 _tcpReactorHandler = new TcpReactorHandler(socket, reactor);
		 _tcpReactorHandler->setObserver(&bfcpServer);
		 _tcpReactorHandler->initConnect();
	}

private:
	ReactorHandler *_tcpReactorHandler;
};

int main(int argc, char **argv)
{
	int port = 9977;

	SocketReactor reactor;
#if 1	
	DatagramSocket *udpsocket = new DatagramSocket(SocketAddress("0.0.0.0", port));

	ReactorHandler *udpHandler = new UdpReactorHandler(*udpsocket, reactor);
	udpHandler->setObserver(&bfcpServer);
	udpHandler->initConnect();
#endif

	ServerSocket svs(port);
	SocketAcceptor<TcpAcceptor> acceptor(svs, reactor);
	
	Thread thread;
	thread.start(reactor);

	Thread threadMsg;
	TestUdp testUdp(bfcpServer);
	threadMsg.start(testUdp);

	thread.join();
	threadMsg.join();

	return 0;
}
