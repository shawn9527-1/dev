#include <stdlib.h>
#include <string>
#include "Log.h"
#include "BFCPClient.h"
#include "ConferenceManager.h"

#include "ReactorHandler.h"
#include "SipShareObserver.h"
#include "BFCPConference.h"
#include "ConferenceManager.h"
#include "FirstHello.h"

//#include "BFCPClientManager.h"

#define REQUEST_FLOOR "sendRequestFloor status"

BFCPClient::BFCPClient(ReactorHandler *reactorHandler)
	: _reactorHandler(reactorHandler)
{

}

int BFCPClient::doSend(char *data, int len)
{
	LOG("Enter");

	//_transport->send(data, len);
	if (_reactorHandler)
	{
		_reactorHandler->doSend(data, len);
	}

	LOG("Leave");
}

int BFCPClient::doRecv(char *data, int len)
{
	LOG("data:%s", data);
	processMessage(data);
	//doSend(data, len);
}

struct BfcpMessage
{
	char userId;
	char *cmd;
};

int BFCPClient::processMessage(char *data)
{
	int userId = 1;
	BfcpMessage *bfcpMsg = (BfcpMessage *)data;
	bfcpMsg->userId = atoi(&data[0]);
	bfcpMsg->cmd = data + 1;

	userId = bfcpMsg->userId;

	LOG("userId:%d, cmd:%s", userId, bfcpMsg->cmd);

	LOG("Enter");
#if 1
	if (strstr(bfcpMsg->cmd, "hello"))
	{
		LOG("Enter");
		if (_conferenceManager && !_conferenceManager->findConf(userId))
		{
			LOG("Enter");
			BFCPConference *conf = _conferenceManager->addConf(userId);
			if (conf)
			{			
				LOG("Enter");	
				if (!conf->findUser(userId))
				{
					LOG("Enter");
					BFCPClient* client = conf->addUser(userId, this);
					client->doFirstHello(userId);
				}							
			}
		}
	}
	else if (strstr(data, "onshare"))
	{
		BFCPConference *conf = _conferenceManager->findConf(userId);
		if (conf)
		{
			BFCPClient* client = conf->findUser(userId);
			client->onShareStart(1);
		}
	}
#endif	
}

int BFCPClient::doFirstHello(int userId)
{	
	LOG("Enter");
	if (_fistHelloObserver)
	{
		LOG("Enter");
		_fistHelloObserver->onFirstHello(userId);
	}
}

void BFCPClient::onShareStart(int userId)
{
	_sipShareObserver->onShareStart(userId);
}

void BFCPClient::sendRequestFloor(int status)
{
	LOG("Enter");

	if (_reactorHandler)
	{
		_reactorHandler->doSend(REQUEST_FLOOR, strlen(REQUEST_FLOOR));
	}
}