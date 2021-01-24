#include "Log.h"
#include "Observer.h"
#include "ReactorHandler.h"

ReactorHandler::ReactorHandler(StreamSocket& socket, SocketReactor& reactor)
	: _streamSocket(socket)
	, _reactor(reactor)
	, _transportType(TCP)
{
	_reactor.addEventHandler(socket, NObserver<ReactorHandler, ReadableNotification>(*this, &ReactorHandler::onReadable));
	_reactor.addEventHandler(socket, NObserver<ReactorHandler, WritableNotification>(*this, &ReactorHandler::onWritable));
}

ReactorHandler::ReactorHandler(DatagramSocket& socket, SocketReactor& reactor)
	: _datagramSocket(socket)
	, _reactor(reactor)
	, _transportType(UDP)
{
	_reactor.addEventHandler(socket, NObserver<ReactorHandler, ReadableNotification>(*this, &ReactorHandler::onReadable));
	_reactor.addEventHandler(socket, NObserver<ReactorHandler, WritableNotification>(*this, &ReactorHandler::onWritable));
}


#if 0
void ReactorHandler::onReadable(const AutoPtr<ReadableNotification>& pNf)
{
	char buffer[1024] = { 0 };

	int len = _socket.receiveFrom(buffer, sizeof(buffer), _address);
	if (len > 0)
	{
		LOG("udp buf:%s", buffer);
	}

	//_socket.sendBytes(buf, sizeof(buf), 0);
}


void ReactorHandler::onWritable(const AutoPtr<WritableNotification>& pNf)
{
	//LOG("Enter");	
	//_socket.sendBytes((char *)"hello", 5, 0);
}
#endif

void ReactorHandler::setObserver(Observer *observer)
{
	_observer = observer;	
}

void ReactorHandler::initConnect()
{
	_observer->connnected(this);
}

#if 0
void ReactorHandler::doConnect()
{
	_observer->doConnnect(this);
}
#endif