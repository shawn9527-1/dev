#include "Log.h"
#include "TcpTransport.h"

TcpTransport::TcpTransport(StreamSocket socket)
	: _socket(socket)
{

}

int TcpTransport::send(char *data, int len)
{
	LOG("Enter");
	_socket.sendBytes(data, len, 0);
}