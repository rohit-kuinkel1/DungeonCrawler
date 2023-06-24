#include "Portal.h"
#include "Character.h"

Portal::Portal(const int& row,const int& col,const int& PortalType)
    : Tile(row, col,"0"),portalType(PortalType)
{}

Tile* Portal::onEnter(Tile* fromTile, Character* who)
{
    return this->destination; //entering of this tile= teleporting to its destination
}

Tile* Portal::getDestination()const
{
    return destination;
}

void Portal::setDestination(Tile* PortalDestination)
{
    this->destination=nullptr;
    destination = PortalDestination;
}

int Portal::getPortalType() const
{
    return portalType;
}
