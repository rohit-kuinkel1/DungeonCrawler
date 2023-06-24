#ifndef PIT_H
#define PIT_H
#include "Tiles.h"

class Pit: public Tile
{
public:
    Pit(const int& , const int&);
    Tile* onEnter(Tile *fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif
