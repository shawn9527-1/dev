#ifndef __BFCP_SERVER_H__
#define __BFCP_SERVER_H__

#include <unordered_map>

//#include "ReactorHandler.h"
//#include "BFCPClient.h"
//#include "BFCPClientManager.h"
#include "FirstHello.h"

#include "Observer.h"
#include "MLShareObserver.h"

//class Observer;
//class BFCPServer : pubilc Observer

class ReactorHandler;
class BFCPClientMananger;
class SipShareObserver;

class BFCPServer : public Observer, public MLShareObserver, public FirstHello
{
public:
	BFCPServer();

	virtual void connnected(ReactorHandler *handler);

	virtual void doConnect(ReactorHandler *handler);

	virtual void onFirstHello(int userId);

	//MLShare
	//virtual void initBfcpConnet();

	virtual int initBFCPConnect(SipShareObserver *sipShareObserver);

	void  connectTo(BFCPParam param);

	void onNotifyShareStart(int userId);

	virtual void rawDataRead(ReactorHandler *handler, char *data, int len);

	void send(ReactorHandler *handler, char *data, int len);

	void sendAll(char *data, int len);

private:
	BFCPClientMananger*					       _bfcpClientManager;
	std::unordered_map<int, SipShareObserver*> _sipShareObservers;
	int                                        _userIndex;
};

#endif
