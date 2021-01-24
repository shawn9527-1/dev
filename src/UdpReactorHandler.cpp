#include "Log.h"
#include "UdpReactorHandler.h"

UdpReactorHandler::UdpReactorHandler(DatagramSocket& socket, SocketReactor& reactor)
	: ReactorHandler(socket, reactor)
	, _socket(socket)
{

}

void UdpReactorHandler::onReadable(const AutoPtr<ReadableNotification>& pNf)
{
	char buffer[1024] = { 0 };

	int len = _socket.receiveFrom(buffer, sizeof(buffer), _address);
	if (len > 0)
	{
		LOG("udp buf:%s", buffer);
		_observer->rawDataRead(this, buffer, len);
	}	
}

void UdpReactorHandler::onWritable(const AutoPtr<WritableNotification>& pNf)
{

}

int UdpReactorHandler::doSend(const char *data, int len)
{
	int sendBytes = 0;

	LOG("DoSend");

	try
	{
		sendBytes = _socket.sendTo(data, len, _address);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return sendBytes;
}
