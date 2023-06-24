#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

#include "Passive.h"
#include "graphicalui.h"
#include "mylist.h"
#include <array>
using namespace std;

class AbstractUI;
class Level;

class DungeonCrawler:public Passive
{
protected:
    AbstractUI* aptr=nullptr;
    Level* ActualLevel=nullptr;
    List levels;  // similar to vector<Level*> levelContainer

public:
    DungeonCrawler(AbstractUI* aptr=nullptr, Level* ActualLevel=nullptr);
    void turn(const int& movingDir=0);
    void newCordinates(const int&);
    void setActualLevel(Level* );
    std::array<int, 2> getCordinates(const int& );
    void notify(Active* source) override;
    void addLevel(Level* l);
    virtual ~DungeonCrawler();
    //copy constructor for char from the level is missing , they need to be saved in dungeon crawler
};

#endif
