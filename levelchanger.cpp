#include "levelchanger.h"
#include "Character.h"
#include "Level.h"
#include "Passive.h"

Levelchanger::Levelchanger(const int& row,const int& col)
    : Tile(row, col,"L"), Active()
{}

Tile *Levelchanger::onEnter(Tile *fromTile, Character *who) //giving newrow and newcol in constr is better
{
    if(who->isPlayable())
    {
        this->character = who;
        Levelchanger::activate(); //does nth more than notify its passive elements, activate = notify() for passive elements
        character = nullptr;
        return nextLevel->getTile(newRow,newCol);
    }
    else if(!who->isPlayable() )
        return this;
}


void Levelchanger::setNextLevel(Level *level)
{
    nextLevel = level;
}

void Levelchanger::setNewCordinates(int row, int col)
{
    newRow = row;
    newCol = col;
}

Level* Levelchanger::getNextLevel()
{
    return nextLevel;
}

int Levelchanger::getNewRow()
{
    return newRow;
}

int Levelchanger::getNewCol()
{
    return newCol;
}

void Levelchanger::activate()
{
    for(Passive* p : getPassiveContainer() )
    {
        p->notify(this);
    }
}

