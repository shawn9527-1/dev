#ifndef __TRANSPORT_H__
#define __TRANSPORT_H__

class Transport
{
public:
	virtual int send(char *data, int len) = 0;
	//virtual int send(char *data, int len) = 0;
};

#endif