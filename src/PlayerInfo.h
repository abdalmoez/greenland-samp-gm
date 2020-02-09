#pragma once

#include <cstring>
#include <iostream>
#include <vector>
#include <map>

#include <sampgdk/a_players.h>
#include <sampgdk/a_samp.h>
#include <sampgdk/core.h>

#include "GreenLandCore/PlayerInfo_Base.h"


using namespace GreenLand;

class PlayerInfo: public PlayerInfo_Base{
    public:
        void setPosition(const Position& position)
        {
            PlayerInfo_Base::setPosition(position);
            SetPlayerPos(m_uid, position.getX(), position.getY(), position.getZ());
            SetPlayerInterior(m_uid, position.getInterior());
            SetPlayerVirtualWorld(m_uid, position.getWorld()); 
        }

        void setHP(const uint64_t health)
        {
            PlayerInfo_Base::setHP(health);
            SetPlayerHealth(m_uid, health);
        }
};
