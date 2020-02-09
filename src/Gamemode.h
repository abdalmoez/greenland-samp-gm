#pragma once
#include <map>
#include <cstring>
#include <iostream>

#include "PlayerInfo.h"

#define MAX_PLAYER_NAME 24
#define MAX_PLAYERS 1000
class Gamemode {
    private:
    std::map<uint64_t, PlayerInfo> m_players;
    public:
    bool OnPlayerConnect(int playerid)
    {
        m_players[playerid] = PlayerInfo();
        return true;
    }

    bool OnPlayerDisconnect(int playerid, int reason)
    {
        m_players.erase(m_players.find(playerid));
        return true;
    }

    bool OnPlayerCommandText(int playerid, const char *cmdtext)
    {
        if (strcmp(cmdtext, "/hello") == 0) 
        {
            char name[MAX_PLAYER_NAME];
            GetPlayerName(playerid, name, sizeof(name));
            char message[255];
            sprintf(message, "Hello, %s!", name);
            SendClientMessage(playerid, 0x00FF00FF, message);
            return true;
        }
        if (strcmp(cmdtext, "/kill") == 0) 
        {
            m_players[playerid].setHP(0);
            SendClientMessage(playerid, 0x00FF00FF, "You are a dead man!");            
            return true;
        }
        if (strcmp(cmdtext, "/armor") == 0) 
        {
            m_players[playerid].setArmor(100);
            SendClientMessage(playerid, 0x00FF00FF, "You got your an armor!");         
            return true;
        }
        if (strcmp(cmdtext, "/hp") == 0) 
        {
            m_players[playerid].setHP(100);
            SendClientMessage(playerid, 0x00FF00FF, "You are revived!");         
            return true;
        }
        return false;
    }
    
    bool OnLoad(void **ppdata)
    {
        return true;
    }

    void OnUnload()
    {
        
    }
};
