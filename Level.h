#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
using namespace std;
class Tile;
class Character;

class Level
{
protected:
    int height=0, width=0;
    vector<Character*> charContainer;
    vector<vector<Tile*>>tileContainer;
    vector<Character*> npcContainer;
public:
    Level(const int& ,const int& );
    ~Level();
    Tile* getTile(const int& ,const int& );
    Tile* getTile(const int& ,const int& ) const;
    void placeCharacter(Character* ,const int& ,const int& );
    void defineLevel(const int& width, const int& height);
    void placeLevelChanger(const int& x1, const int& y1, const int& x2, const int& y2,Level* l1);
    vector<vector<Tile*>> getTileContainer()const {return tileContainer;}
    vector<Character*> getCharContainer() const;
    vector<Character*> getNpcContainer()const;
    int getHeight() const;
    int getWidth() const;
    void removeIfDead();
    void setTile(const int& x1,const int& y1, Tile* toBeSet);
    void placePortals(const int &x1, const int &y1, const int &x2, const int &y2,const int& portalType);
    void placeDoorAndSwitch(const int&,const int&,const int&,const int&);
    void placeChest(const int&,const int&);
};


#endif
