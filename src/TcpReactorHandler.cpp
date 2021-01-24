
#include "Log.h"
#include "TcpReactorHandler.h"

TcpReactorHandler::TcpReactorHandler(StreamSocket& socket, SocketReactor& reactor)
	: ReactorHandler(socket, reactor)
	, _socket(socket)
{

}

void TcpReactorHandler::onReadable(const AutoPtr<ReadableNotification>& pNf)
{
	char buffer[1024] = { 0 };

	int len = _socket.receiveBytes(buffer, sizeof(buffer), 0);
	if (len > 0)
	{
		LOG("buf:%s", buffer);
		_observer->rawDataRead(this, buffer, len);
	}	
}

void TcpReactorHandler::onWritable(const AutoPtr<WritableNotification>& pNf)
{

}

int TcpReactorHandler::doSend(const char *data, int len)
{
	LOG("DoSend");
	
	int sendBytes = 0;
	try
	{
		sendBytes = _socket.sendBytes(data, len);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	
	return sendBytes;
}