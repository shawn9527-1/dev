#ifndef __ML_SHARE_OBS_H__
#define __ML_SHARE_OBS_H__

#include "CommonHeader.h"
//#include "ServiceAgent.h"

class SipShareObserver;
class MLShareObserver
{
public:
    virtual int initBFCPConnect(SipShareObserver *sipShareObserver) = 0;
    virtual void onNotifyShareStart(int userId) = 0;
};

#endif