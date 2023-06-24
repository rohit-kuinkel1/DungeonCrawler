#include "NPC.h"
#include "AbstractController.h"

NPC::NPC(AbstractController* acptr,const int& stamina,const int& strength,const bool& isPerson)
    :Character("n",stamina,strength,false,acptr),controller(acptr)
{}

int NPC::getMove()
{
    return controller->move();
}
