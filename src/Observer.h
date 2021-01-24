#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class ReactorHandler;
class Observer
{
public:
	Observer() {}
	virtual void connnected(ReactorHandler *handler) = 0;
	//virtual void doConnnect(ReactorHandler *handler) = 0;
	virtual void rawDataRead(ReactorHandler *handler, char *data, int len) = 0;
};

#endif
