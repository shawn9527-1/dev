#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"

#include "Transport.h"

using Poco::Net::DatagramSocket;
using Poco::Net::SocketAddress;

class UdpTransport : public Transport
{
public:
	UdpTransport(DatagramSocket socket);
	virtual int send(char *data, int len);

private:
	SocketAddress _address;
	DatagramSocket _socket;
};
