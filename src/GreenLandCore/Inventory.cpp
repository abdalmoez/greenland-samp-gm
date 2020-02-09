#include "Inventory.h"

bool GreenLand::Inventory::addObject(InventoryObject object)
{
    if(m_objects.size() + 1 > m_limit)
    {
        return false;
    }

    m_objects.push_back(object);
    return true;
}

bool GreenLand::Inventory::addObjects(std::vector<InventoryObject> objects)
{
    if( m_objects.size() + objects.size() > m_limit)
    {
        return false;
    }

    m_objects.insert(m_objects.end(), objects.begin(), objects.end());
    return true;
}

bool GreenLand::Inventory::contains(InventoryObjectType object_type)
{
    for (std::vector<InventoryObject>::iterator it = m_objects.begin() ; it != m_objects.end(); ++it)
    {   
        if(it->isOfType(object_type))
        {
            return true;
        }
    }
    return false;
}