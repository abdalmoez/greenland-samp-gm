#pragma once

#include <iostream>

namespace GreenLand {
namespace Util
{
    class Position {
        private:
        int64_t     m_x;
        int64_t     m_y;
        int64_t     m_z;
        int64_t     m_interior;
        int64_t     m_world;

        public:
        int64_t getX() const         { return m_x;}
        int64_t getY() const         { return m_y;}
        int64_t getZ() const         { return m_z;}
        int64_t getInterior() const  { return m_interior;}
        int64_t getWorld() const     { return m_world;}

        void operator= (const Position &position)
        {
            m_x         = position.m_x; 
            m_y         = position.m_y; 
            m_z         = position.m_z; 
            m_interior  = position.m_interior;
            m_world     = position.m_world;   
        }

        bool operator== (const Position &position) const
        {
            return (m_x == position.m_x) && 
                (m_y == position.m_y) && 
                (m_z == position.m_z) && 
                (m_interior == position.m_interior)&& 
                (m_world == position.m_world);
        }

        bool operator!= (const Position &position) const
        {
            return !(*this == position);
        }

        bool nearBy(Position position, uint64_t tolerance, bool check_interior_and_world=true)
        {
            return (abs(m_x - position.m_x) < tolerance) && 
                (abs(m_y - position.m_y) < tolerance) && 
                (abs(m_z - position.m_z) < tolerance) && 
                (m_interior == position.m_interior || !check_interior_and_world)&& 
                (m_world == position.m_world || !check_interior_and_world);
        }

        bool nearBy(int64_t x, int64_t y, int64_t z, uint64_t tolerance)
        {
            return (abs(m_x - x) < tolerance) && 
                (abs(m_y - y) < tolerance) && 
                (abs(m_z - z) < tolerance);
        }

        bool nearBy(int64_t x, int64_t y, int64_t z, uint64_t tolerance_x, uint64_t tolerance_y, uint64_t tolerance_z)
        {
            return (abs(m_x - x) < tolerance_x) && 
                (abs(m_y - y) < tolerance_y) && 
                (abs(m_z - z) < tolerance_z);
        }
        
        bool nearBy(int64_t x, int64_t y, int64_t z, int64_t interior, int64_t world, uint64_t tolerance)
        {
            return (abs(m_x - x) < tolerance) && 
                (abs(m_y - y) < tolerance) && 
                (abs(m_z - z) < tolerance) && 
                (m_interior == interior)&& 
                (m_world == world);
        }

        bool nearBy(int64_t x, int64_t y, int64_t z, int64_t interior, int64_t world,  uint64_t tolerance_x, uint64_t tolerance_y, uint64_t tolerance_z)
        {
            return (abs(m_x - x) < tolerance_x) && 
                (abs(m_y - y) < tolerance_y) && 
                (abs(m_z - z) < tolerance_z) && 
                (m_interior == interior)&& 
                (m_world == world);
        }
    };
} // namespace Util
} // namespace GreenLand