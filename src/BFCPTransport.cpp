#include "BFCPTransport.h"

#if 0
BFCPClient::BFCPClient(ReactorHandler *reactorHandler)
	: _reactorHandler(reactorHandler)
{

}

int BFCPClient::doSend(char *data, int len)
{
	LOG("Enter");

	//_transport->send(data, len);
	_reactorHandler->doSend(data, len);

	LOG("Leave");
}

int BFCPClient::doRecv(char *data, int len)
{
	LOG("data:%s", data);

    BFCP::prase(data);
	//doSend(data, len);
}
#endif