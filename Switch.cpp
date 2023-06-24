#include "Switch.h"
#include "Active.h"

Switch::Switch(const int& row,const int& col)
    : Tile(row,col,"?"), Active()
{}

Tile* Switch::onEnter(Tile *fromTile, Character *who)
{
    Tile::onEnter(fromTile,who);
    activate();
    return this;
}
