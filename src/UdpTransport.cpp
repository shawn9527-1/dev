#include "Log.h"
#include "UdpTransport.h"

UdpTransport::UdpTransport(DatagramSocket socket)
	: _socket(socket)
{

}

int UdpTransport::send(char *data, int len)
{
	LOG("Enter");
//	_socket.sendTo(data, len, _address, 0);
}