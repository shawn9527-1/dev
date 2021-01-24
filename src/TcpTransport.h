#include "Poco/Net/StreamSocket.h"

#include "Transport.h"

using Poco::Net::StreamSocket;

class TcpTransport : public Transport
{
public:
	TcpTransport(StreamSocket socket);

	virtual int send(char *data, int len);

private:
	StreamSocket _socket;
};
