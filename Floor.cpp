#include "Floor.h"

Floor::Floor(const int& row,const int& col)
    : Tile(row, col,".")
{}

Tile* Floor::onEnter(Tile* fromTile, Character* who)
{
    Tile::onEnter(fromTile,who);
    return this;
}

