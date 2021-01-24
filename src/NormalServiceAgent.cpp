#include "Log.h"
#include "NormalServiceAgent.h"

NormalServiceAgent::NormalServiceAgent(MLShareObserver *observer)
    : _mlShareObserver(observer)
{

}

void NormalServiceAgent::invite()
{
    LOG("Enter");
    _userId = _mlShareObserver->initBFCPConnect(this);
    LOG("Enter userId:%d", _userId);
}

void NormalServiceAgent::notifyShareStart(int userId)
{
    LOG("Enter");
    
    _mlShareObserver->onNotifyShareStart(_userId);
}

void NormalServiceAgent::onFirstHello(int userId)
{
    LOG("first hello");
    //onStartShare()
}

void NormalServiceAgent::onShareStart(int userId)
{
    LOG("onShareStart");
}