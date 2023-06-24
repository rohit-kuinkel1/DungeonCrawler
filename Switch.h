#ifndef SWITCH_H
#define SWITCH_H

#include "Tiles.h"
#include "Active.h"

class Switch : public Tile, public Active
{
public:
    Switch(const int& ,const int& );
    Tile* onEnter(Tile* ,Character*) override;
   // void activate()override;
};

#endif
