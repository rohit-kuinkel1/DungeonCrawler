#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "AbstractController.h"
#include "AbstractUI.h"
#include "DungeonCrawler.h"

class TerminalUI: public AbstractUI, public AbstractController
{
protected:
    Level* ActualLevel;
public:
    TerminalUI()=default;
    TerminalUI(Level*);
    void draw(Level*) override;
    void winEvent()override;
    void deathEvent()override;
    DungeonCrawler* dptr=nullptr;
    int move() override;
};

#endif











