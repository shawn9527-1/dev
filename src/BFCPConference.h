#ifndef __BFCP_CONFERENCE_H__
#define __BFCP_CONFERENCE_H__

///#include "BFCPClient.h"
#include "BFCPClientManager.h"

class BFCPConference
{
public:
    BFCPConference();

    void setBfcpClientManager(BFCPClientMananger *clientManager) { _bfcpClientManager = clientManager; }

    bool findConf(int confId);
    int addConf(int confId);
    BFCPClient* findUser(int userId);
    BFCPClient* addUser(int userId, BFCPClient *client);

private:
    BFCPClientMananger* _bfcpClientManager;
};

#endif