#ifndef WALL_H
#define WALL_H

#include "Tiles.h"

class Wall : public Tile
{
public:
    Wall(const int& , const int&);
    Tile* onEnter(Tile* fromTile, Character* who) override;
};

#endif


