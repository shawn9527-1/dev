#ifndef __REACTORHANDLER_H__
#define __REACTORHANDLER_H__

#include <exception>
#include <iostream>

#include "Poco/Net/Socket.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketReactor.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/NObserver.h"
#include "Poco/Net/SocketNotification.h"
#include "Poco/Net/SocketAddress.h"
#include "Observer.h"

using Poco::AutoPtr;
using Poco::NObserver;
using Poco::Net::DatagramSocket;
using Poco::Net::SocketReactor;
using Poco::Net::ReadableNotification;
using Poco::Net::WritableNotification;
using Poco::Net::SocketAddress;
using Poco::Net::StreamSocket;
using Poco::Net::Socket;

enum TransportType
{
	UDP,
	TCP
};

//class Observer;
class ReactorHandler
{
public:
	ReactorHandler(StreamSocket& socket, SocketReactor& reactor);
	ReactorHandler(DatagramSocket& socket, SocketReactor& reactor);
	
	virtual void onReadable(const AutoPtr<ReadableNotification>& pNf) = 0;
	virtual void onWritable(const AutoPtr<WritableNotification>& pNf) = 0;
	
	virtual int doSend(const char *data, int len) = 0;

	void initConnect();
	//void doConnect();

	//void setEvent(Socket& socket, SocketReactor& reactor);
	void setObserver(Observer *observer);
	virtual SocketAddress getAddress() { return _address; }
	StreamSocket getStreamSocket() { return _streamSocket; }
	DatagramSocket getDatagramSocket() { return _datagramSocket; }

	TransportType getTransportType() { return _transportType; }

protected:
	Observer*       _observer;

private:
	SocketAddress   _address;	
	StreamSocket    _streamSocket;
	DatagramSocket  _datagramSocket;
	SocketReactor&  _reactor;
	TransportType   _transportType;
};

#endif
