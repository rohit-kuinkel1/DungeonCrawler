#include "Wall.h"

Wall::Wall(const int& row, const int& col)
    : Tile(row, col,"#")
{}

Tile* Wall::onEnter(Tile* fromTile, Character* who)
{
    return nullptr;
}
