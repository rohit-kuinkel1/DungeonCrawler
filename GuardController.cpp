#include "GuardController.h"
#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

GuardController::GuardController()
{}

int GuardController::move()
{
   int direction= rand()%10; //0-9
   if(direction==0)
      return direction+3;
    else
      return direction;

   //return 5;
}




























//FOR THE NPCs THAT ARE IN LEVEL NPC CONTAINER
    //string direction = "123456789";

    /*
    if (x >= int(direction.size() ))
	{
		x = rand()%9;
	}

    for (size_t i = 0; i < currentLevel->getNpcContainer().size(); i++)
	{
        Character* npc1 = this->currentLevel->getNpcContainer().at(i);
        Tile* t = currentLevel->getNpcContainer().at(i)->getTile();
		int row1 = t->getRow();
		int col1 = t->getCol();

		char c = direction.at(x);
		switch (c)
		{
		case '1':
		{
			row1++;
			col1--;
			break;
		}
		case '2':
		{
			row1++;
			break;
		}
		case '3':
		{
			row1++;
			col1++;
			break;
		}
		case '4':
		{
			--col1;
			break;
		}
		case '5':
		{
            //aptr->draw(currentLevel);
			break;
		}
		case '6':
		{
			col1++;
			break;
		}
		case '7':
		{
			row1--;
			col1--;
			break;
		}
		case '8':
		{
			row1--;
			break;
		}
		case '9':
		{
			row1--;
			col1++;
			break;
		}
		default:
		{
            //aptr->draw(currentLevel);
			break;
		}
		}
		if (row1 > currentLevel->getWidth() || col1 > currentLevel->getHeight() || row1 < 0 || col1 < 0
            || !(t->moveTo(currentLevel->getTileContainer()[row1][col1], npc1)))
		{
			cout << "NPC movement failed" << endl;

		}

        t->moveTo(currentLevel->getTileContainer()[row1][col1], npc1);
	}
	cout << "The NPC made this turn: " << ++x << endl;
	int inc = rand() % 10;
	x = x + inc;
*/









