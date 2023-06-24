#include "Character.h"
#include "AbstractController.h"

Character::Character()
{}

Character::Character(const string& texture,const int& strength,const int& stamina,const bool& isPerson,AbstractController* aptr)
    : texture(texture), currentTile(nullptr), controller(aptr),strength(strength),stamina(stamina),isPlayer(isPerson)
{
    this->HP=getMaxHP();
}

void Character::setTile(Tile* dest)
{
    currentTile = dest;
}

int Character::getMove()
{
    moveDirection=controller->move();
    return moveDirection;
}

void Character::setHP(const int & newHP)
{
    this->HP=0;
    this->HP=newHP;
}

int Character::getMoveDirection()
{
    return moveDirection;
}

int Character::getMaxHP() const
{
    int maxHP=20+(this->stamina*5);
    return maxHP;
}

int Character::getStamina() const
{
    return this->stamina;
}

int Character::getStrength() const
{
    return this->strength;
}

int Character::getHP()const
{
    return this->HP;
}

bool Character::isPlayable() const
{
    return isPlayer;
}

Tile* Character::getTile()const
{
    return this->currentTile;
}

AbstractController* Character::getController()
{
    return this->controller;
}

Character::~Character()
{}



