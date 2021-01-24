//#include "BFCPClientManager.h"
#include "Log.h"
#include "ConferenceManager.h"
#include "BFCPConference.h"

ConferenceMap ConferenceManager::_conferenceMap;

ConferenceManager::ConferenceManager()
{

}

BFCPConference* ConferenceManager::addConf(int confId)
{
    BFCPConference *conf = new BFCPConference;
    conf->setBfcpClientManager(new BFCPClientMananger);
    _conferenceMap.insert({confId, conf});
    LOG("Enter size:%d", (int)_conferenceMap.size());
    return conf;
}

BFCPConference* ConferenceManager::findConf(int confId)
{
    LOG("Enter size:%d", (int)_conferenceMap.size());

    ConferenceMap::iterator iter = _conferenceMap.find(confId);
    if (iter != _conferenceMap.end())
    {
        LOG("Enter");
        return iter->second;
    }    

    //return _conferenceMap[confId];
}

#if 0
int ConferenceManager::addUser(int userId, BFCPClient *client)
{
    _conferenceMap.insert({userId, client});
}

bool ConferenceManager::findUser(int userId)
{
    BFCPClient* client = _conferenceMap.find(userId);
    return client ? true : false;
}
#endif
    