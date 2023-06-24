#ifndef GUARDCONTROLLER_H
#define GUARDCONTROLLER_H

#include <string>
using namespace std;

#include "AbstractController.h"

class Level;
class DungeonCrawler;

class GuardController :public AbstractController
{
protected:
    DungeonCrawler* dptr=nullptr;
    Level* currentLevel=nullptr;
public:
    GuardController();
    int move()override;
};


#endif
