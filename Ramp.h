#ifndef RAMP_H
#define RAMP_H
#include "Tiles.h"

class Ramp : public Tile
{
public:
    Ramp(const int& , const int&);
    Tile* onEnter(Tile* , Character*) override;
};

#endif
