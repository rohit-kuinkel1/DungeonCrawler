#include "graphicalui.h"
#include "NPC.h"
#include "levelchanger.h"
#include "lootchest.h"
#include "ui_mainwindow.h"
#include "Tiles.h"
#include "Floor.h"
#include "Wall.h"
#include "Portal.h"
#include "Switch.h"
#include "Door.h"
#include "Ramp.h"
#include "Pit.h"
#include "Character.h"
#include "mainwindow.h"
#include <random>
#include "welcomescreen.h"
#include "Level.h"
#include <QLabel>
#include <QtTest/QTest>
#include <QMessageBox>

GraphicalUI::GraphicalUI(Level* level)
    : AbstractUI(), AbstractController(), ActualLevel(level)
{
    int width   = ActualLevel->getWidth();
    int height  = ActualLevel->getHeight();

    setOtherPixmap();

    start_screen = new Dialog(this);
    main_game    = new MainWindow(height, width,this);

    auto ui = main_game->getUI();
    ui->label->setStyleSheet("background: transparent;}");

    setArrowsPixmap();
    setBloodyFrame();
    setCharacterPixmap();
    setFloorPixmap();
    //setOtherPixmap();
    setPortalPixmap();

    ui->playerstats->show();
    ui->playerstats->raise();
    ui->playerstats->setStyleSheet("color:white;");

    main_game->setAndConnectButtons();

    //define the pictures for tiles and character
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            QLabel* tmp = new QLabel("", ui->widget);
            Tile* currentTile = ActualLevel->getTile(i,j);

            if(currentTile->hasCharacter())
            {
                QLabel* tmpCharacter = new QLabel("", ui->gridLayout->itemAtPosition(i,j)->widget());
                tmpCharacter->setPixmap( *characterTextures[4][0] );
                tmpCharacter->setObjectName("CurrentCharTile");
                tmpCharacter->setScaledContents(true);
                tmpCharacter->show();
                tmpCharacter->raise();
                //if the current tile has char then show it above the tile texture
            }

            if(typeid(*currentTile) == typeid(Floor))
            {
                tmp->setMinimumHeight(ui->widget->height()/height);
                tmp->setMinimumWidth(ui->widget->width()/width);
                tmp->setPixmap( *floorTextures[ rand()%4 ] );
                tmp->setScaledContents(true);
                ui->gridLayout->addWidget(tmp, i, j, Qt::AlignCenter); // i = height - (i+1)
            }
            else if(typeid(*currentTile) == typeid(Wall))
            {
                tmp->setMinimumHeight(ui->widget->height()/height);
                tmp->setMinimumWidth(ui->widget->width()/width);
                tmp->setPixmap( *WallTexture );
                tmp->setScaledContents(true);
               ui->gridLayout->addWidget(tmp, i, j, Qt::AlignCenter);
            }
            else if(typeid(*currentTile) == typeid(Portal))
            {
                tmp->setMinimumHeight(ui->widget->height()/height);
                tmp->setMinimumWidth(ui->widget->width()/width);
                Portal* tmpPortal = dynamic_cast<Portal*>(currentTile);
                tmp->setPixmap( *portalTextures[ tmpPortal->getPortalType() ] );
                tmp->setScaledContents(true);
               ui->gridLayout->addWidget(tmp, i, j, Qt::AlignCenter);
            }
            else if(typeid(*currentTile) == typeid(Switch))
            {
                tmp->setMinimumHeight(ui->widget->height()/height);
                tmp->setMinimumWidth(ui->widget->width()/width);
                tmp->setPixmap( *SwitchTexture );
                tmp->setScaledContents(true);
                ui->gridLayout->addWidget(tmp, i, j, Qt::AlignCenter);
            }
            else if(typeid(*currentTile) == typeid(Door))
            {
                tmp->setMinimumHeight(ui->widget->height()/height);
                tmp->setMinimumWidth(ui->widget->width()/width);
                tmp->setPixmap( *doorTextures[0] );
                tmp->setScaledContents(true);
                ui->gridLayout->addWidget(tmp, i, j, Qt::AlignCenter);
             }
            else if(typeid(*currentTile) == typeid(Ramp))
            {
                tmp->setMinimumHeight( ui->widget->height()/height );
                tmp->setMinimumWidth(ui->widget->width()/width);
                tmp->setPixmap( *RampTexture );
                tmp->setScaledContents(true);
                ui->gridLayout->addWidget(tmp, i, j, Qt::AlignCenter);

                QLabel* forRamp = new QLabel("", tmp);
                forRamp->setPixmap( *RampTexture );
                forRamp->setScaledContents(true);
                forRamp->setMaximumSize( tmp->size() );
                forRamp->resize( tmp->size() );
                forRamp->setStyleSheet("background-color: ffffff;");

            }
            else if(typeid(*currentTile) == typeid(Pit))
            {
                tmp->setPixmap( *PitTexture );
                tmp->setScaledContents(true);
                ui->gridLayout->addWidget(tmp, i, j, Qt::AlignCenter);
                tmp->setMinimumHeight(ui->widget->height()/height );
                tmp->setMinimumWidth(ui->widget->width()/width);

                QLabel* forPit = new QLabel("", tmp);
                forPit->setPixmap( *PitTexture );
                forPit->setScaledContents(true);
                forPit->resize( tmp->size() );
            }
            else if(typeid(*currentTile) == typeid(Levelchanger))
            {
                tmp->setPixmap(*portalTextures[3]);
                tmp->setScaledContents(true);
                ui->gridLayout->addWidget(tmp,i,j,Qt::AlignCenter);
                tmp->setMinimumHeight(ui->widget->height()/height);
                tmp->setMaximumHeight(ui->widget->width()/width);
            }
            else if(typeid(*currentTile) == typeid(Lootchest))
            {
                tmp->setPixmap(*loot_chest);
                tmp->setScaledContents(true);
                ui->gridLayout->addWidget(tmp,i,j,Qt::AlignCenter);
                tmp->setMinimumHeight(ui->widget->height()/height);
                tmp->setMaximumHeight(ui->widget->width()/width);
            }
            if(currentTile->hasCharacter())
            {
                if( currentTile->getCharacter()->isPlayable() )
                {
                 QLabel* tempCharacter = new QLabel("", ui->gridLayout->itemAtPosition(i,j)->widget());
                 tempCharacter->setScaledContents(true);
                 tempCharacter->setPixmap(*characterTextures[1][1]);
                 tempCharacter->setMaximumSize(ui->gridLayout->itemAtPosition(i,j)->widget()->size());
                 tempCharacter->setObjectName("CurrentCharTile");
                 tempCharacter->setStyleSheet("QLabel{background-color: transparent;}");
                 tempCharacter->show();
                 tempCharacter->lower();
                }
                else
                {
                 QLabel* tempNPC = new QLabel("", ui->gridLayout->itemAtPosition(i,j)->widget());
                 tempNPC->setScaledContents(true);
                 tempNPC->setMaximumSize(ui->gridLayout->itemAtPosition(i,j)->widget()->size());
                 tempNPC->setPixmap(*zombieTextures[rand()%2]);
                 tempNPC->setObjectName("CurrentCharTile");
                 tempNPC->setStyleSheet("QLabel{background-color: transparent;}");
                 tempNPC->show();
                 tempNPC->lower();
                }
            }
        }
    }

 start_screen->show();

}

GraphicalUI::~GraphicalUI()
{
    delete main_game;
    delete start_screen;
    delete WallTexture;
    delete SwitchTexture;
    delete PitTexture;
    delete RampTexture;
    delete FrameTexture;

    for(auto ptr : doorTextures)
    {
        delete ptr;
    }
    for(auto ptr : zombieTextures )
    {
        delete ptr;
    }
    for(auto ptr : floorTextures)
    {
        delete ptr;
    }
   for(auto ptr : portalTextures)
   {
       delete ptr;
   }
   for(auto& arr : characterTextures)
   {
      for(auto& ptr : arr)
      {
          delete ptr;
      }
   }
}

int GraphicalUI::move()
{
    QFont font("Times New Roman",17);
    auto ui = main_game->getUI();
    ui->playerstats->adjustSize();
    ui->playerstats->setFont(font);

    Character* character;
    int i=0;
    while(true)
    {
        if(ActualLevel->getCharContainer().at(i)->isPlayable()){
        character = ActualLevel->getCharContainer()[i];
        break;
        }
        i++;
    }
    //the line above is done because when NPCS are placed in another level, then our char from old level will
    //be displayed with the stats of the NPC in this level. With this line we make sure the correct stats is being
    //displayed

   while(true)
    {
       QTest::qWait(50);
       QCoreApplication::processEvents();    //ohne die Zeile crasht das Programm
       if(main_game->hasButtonBeenPressed())
       {
            main_game->setInputChanged(false);
            ui->playerstats->setText( QString("Playerstats:\nPlayer-Strength: %1\nPlayer-Stamina: %2\nPlayer-HP: %3").arg(character->getStrength()).arg(character->getStamina()).arg(character->getHP()) );
            return main_game->getLastButtonPressed();
       }
    }
}

void GraphicalUI::switchWindow()
{
    start_screen->hide();
    main_game->show();
}

void GraphicalUI::draw(Level *level)
{
   int rows = level->getHeight(); //the level should be row*cols dimension
   int cols = level->getWidth();
   auto ui = main_game->getUI();

   for(int i = 0; i < rows; i++)
   {
       for(int j = 0; j < cols; j++)
       {
           //delete the char image from old tile after turn(int) has been called
           QLabel* CheckForKidLabels = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );
           for(auto& x : CheckForKidLabels->children())
           {
               if(x->objectName() == "CurrentCharTile")
                   delete x;
           }
           for(auto& x : ui->centralwidget->children())
           {
               if( x->objectName() ==  "CurrentCharTile")
                   delete x;
           }

           Tile* tmp_tile = level->getTile(i,j);
           if(tmp_tile->hasCharacter()) //if there is a char at the tile;
           {
               int moveDirection = tmp_tile->getCharacter()->getMoveDirection();
               QLabel* CurrentPlayerTile = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );
               QLabel* CharacterLabel = new QLabel("", CurrentPlayerTile);
               CharacterLabel->setObjectName("CurrentCharTile");
               CharacterLabel->setMaximumSize( CurrentPlayerTile->size() );
               CharacterLabel->setScaledContents(true);
               CharacterLabel->setStyleSheet("QLabel{ background-color: transparent;}");
               QPixmap tmp=*characterTextures[1][0];
               CharacterLabel->setPixmap( tmp );

                   switch(moveDirection)
                   {
                       case 1:
                       case 2:
                       case 3:
                       {
                           CharacterLabel->setPixmap( *characterTextures[1][ rand()%3 ] );
                           break;
                       }
                       case 4:
                       {
                           CharacterLabel->setPixmap( *characterTextures[2][ rand()%3 ] );
                           break;
                       }
                       case 6:
                       {
                           CharacterLabel->setPixmap( *characterTextures[3][ rand()%3 ] );
                           break;
                       }
                       case 7:
                       case 8:
                       case 9:
                       {
                           CharacterLabel->setPixmap( *characterTextures[0][ rand()%3 ] );
                           break;
                       }
                       default:
                       {
                          if( typeid(( *tmp_tile->getCharacter() )) ==typeid(NPC)  )
                          {

                            CharacterLabel->setPixmap( *zombieTextures[ rand()%2 ] );
                          }
                          else
                             CharacterLabel->setPixmap( *characterTextures[ 1 ][0] );
                          break;
                       }

                   }
               CharacterLabel->show();
               CharacterLabel->lower();
            }

           if(typeid(*tmp_tile) == typeid(Door))
           {
               Door* tmpDoor = dynamic_cast<Door*>(tmp_tile);
               QLabel* tmpLabel = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );

               if(tmpDoor->isOpen())
                  tmpLabel->setPixmap(*doorTextures[1]);
               else
                  tmpLabel->setPixmap(*doorTextures[0]);
            }

           if(typeid(*tmp_tile) == typeid(Pit))
           {
               if(tmp_tile->hasCharacter())
               {
                   QLabel* CharacterLabel = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );
                   CharacterLabel->raise();
                   CharacterLabel->setStyleSheet("QLabel{ background-color: transparent;}");
               }
            }

           if(typeid(*tmp_tile) == typeid(Ramp))
           {
                if(tmp_tile->hasCharacter())
                {
                   QLabel* CharacterLabel = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );
                   CharacterLabel->raise();
                   CharacterLabel->setStyleSheet("QLabel{ background-color: transparent;}");
                   CharacterLabel->lower();
                }
            }

           //this has been done so that after we change the level, the old textures will get overwritten if they have to to overwritten;

           if(typeid(*tmp_tile) == typeid(Floor))
           {
               QLabel* CurrentCharLabel = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() ); 
               CurrentCharLabel->setPixmap( *floorTextures[0] );
               CurrentCharLabel->raise();
           }

           if(typeid(*tmp_tile) == typeid(Wall))
           {
               QLabel* CurrentCharLabel = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );
               CurrentCharLabel->setPixmap( *WallTexture );
               CurrentCharLabel->raise();
           }

           if(typeid(*tmp_tile) == typeid(Portal))
           {
               QLabel* CurrentCharacterLabel = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );
               Portal* tmpPortal = dynamic_cast<Portal*>(tmp_tile);
               CurrentCharacterLabel->setPixmap( *portalTextures[ tmpPortal->getPortalType() ] );
               CurrentCharacterLabel->raise();
           }

           if(typeid(*tmp_tile) == typeid(Switch))
           {
               QLabel* CurrentCharacterLabel = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );
               CurrentCharacterLabel->setPixmap( *SwitchTexture );
               CurrentCharacterLabel->raise();
            }

           if(typeid(*tmp_tile) == typeid(Levelchanger))
           {
               QLabel* CurrentCharacterLabel = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );
               CurrentCharacterLabel->setPixmap( *portalTextures[ 3 ] );
               CurrentCharacterLabel->raise();
           }
           if(typeid(*tmp_tile) == typeid(Lootchest))
           {
               QLabel* CurrentCharacterLabel = qobject_cast<QLabel*>( ui->gridLayout->itemAtPosition(i,j)->widget() );
               CurrentCharacterLabel->setPixmap( *loot_chest );
               CurrentCharacterLabel->raise();
           }
        }
    }
}

Level* GraphicalUI::getActualLevel() const
{
    return this->ActualLevel;
}

void GraphicalUI::setActualLevel(Level* l1)
{
    this->ActualLevel= nullptr;
    this->ActualLevel= l1;
}

void GraphicalUI::setBloodyFrame()
{
    QPixmap BloodyFrame;
    BloodyFrame.load("C:/Users/Dell/Desktop/textures/bloody_frame.png");
    main_game->getUI()->label->setPixmap(BloodyFrame);
    main_game->getUI()->label->setScaledContents(true);
    main_game->getUI()->label->setStyleSheet("background: transparent;}");
}

void GraphicalUI::setArrowsPixmap()
{
    arrowTextures[0]=(new QPixmap("C:/Users/Dell/Desktop/textures/arrows/arrow_up_left.png"));
    arrowTextures[1]=(new QPixmap("C:/Users/Dell/Desktop/textures/arrows/arrow_up.png"));
    arrowTextures[2]=(new QPixmap("C:/Users/Dell/Desktop/textures/arrows/arrow_up_right.png"));
    arrowTextures[3]=(new QPixmap("C:/Users/Dell/Desktop/textures/arrows/arrow_left.png"));
    arrowTextures[4]=(new QPixmap("C:/Users/Dell/Desktop/textures/arrows/arrow_skip.png"));
    arrowTextures[5]=(new QPixmap("C:/Users/Dell/Desktop/textures/arrows/arrow_right.png"));
    arrowTextures[6]=(new QPixmap("C:/Users/Dell/Desktop/textures/arrows/arrow_down_left.png"));
    arrowTextures[7]=(new QPixmap("C:/Users/Dell/Desktop/textures/arrows/arrow_down.png"));
    arrowTextures[8]=(new QPixmap("C:/Users/Dell/Desktop/textures/arrows/arrow_down_right.png"));
}

void GraphicalUI::setCharacterPixmap()
{

    QPixmap* character1 = new QPixmap("C:/Users/Dell/Desktop/textures/char/back/char_back_1.png");
    QPixmap* character2 = new QPixmap("C:/Users/Dell/Desktop/textures/char/back/char_back_2.png");
    QPixmap* character3 = new QPixmap("C:/Users/Dell/Desktop/textures/char/back/char_back_3.png");
    QPixmap* character4 = new QPixmap("C:/Users/Dell/Desktop/textures/char/front/char_front_1.png");
    QPixmap* character5 = new QPixmap("C:/Users/Dell/Desktop/textures/char/front/char_front_2.png");
    QPixmap* character6 = new QPixmap("C:/Users/Dell/Desktop/textures/char/front/char_front_3.png");
    QPixmap* character7 = new QPixmap("C:/Users/Dell/Desktop/textures/char/left/char_left_1.png");
    QPixmap* character8 = new QPixmap("C:/Users/Dell/Desktop/textures/char/left/char_left_2.png");
    QPixmap* character9 = new QPixmap("C:/Users/Dell/Desktop/textures/char/left/char_left_3.png");
    QPixmap* character10 = new QPixmap("C:/Users/Dell/Desktop/textures/char/right/char_right_1.png");
    QPixmap* character11 = new QPixmap("C:/Users/Dell/Desktop/textures/char/right/char_right_2.png");
    QPixmap* character12 = new QPixmap("C:/Users/Dell/Desktop/textures/char/right/char_right_3.png");
    QPixmap* character13 = new QPixmap("C:/Users/Dell/Desktop/textures/char/right/char_right_3.png");

    characterTextures[0][0] = character1;
    characterTextures[0][1] = character2;
    characterTextures[0][2] = character3;
    characterTextures[1][0] = character4;
    characterTextures[1][1] = character5;
    characterTextures[1][2] = character6;
    characterTextures[2][0] = character7;
    characterTextures[2][1] = character8;
    characterTextures[2][2] = character9;
    characterTextures[3][0] = character10;
    characterTextures[3][1] = character11;
    characterTextures[3][2] = character12;
    characterTextures[4][0] = character13;

}

void GraphicalUI::setFloorPixmap()
{
   floorTextures[0] = new QPixmap("C:/Users/Dell/Desktop/textures/floor/floor1.png");
   floorTextures[1] = new QPixmap("C:/Users/Dell/Desktop/textures/floor/floor2.png");
   floorTextures[2] = new QPixmap("C:/Users/Dell/Desktop/textures/floor/floor3.png");
   floorTextures[3] = new QPixmap("C:/Users/Dell/Desktop/textures/floor/floor4.png");
   floorTextures[4] = new QPixmap("C:/Users/Dell/Desktop/textures/floor/floor5.png");

}

void GraphicalUI::setPortalPixmap()
{
   portalTextures[0] = new QPixmap("C:/Users/Dell/Desktop/textures/portal/portal1.png");
   portalTextures[1] = new QPixmap("C:/Users/Dell/Desktop/textures/portal/portal2.png");
   portalTextures[2] = new QPixmap("C:/Users/Dell/Desktop/textures/portal/portal3.png");
   portalTextures[3]=  new QPixmap("C:/Users/Dell/Desktop/textures/levelchanger.png");

}

void GraphicalUI::setOtherPixmap()
{

    WallTexture = new QPixmap("C:/Users/Dell/Desktop/textures/wall/wall1.png");

    SwitchTexture = new QPixmap("C:/Users/Dell/Desktop/textures/switch.png");

    PitTexture =new QPixmap("C:/Users/Dell/Desktop/textures/pit.png");

    RampTexture = new QPixmap("C:/Users/Dell/Desktop/textures/ramp.png");

    FrameTexture = new QPixmap("C:/Users/Dell/Desktop/textures/bloody_frame.png");

   doorTextures[0] = new QPixmap("C:/Users/Dell/Desktop/textures/doors/door1.png");
   doorTextures[1] = new QPixmap("C:/Users/Dell/Desktop/textures/doors/door2.png");

    zombieTextures[0] = new QPixmap("C:/Users/Dell/Desktop/textures/zombie/zombie_left.png");
    zombieTextures[1] = new QPixmap("C:/Users/Dell/Desktop/textures/zombie/zombie_right.png");

    welcome_screen=new QPixmap("C:/Users/Dell/Desktop/textures/startscreen.png");
    start_button=new QPixmap("C:/Users/Dell/Desktop/textures/new_game_button.png");

    loot_chest=new QPixmap("C:/Users/Dell/Desktop/textures/chest.png");

}

void GraphicalUI::winEvent()
{
    QMessageBox* winBox =new QMessageBox();
    winBox->setStandardButtons(QMessageBox::Ok | QMessageBox::No);
    winBox->setText("You found the hidden tresure ! ! !");
    winBox->adjustSize();
    int x= winBox->exec();
    switch (x)
    {
          case QMessageBox::Ok:
        {
            QMessageBox* wB= new QMessageBox();
            wB->setText("You won !");
            wB->adjustSize();
            wB->exec();
            QTest::qWait(333);
            delete winBox;
            delete wB;
            exit(0);
            break;
        }
          case QMessageBox::No:
        {
            break;
        }
    }
    delete winBox;
}

void GraphicalUI::deathEvent()
{
    QMessageBox* msg = new QMessageBox(); 
    msg->setText("You died to an NPC .....");
    msg->exec();
    QTest::qWait(333);
    exit(0);
}





