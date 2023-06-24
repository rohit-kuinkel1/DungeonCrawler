#include <typeinfo>
#include "Pit.h"
#include "Ramp.h"

Pit::Pit(const int& row,const int& col)
    : Tile(row, col,"_")
{}

Tile* Pit::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile* Pit::onLeave(Tile* destTile, Character* who) //if destTile isnt a Pit or a Ramp movement not possible
{
    if((typeid(*destTile) == typeid(Ramp)) || (typeid(*destTile) == typeid(Pit)))
        return this;
    else
     return nullptr;
}


