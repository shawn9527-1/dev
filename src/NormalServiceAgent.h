#ifndef __NORMAL_SERVICE_AGENT_H__
#define __NORMAL_SERVICE_AGENT_H__

#include "ServiceAgent.h"
#include "MLShareObserver.h"
#include "SipShareObserver.h"

class NormalServiceAgent : public ServiceAgent, public SipShareObserver
{
public:
    NormalServiceAgent(MLShareObserver *observer);

    virtual void invite();
    virtual void notifyShareStart(int userId);
    
    //bfcpclient first hello
    virtual void onFirstHello(int userId);
    virtual void onShareStart(int userId);

private:
    MLShareObserver *_mlShareObserver;
    int             _userId;
    
};

#endif