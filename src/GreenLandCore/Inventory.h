#pragma once

#include <iostream>
#include <vector>

namespace GreenLand {
enum InventoryObjectType{
    WP_MP4
};
class InventoryObject{
    private:
        InventoryObjectType m_objectType;
        uint64_t            m_quantity;
    public:
        InventoryObject(InventoryObjectType object, uint64_t quantity):
            m_objectType(object),
            m_quantity(quantity)
        {}

        uint64_t getQuantity()                                 { return m_quantity; }
        void setQuantity(uint64_t quantity)                    { m_quantity = quantity; }
        
        InventoryObjectType getType()                          { return m_objectType; }
        void setType(InventoryObjectType object)               { m_objectType = object; }
        
        bool isOfType(const InventoryObjectType &object_type) const
        {
            return (m_objectType == object_type);
        }
};

class Inventory {
    public:
        Inventory(uint64_t limit) : 
            m_objects(),
            m_limit(limit)
        {}
        
        bool addObject(InventoryObject object);

        bool addObjects(std::vector<InventoryObject> objects);

        bool contains(InventoryObjectType object_type);

        InventoryObject& at(uint64_t index) { return m_objects.at(index); }
    private:
        std::vector<InventoryObject> m_objects;
        uint64_t                     m_limit;
};
}
