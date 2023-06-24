#ifndef Npc_h
#define Npc_h
#include "Character.h"
#include <string>

using namespace std;
class AbstractController;

class NPC :public Character
{
protected:
	AbstractController* controller = nullptr;
public:
    NPC(AbstractController* ,const int&, const int&,const bool&);
	AbstractController* getController()const { return controller; }
    int getMove() override;
};

#endif
