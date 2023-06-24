#include "ui_welcomescreen.h"
#include "graphicalui.h"
#include "welcomescreen.h"


Dialog::Dialog( GraphicalUI* gui,QWidget *parent)
    : QDialog(parent),ui(new Ui::Dialog),GUI(gui)
{
    ui->setupUi(this);

  QPixmap BackgroundImage;
  //BackgroundImage.load("C:/Users/Dell/Desktop/textures/startscreen.png");
  BackgroundImage= QPixmap(*gui->welcome_screen);
  ui->label->setPixmap(BackgroundImage);
  ui->label->setScaledContents(true);
  ui->label->setStyleSheet("background: black;");


  QPushButton* start_button = new QPushButton(this);
  tmp=start_button;
  start_button->resize( this->width()/6, this->height()/10);
  QPixmap pix= QPixmap(*gui->start_button);
  //pix.load("C:/Users/Dell/Desktop/textures/new_game_button.png");
   start_button->setIcon(pix);
   start_button->setIconSize(start_button->size());
  start_button->setIconSize(QSize(start_button->width(), start_button->height()));

   //place it somewhere in the middle
    int offset = (int)(start_button->width()/2);
    float x = (int)(ui->label->size().width()  / 2);
    float y = (int)(ui->label->size().height()/1.7);
    start_button->move(x-offset,y); //set it exactly at the horizontal center

    connect(start_button, &QPushButton::clicked, this, &Dialog::gameStart);
}

Ui::Dialog* Dialog::getUI()
{
    return this->ui;
}

Dialog::~Dialog()
{
    delete ui;
    delete GUI;
}

void Dialog::resizeEvent(QResizeEvent* event)
{
  QDialog::resizeEvent(event);

  ui->label->resize( this->width() + 10, this->height() );
  int offset = (int)(tmp->width()/2);
  int x = (int)(ui->label->size().width()  / 2);
  int y = (int)(ui->label->size().height() / 1.5);
  tmp->move(x - offset, y);
  tmp->resize( this->width()/5, this->height()/10);
}

void Dialog::gameStart()
{
    GUI->switchWindow();
}
