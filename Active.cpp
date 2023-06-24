#include "Active.h"
#include "Passive.h"
#include <algorithm>
using namespace std;

void Active::attach(Passive* toAttach)
{
    auto it=std::find(PassiveContainer.begin(),PassiveContainer.end(),toAttach);
    if( it==PassiveContainer.end() ) //if iterator reaches the end, item wasnt there
    {
        PassiveContainer.push_back(toAttach);
    }
}

void Active::dettach(Passive* toDettach)
{
    auto it=std::find(PassiveContainer.begin(),PassiveContainer.end(),toDettach);
    if( it!=PassiveContainer.end() ) //if it is not at the end then item is found
      PassiveContainer.erase(it);
}

void Active::activate()
{
    for(Passive* p : PassiveContainer)
    {
        p->notify(this);
    }
}

vector<Passive*> Active::getPassiveContainer()
{
    return PassiveContainer;
}

Active::~Active()
{

}
