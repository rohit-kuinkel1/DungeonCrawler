#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

class Level;

class AbstractUI{
public:
    AbstractUI()=default;
    virtual void draw(Level* level) = 0;
    virtual void winEvent()=0;
    virtual void deathEvent()=0;
   // ~AbstractUI();
};

#endif
