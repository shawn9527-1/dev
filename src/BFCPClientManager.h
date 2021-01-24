#ifndef __BFCP_CLIENT_MANAGER_H__
#define __BFCP_CLIENT_MANAGER_H__

#include <map>

//#include "ReactorHandler.h"
//#include "BFCPClient.h"

class ReactorHandler;
class BFCPClient;

typedef std::map<ReactorHandler*, BFCPClient*> BFCPClientMap;
typedef std::map<int, BFCPClient*> BFCPClients;

class BFCPClientMananger
{
public:	
	BFCPClientMananger();

	BFCPClient* add(ReactorHandler *handler);
	void del(ReactorHandler *handler);
	BFCPClient* find(ReactorHandler *handler);

	BFCPClient* findByUserId(int userId);

	BFCPClient* add(int userId, BFCPClient *client);

	void readRawData(ReactorHandler *handle, char *data, int len);

	BFCPClientMap getBfcpClientMap() { return _bfcpClientMap; }

private:
	BFCPClientMap  _bfcpClientMap;
	BFCPClients    _bfcpClients;
};

#endif
