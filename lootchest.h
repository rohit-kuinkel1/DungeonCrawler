#ifndef LOOTCHEST_H
#define LOOTCHEST_H

#include "Tiles.h"
#include <QMessageBox>

class Lootchest: public Tile
{
public:
    Lootchest();
    Lootchest(const int& row=0,const int& col=0);
    Tile* onEnter(Tile* fromTile, Character* who) override;
   // ~Lootchest();
};

#endif

