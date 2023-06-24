#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Tile;
class AbstractController;

class Character
{
protected:
    string texture;
    int moveDirection;
    Tile* currentTile=nullptr;
    AbstractController* controller=nullptr;
    int strength;
    int stamina;
    int HP;
    bool isPlayer=false;
public:
    Character();
    explicit Character(const string& ,const int& , const int& ,const bool& , AbstractController* );
    const string getTexture() const{return this->texture;}
    Tile* getTile()const;
    void setTile(Tile* );
    //getters and setters
    virtual int getMove();
    void setHP(const int&);
    AbstractController* getController();
    int getMoveDirection();
    int getMaxHP()const;
    int getStamina()const;
    int getStrength()const;
    void setStamina(const int& s){stamina=s;}
    void setStrength(const int& s1){strength=s1;}
    virtual ~Character();
    int getHP() const;
    bool isPlayable()const;

};

#endif
