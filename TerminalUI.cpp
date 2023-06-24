#include "TerminalUI.h"
#include "Level.h"
#include "Tiles.h"

#include <iostream>
using namespace std;

TerminalUI::TerminalUI(Level* l1)
    : ActualLevel(l1)
{}

void TerminalUI::draw(Level* level)
{
    for(int h = level->getHeight()-1; h >= 0; h--)
    {
        for(int w = 0; w < level->getWidth(); w++)
        {
          cout <<" "<< level->getTileContainer().at(h).at(w)->getTexture();
        }
        cout << endl;
    }
    this->move();
}

void TerminalUI::winEvent()
{
    cout<<"Congrats , You won this game !!"<<endl;
    exit(0);

}

void TerminalUI::deathEvent()
{
    cout<<"You died to an NPC ..." <<endl;
    this->ActualLevel->removeIfDead();
    exit(0);
}

int TerminalUI::move()
{
    int user_input;
    cin >> user_input;
    if (user_input == 0)
        exit(0);
	
    if(cin.fail() || user_input<=-1 || user_input>=10 )
    {
        cin.clear();
        cin.ignore();
        cout<<"Invalid Input , give a number between 1 and 9, press 0 to exit"<<endl;
        this->draw(ActualLevel);
    }
  return user_input;
}

