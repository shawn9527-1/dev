#ifndef __CONFERENCE_MANAGER_H__
#define __CONFERENCE_MANAGER_H__

#include <unordered_map>
//#include "BFCPConference.h"
//#include "BFCPClient.h"

class BFCPConference;

typedef std::unordered_map<int, BFCPConference*> ConferenceMap;

class ConferenceManager
{
public:    

    ConferenceManager();

    BFCPConference* addConf(int confId);
    static BFCPConference* findConf(int confId);
    //int addUser(int userId, BFCPClient *client);
    //bool findUser(int userId);

private:
    static ConferenceMap _conferenceMap;
};

#endif