#ifndef DOOR_H
#define DOOR_H
#include "Tiles.h"
#include "Passive.h"

class Door : public Tile, public Passive
{
protected:
    bool isDoorOpen=false;
public:
    Door(const int& row=0 ,const int& column=0);
    Tile* onEnter(Tile* , Character* ) override;
    void notify(Active* ) override;
    bool isOpen();
    void changeDoorState();
  //  ~Door();
};

#endif
