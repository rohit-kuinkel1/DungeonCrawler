#ifndef PORTAL_H
#define PORTAL_H
#include "Tiles.h"

class Portal : public Tile{
protected:
    Tile* destination=nullptr;
    int portalType=0;
public:
    Portal(const int& ,const int& ,const int& PortalType = 0);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    //getters and setters
    Tile* getDestination()const;
    int getPortalType()const;
    void setDestination(Tile* );
};

#endif
