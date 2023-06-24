#ifndef TILE_H
#define TILE_H

#include <string>
using namespace std;

class Active;
class Passive;
class Character;

class Tile{
protected:
    string texture;
    Character* character;
    int row=0, col=0; //need to be 0 for fight results to happen properly
public:
    Tile(const int& , const int&);
    Tile(const int& , const int& ,const string&);
    bool hasCharacter()const;
    //move methods
    bool moveTo(Tile* , Character* );
    virtual Tile* onEnter(Tile* , Character* )=0; //= abstract class
    virtual Tile* onLeave(Tile* , Character* );
    //getters
    int getRow()const {return this->row;}
    int getCol(){return this->col;}
    Character* getCharacter() const{ return this->character;}
    void setCharacter(Character* );
    string getTexture()const ;
    bool fightResult(Tile* , Tile*);
    virtual ~Tile();
};

#endif






