#include "DungeonCrawler.h"
#include "AbstractUI.h"
#include "Active.h"
#include "Level.h"
#include "Character.h"
#include "Tiles.h"
#include "levelchanger.h"
#include "graphicalui.h"
#include "lootchest.h"

#include <QDebug>
#include <iostream>
using namespace std;

DungeonCrawler::DungeonCrawler(AbstractUI* aptr,Level* level)
    : aptr(aptr),ActualLevel(level)
{}

void DungeonCrawler::notify(Active *source)
{
    Levelchanger* LevelChanger = dynamic_cast<Levelchanger*>(source);
    Level* tmpLevel            = LevelChanger->getNextLevel();

    for(List::Iterator it = levels.begin(); it != levels.end(); ++it)
    {
        if( *(it) == tmpLevel) //if the nextLevel of LC is inside of our List container
        {
            Character* who = LevelChanger->getCharacter(); // get the character that was standing on LC

            int newRow = LevelChanger->getNewRow(); //newRow = the row for char in another Level
            int newCol = LevelChanger->getNewCol(); //newCol= the col for char in another level

            tmpLevel->placeCharacter(who,newRow,newCol);

            int currentRow = LevelChanger->getRow(); //Tile::getRow() for LevelChanger
            int currentCol = LevelChanger->getCol(); //Tile::getCol() for LevelChanger

            ActualLevel->getTile(currentRow,currentCol)->setCharacter(nullptr); //remove the char from the old Tile

            ActualLevel = tmpLevel;
            qInfo()<<"Level changed ! ! !"; //now that everything is moved, set the ActualLevel as the prev tmplevel

            dynamic_cast<GraphicalUI*>(aptr)->setActualLevel( ActualLevel );
            tmpLevel->getCharContainer().push_back(who);
            aptr->draw(ActualLevel);
            break;
        }

    }
}

void DungeonCrawler::turn(const int& movingDir)
{
   aptr->draw(ActualLevel);
   while(true)
    {
        for(size_t i=0; i<ActualLevel->getCharContainer().size(); i++ ) //for all the Characters in charContainer
        {

            Character* character=ActualLevel->getCharContainer()[i];           
            while(true)
            {              
                int movingDir = character->getMove(); //gets move from the controller of the char
                array<int,2> cordinates = getCordinates(movingDir); //this line takes in cordinates from the GUI and then determines the Row and Col where the char will be moved to

                int row=0,col=0;
                row = character->getTile()->getRow()+cordinates[0]; //set the new row
                col = character->getTile()->getCol()+cordinates[1]; //set the new col

                if( (row < 0) || (row >= ActualLevel->getHeight()) || (col < 0) || (col >= ActualLevel->getWidth() ) )
                {
                    cout << "Cant go out of Level, try again ! ! !";
                    continue;
                }

                Tile* currentTile = character->getTile();
                Tile* destTile  = ActualLevel->getTile(currentTile->getRow()+cordinates[0], currentTile->getCol()+cordinates[1]); //mathi ko row ra col lekhna milxa ?

                bool isMovementPossible = true;
                isMovementPossible=currentTile->moveTo(destTile, character); //iMP will be false if nullptr else true
                ActualLevel->removeIfDead();

                bool allPlayersAreDead = true;
                for( Character* player : ActualLevel->getCharContainer() )
                {
                    if( player->isPlayable() )
                    {
                        allPlayersAreDead = false;
                      //  break;
                    }
                }

                if(allPlayersAreDead)
                {
                    ActualLevel->removeIfDead();
                    aptr->deathEvent();
                }

                if(typeid(*destTile)== typeid(Lootchest) && character->isPlayable())
                    aptr->winEvent();

                if(!isMovementPossible)               
                    cout << "Cant go there, try again ! ! !";

                aptr->draw(ActualLevel);
                break;             
            }
        }
    }
}

array<int, 2> DungeonCrawler::getCordinates(const int& movingDir)
{
    enum {row=0, col=1};
    array<int, 2> coordinates = {0,0}; //(row,col)=(0,0)
    switch(movingDir)
    {
        case 1:
        {
            coordinates[row] += 1; // row=row+1
            coordinates[col] -= 1; // col=col-1
            break;
        }
        case 2:
        {
            coordinates[row] += 1;
            break;
        }
        case 3:
        {
            coordinates[row] += 1;
            coordinates[col] += 1;
            break;
        }
        case 4:
        {
            coordinates[col] -= 1;
            break;
        }
        case 5: break;
        case 6:
        {
            coordinates[col] += 1;
            break;
        }
        case 7:
        {
            coordinates[row] -= 1;
            coordinates[col] -= 1;
            break;
        }
        case 8:
        {
            coordinates[row] -= 1;
            break;
        }
        case 9:
        {
            coordinates[row] -= 1;
            coordinates[col] += 1;
            break;
        }
        default:
        {
            break;
        }
    }
  return coordinates;
}

void DungeonCrawler::setActualLevel(Level* level)
{
    ActualLevel = level;
}

void DungeonCrawler::addLevel(Level *level)
{
    levels.push_back(level); // List::push_back
}

DungeonCrawler::~DungeonCrawler()
{}

