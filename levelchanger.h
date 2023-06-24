#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include "Tiles.h"
#include "Active.h"

class Level;

class Levelchanger : public Tile, public Active
{
protected:
    Level* nextLevel=nullptr; //if you are in level1, nextLevel is level2
    int newRow=1,newCol=1;
public:
    Levelchanger(const int& row =1,const int& col =1);
    void activate() override;
    Tile* onEnter(Tile* fromTile, Character* who) override;
    //getters and setters
    void setNextLevel(Level* level);
    void setNewCordinates(int row, int col);
    Level* getNextLevel();
    int getNewRow();
    int getNewCol();    

};

#endif



