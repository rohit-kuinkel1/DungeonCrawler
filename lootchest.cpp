#include "lootchest.h"
#include "Character.h"
#include "qtestsupport_core.h"
#include <QDebug>

Lootchest::Lootchest(const int& row,const int& col)
    : Tile(row, col,"LC")
{}

Tile *Lootchest::onEnter(Tile *fromTile, Character *who)
{
    Tile::onEnter(fromTile, who);
}

