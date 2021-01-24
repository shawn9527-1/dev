#include "Log.h"
//#include "BFCPClient.h"
#include "BFCPClientManager.h"
//#include "UdpTransport.h"
#include "ReactorHandler.h"
#include "BFCPClient.h"
#include "ConferenceManager.h"

BFCPClientMananger::BFCPClientMananger()
{

}

BFCPClient* BFCPClientMananger::add(ReactorHandler *handler)
{
	BFCPClient *client = new BFCPClient(handler);
	//client->setClientManager(this);
	client->setConferenceManager(new ConferenceManager);

	LOG("Enter handler:%p, client:%p", handler, client);

	_bfcpClientMap.insert(std::make_pair(handler, client));
	return client;
}

BFCPClient* BFCPClientMananger::add(int userId, BFCPClient *client)
{
	_bfcpClients.insert(std::make_pair(userId, client));
}

void BFCPClientMananger::del(ReactorHandler *handler)
{
	std::map<ReactorHandler*, BFCPClient*>::iterator iter = _bfcpClientMap.find(handler);
	if (iter != _bfcpClientMap.end())
	{
		_bfcpClientMap.erase(iter);
	}
}

BFCPClient* BFCPClientMananger::findByUserId(int userId)
{
	#if 1
	LOG("Enter");
	BFCPClients::iterator iter = _bfcpClients.find(userId);
	if (iter != _bfcpClients.end())
	{
		LOG("Enter");

		return iter->second;
	}

	return NULL;
	#endif
}

BFCPClient* BFCPClientMananger::find(ReactorHandler *handler)
{
	std::map<ReactorHandler*, BFCPClient*>::iterator iter = _bfcpClientMap.find(handler);
	if (iter != _bfcpClientMap.end())
	{
		return iter->second;
	}	
}

void BFCPClientMananger::readRawData(ReactorHandler *handle, char *data, int len)
{

}