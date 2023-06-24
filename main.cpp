#include "Character.h"
#include "GuardController.h"
#include "Level.h"
#include "DungeonCrawler.h"
#include "NPC.h"
#include "graphicalui.h"
#include "levelchanger.h"
#include <QApplication>
#include <QtTest/QTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Level* l1 =new Level(20,16);
    l1->placePortals(7,7,14,14,1);
    l1->placePortals(1,1,18,14,2);
    l1->placePortals(1,14,18,1,0);
    l1->placeChest(8,10);
    l1->placeDoorAndSwitch(10,10,11,9);

    Level* l2=new Level(20,16);
    l2->placePortals(4,4,16,16,0);
    l2->placePortals(1,12,13,1,1);
    l2->placeDoorAndSwitch(10,10,11,9);
    l2->placeChest(11,12);

    l1->placeLevelChanger(15,10,12,15,l2); //place a Tile of type LC in l1 and l2 to connect

    Levelchanger* lc1=dynamic_cast<Levelchanger*>(l1->getTile(15,10));
    Levelchanger* lc2=dynamic_cast<Levelchanger*>(l2->getTile(12,15));

    //lc1->connectLevelChangers(lc2);

//------------------------------------MAIN LOGIC---------------------------------------------------------------

    GraphicalUI* gui = new GraphicalUI(l1);
    DungeonCrawler* dpt= new DungeonCrawler(gui,l1);

    AbstractController* a1=new GuardController(); //for NPC

    Character* c= new Character ("c",220,110,true,gui);
    Character* n1= new NPC(a1,100,100,false);
    Character* n2= new NPC(a1,100,100,false);
    Character* n3= new NPC(a1,20,20,false);
    Character* n4= new NPC(a1,1000,1000,false);

    l1->placeCharacter(c,6,6);
    l1->placeCharacter(n1,7,14);
    l1->placeCharacter(n2,3,14);

    l2->placeCharacter(n3,15,13);
    l2->placeCharacter(n4,9,10);

    lc1->attach(dpt); //push dpt back into lc1s passiveContainer
    lc2->attach(dpt); //push dpt back into lc2s passiveContainer

    dpt->addLevel(l1); //push_back l1 into the List object we created for DC.
    dpt->addLevel(l2); //push_back l1 into the List object we created for DC.

    dpt->turn();

    delete dpt;
    delete gui;
    delete c;
    delete n1;
    delete n2;
    delete a1;
    delete l1;
    delete l2;
    delete lc1;
    delete lc2;

  return a.exec();
}


