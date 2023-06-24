#ifndef FLOOR_H
#define FLOOR_H

#include "Tiles.h"

class Floor: public Tile{
public:
    Floor();
    Floor(const int& ,const int& );
    Tile* onEnter(Tile* , Character*) override;
    //~Floor();
};

#endif
