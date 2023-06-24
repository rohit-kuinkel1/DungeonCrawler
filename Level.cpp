#include <array>
#include "Level.h"
#include "Tiles.h"
#include "Portal.h"
#include "Floor.h"
#include "Wall.h"
#include "Character.h"
#include "Switch.h"
#include "Door.h"
#include "Ramp.h"
#include "Pit.h"
#include "levelchanger.h"
#include "lootchest.h"
#include <typeinfo>

Level::Level(const int& height,const int& width): height(height), width(width)
{
    tileContainer.resize(height,vector<Tile*>(width)); //height * vector of Tiles which contain width Tiles initialised with null

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if( (i == 0) || (i == height-1) || (j == 0) || (j==width-1) )
            { //fill the borders with wall
                tileContainer[i][j] = new Wall(i,j);
            }
            else if ((i==height-4 && j<width/2)||(j==width/2) || (i==height/2))
            {
                tileContainer[i][j] = new Wall(i,j);
            }
            else if ((i==5 && j==5) || (i==5&&j==6))
            {
                tileContainer[i][j] = new Pit(i,j);
            }
            else if ((i==5 && j==4) || (i==5&&j==8) )
            {
                tileContainer[i][j] = new Ramp(i,j);
            }        
            else
            {
                tileContainer[i][j]=new Floor(i,j);
            }
        }
    }
}

Level::~Level()
{
    for(int i = 0; i <  height; i++){
            for(int j = 0; j < width; j++){
                delete tileContainer[i][j];
            }
        }

}

void Level::placeCharacter(Character* c,const int& row,const int& col)
{
    c->setTile(tileContainer[row][col]);
    tileContainer[row][col]->setCharacter(c);
    charContainer.push_back(c);
}

void Level::placePortals(const int& x1, const int& y1, const int& x2, const int& y2,const int& portalType)
{
    Portal* p1= new Portal(x1,y1,portalType);
    Portal* p2= new Portal(x2,y2,portalType);

    p1->setDestination(p2);
    p2->setDestination(p1);

    tileContainer[x1][y1]=nullptr;
    tileContainer[x1][y1]=nullptr;

    tileContainer[x1][y1]=p1;
    tileContainer[x2][y2]=p2;

}

void Level::placeDoorAndSwitch(const int &x1, const int &y1, const int &x2, const int &y2)
{
    Door*d1  = new Door(x1,y1);
    Switch*s1= new Switch(x2,y2);
    s1->attach(d1);
    //the onEnter from Switch opens the door.

    tileContainer[x1][y1]=nullptr; //do delete
    tileContainer[x1][y1]=nullptr;

    tileContainer[x1][y1]=d1;
    tileContainer[x2][y2]=s1;
}

void Level::placeChest(const int& x1, const int& y1)
{
    Lootchest* loot= new Lootchest(x1,y1);
    tileContainer[x1][y1]=nullptr;
    tileContainer[x1][y1]=loot;
}


void Level::placeLevelChanger(const int& x1, const int& y1, const int &x2, const int &y2, Level* l1)
{
    tileContainer.at(x1).at(y1)=nullptr; 
    l1->getTileContainer().at(x2).at(y2)=nullptr;

    Levelchanger* lc1= new Levelchanger(x1,y1); //row and col of this lc is x1 and y1
    this->setTile(x1,y1,lc1);
    lc1->setNextLevel(l1);

    Levelchanger* lc2= new Levelchanger(x2,y2);
    l1->setTile(x2,y2,lc2);
    lc2->setNextLevel(this);

    lc1->setNewCordinates(x2,y2); //char from lc1 should go to this cordinate in level2
    lc2->setNewCordinates(x1,y1); //char from lc2 should go to this cordinate in level1
}

int Level::getHeight() const{
   return height;
}

int Level::getWidth() const{
    return width;
}

void Level::removeIfDead()
{
    for(size_t i=0; i<charContainer.size();i++)
    {
        if(charContainer.at(i)->getTile()==nullptr)
            charContainer.erase(charContainer.begin()+i);
    }
}

void Level::setTile(const int &x1, const int &y1, Tile *toBeSet)
{
    //delete tileContainer[x1][y1];
    tileContainer[x1][y1]=toBeSet;
}

Tile* Level::getTile(const int& row,const int& col){
    return tileContainer[row][col];
}

Tile* Level::getTile(const int& row,const int& col) const{
    return tileContainer[row][col];
}

vector<Character*> Level::getCharContainer() const{
    return charContainer;
}

vector<Character *> Level::getNpcContainer() const
{
    return this->npcContainer;
}

