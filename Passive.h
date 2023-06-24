#ifndef PASSIVE_H
#define PASSIVE_H
class Active;

class Passive{
public:
    Passive()=default;
    virtual void notify(Active*) = 0;
};

#endif
