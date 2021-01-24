#include "Log.h"
#include "BFCPServer.h"
#include "BFCPClientManager.h"
#include "BFCPClient.h"
#include "SipShareObserver.h"
#include "BFCPConference.h"
#include "ConferenceManager.h"

BFCPServer::BFCPServer()
	: _userIndex(0)
{
	_bfcpClientManager = new BFCPClientMananger;
}

void BFCPServer::connnected(ReactorHandler *handler)
{
	LOG("Enter");

	BFCPClient *client = _bfcpClientManager->add(handler);
	client->setFirstObserver(this);

#if 0
	int id = handler->getid();
	param = paramMap.find(id);
	sendhello(confid, userid);
#endif
}

void BFCPServer::onFirstHello(int userId)
{
	LOG("Enter userId:%d", userId);
	 if (_sipShareObservers.find(userId) != _sipShareObservers.end())
	 {
		 LOG("Enter");
		 BFCPConference *conf = ConferenceManager::findConf(userId);
		 if (conf)
		 {
			 LOG("Enter");
		 	BFCPClient *client = conf->findUser(userId);
			if (client)
			{
				LOG("Enter");
		 		client->setSipShareObserver(_sipShareObservers[userId]);
			}
		 }
	 }
}

void BFCPServer::connectTo(BFCPParam param)
{
#if 0
	DatagramSocket *udpsocket = new DatagramSocket(SocketAddress("0.0.0.0", port));
	SocketReactor reactor;	
	ReactorHandler *udpHandler = new UdpReactorHandler(*udpsocket, reactor);
	udpHandler->setObserver(&bfcpServer);
	udpHandler->initConnect();

	BFCPClient *client = _bfcpClientManager->add(handler);
	client->setconfId();
	client->setUserId();
#endif	
}

void BFCPServer::doConnect(ReactorHandler *handler)
{

}

void BFCPServer::rawDataRead(ReactorHandler *handler, char *data, int len)
{
	LOG("Enter");

	BFCPClient *client = _bfcpClientManager->find(handler);
	if (client)
	{
		LOG("Enter");
		client->doRecv(data, len);
	}
}

void BFCPServer::send(ReactorHandler *handler, char *data, int len)
{
	BFCPClient *client = _bfcpClientManager->find(handler);
	if (client)
	{
		//client->doSend(data, len, handler->getAddress());
		client->doSend(data, len);
	}
}

void BFCPServer::sendAll(char *data, int len)
{
	BFCPClientMap bfcpClientMap = _bfcpClientManager->getBfcpClientMap();

	LOG("map size:%d", (int)bfcpClientMap.size());

	BFCPClientMap::iterator iter = bfcpClientMap.begin();
	for (; iter != bfcpClientMap.end(); iter++)
	{
		LOG("map enter");
		iter->second->doSend(data, len);
		LOG("map leave");
	}
}

int BFCPServer::initBFCPConnect(SipShareObserver *sipShareObserver)
{	
	LOG("Enter");
	int userId = ++_userIndex;
	//反向通知
	_sipShareObservers.insert({userId, sipShareObserver});
	return userId;
}

void BFCPServer::onNotifyShareStart(int userId)
{
	LOG("Enter");

	//BFCPClient* client = _bfcpClientManager->findByUserId(userId);
	BFCPConference *conf = ConferenceManager::findConf(userId);
	if (conf)
	{
		BFCPClient* client = conf->findUser(userId);
		if (client)
		{
			LOG("Enter");
			client->sendRequestFloor(1);
		}
	}
}
