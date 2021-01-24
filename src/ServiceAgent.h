#ifndef __SERVICE_AGENT_H__
#define __SERVICE_AGENT_H__

#include "FirstHello.h"

class ServiceAgent : public FirstHello
{
public:
    virtual void invite() = 0;
};

#endif

