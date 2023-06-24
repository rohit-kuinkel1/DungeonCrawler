#include "Tiles.h"
#include "Character.h"
#include <QDebug>

Tile::Tile(const int& row, const int& col)
    : texture(""), character(nullptr),row(row), col(col)
{}

Tile::Tile(const int& row, const int& col,const string& texture)
    : texture(texture), character(nullptr), row(row), col(col)
{}

bool Tile::hasCharacter() const
{
    if(this->character!=nullptr)
        return true;
    else
        return false;
}

string Tile::getTexture()const
{
    if( hasCharacter() )
        return character->getTexture();
    else
        return this->getTexture();
}

bool Tile::fightResult(Tile* fromTile, Tile* destTile)
{
    Character* attacker  = fromTile->getCharacter();
    Character* defendant = destTile->getCharacter();

    if( (defendant->getHP() - attacker->getStrength() ) >= 1 ) //if  defender alive
    {
        qInfo()<<"Defender is alive!";
        defendant->setHP( defendant->getHP() - attacker->getStrength() );
       // return false;

        if( (attacker->getHP() - defendant->getStrength() ) >= 1) //if attacker is alive after defender hit back
        {
            attacker->setHP( attacker->getHP() - defendant->getStrength() );
            return true;
        }
        else if( (attacker->getHP() - defendant->getStrength()) <= 0) //if attacker died
        {
            qInfo()<<"attacker died!";
            fromTile->setCharacter(nullptr);
            attacker->setTile(nullptr);
            this->setCharacter(defendant);
            return true;
        }
    }
    else //if defender died
    {
        qInfo()<<"Defender is dead ! ! !";
        attacker->setTile(destTile);
        defendant->setTile(nullptr);
        destTile->setCharacter(attacker);
        this->setCharacter(nullptr);

        return true;
    }
    return false;
}

Tile* Tile::onEnter(Tile* fromTile, Character* who)
{
    return this;
}

Tile* Tile::onLeave(Tile* destTile, Character* who)
{
    return this;
}

bool Tile::moveTo(Tile* destTile, Character* who)
{
   if(destTile == this)
       return true;

   if( onLeave(destTile, who) )     //if onLeave can be done succesfully
   {
        if( this->hasCharacter() && destTile->hasCharacter() )
        {
            if( this->getCharacter()->isPlayable() == destTile->getCharacter()->isPlayable() )
            {
                qInfo()<<" No fight between these characters ! ! !";
                return false;      //no fight betwn P&P and NPC&NPC
            }
            else
            {
                fightResult(this,destTile);
            }
        }
   }

  Tile* destination = destTile->onEnter(this, who); //result should be saved acc. to the question
   if(destination != nullptr)
   {
       destination->setCharacter(character);
       character->setTile(destination);
       this->character=nullptr;
       return true;
   }

 return false;
}


void Tile::setCharacter(Character* who)
{
    this->character = who;
}

Tile::~Tile()
{
}



