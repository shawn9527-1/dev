#ifndef __BFCP_CLIENT_H__
#define __BFCP_CLIENT_H__

#if 0
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"

//#include "ReactorHandler.h"
//#include "SipShareObserver.h"
//#include "BFCPConference.h"
//#include "ConferenceManager.h"
//#include "BFCPClientManager.h"

//#include "FirstHello.h"

using Poco::Net::DatagramSocket;
using Poco::Net::StreamSocket;
using Poco::Net::SocketAddress;
#endif

class ReactorHandler;
class SipShareObserver;
class FirstHello;
class ConferenceManager;
class BFCPClientMananger;

class BFCPClient
{
public:
	BFCPClient(ReactorHandler *reactorHandler);

	//void setClientManager(BFCPClientMananger *clientManager) { _bfcpClientManager = clientManager; }
	void setConferenceManager(ConferenceManager *conferenceManager) { _conferenceManager = conferenceManager; }
	void setFirstObserver(FirstHello *firstObserver) { _fistHelloObserver = firstObserver; }
	void setSipShareObserver(SipShareObserver* sipShareObserver) { _sipShareObserver = sipShareObserver; }

	int doSend(char *data, int len);

	int doRecv(char *data, int len);
	int processMessage(char *data);
	
	int doFirstHello(int userId);
	
	void sendRequestFloor(int status); 
	void onShareStart(int userId);

private:
	ReactorHandler*         _reactorHandler;
	ConferenceManager*      _conferenceManager;
	FirstHello*             _fistHelloObserver;
	SipShareObserver*       _sipShareObserver;
	//BFCPClientMananger*     _bfcpClientManager;
};

#endif
