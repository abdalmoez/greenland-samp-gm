#pragma once

#include <cstring>
#include <iostream>
#include <map>
#include "Util/Position.h"

using namespace GreenLand::Util;

namespace GreenLand {

class PlayerInfo_Base{
    protected:
        uint64_t    m_uid;
        int64_t     m_pid;
        char        m_username[24];
        int64_t     m_health;
        int64_t     m_armor;
        int64_t     m_cash;
        int64_t     m_bank;
        int64_t     m_wantedLevel;
        int64_t     m_notority;
        Position    m_position;
        uint64_t    m_adminLevel;
        
    public:
        virtual const char*       getUsername() const                             { return m_username; }
        virtual const int64_t     getHP() const                                   { return m_health; }
        virtual const int64_t     getArmor() const                                { return m_armor; }
        virtual const int64_t     getCash() const                                 { return m_cash; }
        virtual const int64_t     getBankCash() const                             { return m_bank; }
        virtual const int64_t     getWantedLevel() const                          { return m_wantedLevel; }
        virtual const int64_t     getNotority() const                             { return m_notority; }
        virtual const Position    getPosition() const                             { return m_position; }
        virtual const int64_t     getAdminLevel() const                           { return m_adminLevel; }
        
        virtual void       setUsername(const char* username)                      { std::strcpy(m_username, username); }
        virtual void       setHP(const uint64_t health)                           { m_health       = health; }
        virtual void       setArmor(const uint64_t armor)                         { m_armor        = armor; }
        virtual void       setCash(const uint64_t cash)                           { m_cash         = cash; }
        virtual void       setBankCash(const uint64_t bank)                       { m_bank         = bank; }
        virtual void       setWantedLevel(const uint64_t wantedLevel)             { m_wantedLevel  = wantedLevel; }
        virtual void       setNotority(const uint64_t notority)                   { m_notority     = notority; }
        virtual void       setPosition(const Position& position)                  { m_position     = position; }
        virtual void       setAdminLevel(const uint64_t adminLevel)               { m_adminLevel   = adminLevel; }

        virtual bool       isAdmin()                           { return (m_adminLevel > 0); }        
        virtual bool       haveCash(int64_t amount)            { return (m_cash >= amount); }
        
};

}