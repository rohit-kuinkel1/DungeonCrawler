#ifndef ACTIVE_H
#define ACTIVE_H

#include <vector>
using namespace std;
class Passive;

class Active
{
protected:
    vector<Passive*> PassiveContainer;
public:
    Active()=default;
    void attach(Passive* );
    void dettach(Passive* );
    virtual void activate();
    vector<Passive*> getPassiveContainer();
    virtual ~Active();
};

#endif
