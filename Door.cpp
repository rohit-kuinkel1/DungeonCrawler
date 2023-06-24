#include "Door.h"
#include "Active.h"

Door::Door(const int& row,const int& col)
    : Tile(row,col,"X"), Passive()
{}

void Door::notify(Active* source)
{
    changeDoorState();
    //source->attach(this);
}

bool Door::isOpen()
{
    return isDoorOpen;
}

Tile* Door::onEnter(Tile* fromTile, Character* who)
{
    Tile::onEnter(fromTile,who);
    if( isOpen() )
        return this;
    else
        return nullptr;
}

void Door::changeDoorState()
{
    if( isOpen() )
    {
     isDoorOpen=false;
     texture="X";
    }
    else
    {
     texture="/";
     isDoorOpen=true;
    }
}




