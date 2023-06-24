#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include "AbstractUI.h"
#include "AbstractController.h"
#include <vector>
#include <QPushButton>
#include <array>
#include <QPixmap>

using std::vector;
using std::array;

class MainWindow;
class Dialog;
class Level;
class DungeonCrawler;

class GraphicalUI: public AbstractUI , public AbstractController //kina AC bata pani
{
private:
    MainWindow* main_game;
    Dialog* start_screen;
    Level* ActualLevel;
    array<array<QPixmap*, 3>, 5> characterTextures;
    array<QPixmap*, 5> floorTextures;
    array<QPixmap*, 4> portalTextures;
    array<QPixmap*, 2> doorTextures;
    array<QPixmap*, 2> zombieTextures;
    QPixmap* WallTexture;
    QPixmap* SwitchTexture;
    QPixmap* PitTexture;
    QPixmap* RampTexture;
    //QPixmap* welcome_screen;
    QPixmap* FrameTexture;
    DungeonCrawler* dpt;
    QPixmap* loot_chest;
public:
    GraphicalUI()=default;
    GraphicalUI(Level* level=nullptr );
    void draw(Level*) override ;
    int move() override;
    void switchWindow();
    void setBloodyFrame();
    void setArrowsPixmap();
    void setCharacterPixmap();
    void setFloorPixmap();
    void setPortalPixmap();
    void setOtherPixmap();
    void winEvent() override;
    void deathEvent() override;
    QPixmap* welcome_screen;
    QPixmap* start_button;
   // array<QIcon*, 9> arrowTextures;
    array<QPixmap*, 9> arrowTextures;
    Level* getActualLevel( )const;
    void setActualLevel(Level* );
    virtual ~GraphicalUI();
};


#endif
