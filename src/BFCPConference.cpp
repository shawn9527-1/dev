#include "Log.h"
#include "BFCPConference.h"

BFCPConference::BFCPConference()
{

}

bool BFCPConference::findConf(int confId)
{

}

int BFCPConference::addConf(int confId)
{

}

BFCPClient* BFCPConference::findUser(int userId)
{
    LOG("Enter");
    if (_bfcpClientManager) {
        LOG("Enter");
        return _bfcpClientManager->findByUserId(userId);
    }

    return NULL;
}

BFCPClient* BFCPConference::addUser(int userId, BFCPClient *client)
{
    _bfcpClientManager->add(userId, client);
    return client;
}
