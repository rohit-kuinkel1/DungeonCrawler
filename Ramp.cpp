#include "Ramp.h"

Ramp::Ramp(const int& row,const int& col)
    : Tile(row, col,"<")
{}

Tile* Ramp::onEnter(Tile *fromTile, Character *who)
{
    Tile::onEnter(fromTile,who);
    return this;
}

