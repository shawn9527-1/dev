#ifndef __SIPOBSERVER_H__
#define __SIPOBSERVER_H__

class SipShareObserver
{
public:
    virtual void onShareStart(int userId) = 0;    
};

#endif