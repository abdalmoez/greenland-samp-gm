#include <sampgdk/a_players.h>
#include <sampgdk/a_samp.h>
#include <sampgdk/core.h>

#include "Gamemode.h"

Gamemode gm_GreenLand;

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid)
{
    return gm_GreenLand.OnPlayerConnect(playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDisconnect(int playerid, int reason)
{
    return gm_GreenLand.OnPlayerDisconnect(playerid, reason);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerCommandText(int playerid, const char *cmdtext)
{
    return gm_GreenLand.OnPlayerCommandText(playerid, cmdtext);
}


PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) 
{
    return gm_GreenLand.OnLoad(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    gm_GreenLand.OnUnload();
}
