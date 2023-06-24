#include "mainwindow.h"
#include "graphicalui.h"
#include "movebutton.h"
#include <QPushButton>
#include "ui_mainwindow.h"

MainWindow::MainWindow(int row, int col, GraphicalUI* gpt,QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), row(row),column(col)
    , gptr(gpt)
{
   ui->setupUi(this);
   ui->centralwidget->setStyleSheet("background-color: #000000;");
   ui->statusbar->setStyleSheet("background-color: #000000;");
   ui->label->setStyleSheet("{background: transparent;");

   ui->widget->raise(); //level playground
   ui->label->raise(); //bloody image
   ui->widget_2->raise(); //buttons

   //for the bloody frame to show at top,we need to raise it after we raise our level, but in order for our buttons to work
   //it has to be at the very top of the layouts ,thats why widget_2 is raised at the end

}

MainWindow::~MainWindow()
{
    delete ui;
}

Ui::MainWindow *MainWindow::getUI()
{
    return ui;
}

void MainWindow::setAndConnectButtons()
{
    //create and set buttons
    MoveButton* down_left  = new MoveButton(1, ui->widget_2);
    down_left->setObjectName("down_left");

   MoveButton* down       = new MoveButton(2, ui->widget_2);
    down->setObjectName("down");

    MoveButton* down_right = new MoveButton(3, ui->widget_2);
    down_right->setObjectName("down_right");

    MoveButton* left       = new MoveButton(4, ui->widget_2);
    left->setObjectName("left");

    MoveButton* stay       = new MoveButton(5, ui->widget_2);
    stay->setObjectName("stay");

    MoveButton* right      = new MoveButton(6, ui->widget_2);
    right->setObjectName("right");

    MoveButton*up_left     = new MoveButton(7, ui->widget_2);
    up_left->setObjectName("up_left");

    MoveButton*up          = new MoveButton(8, ui->widget_2);
    up->setObjectName("up");

    MoveButton* up_right   = new MoveButton(9, ui->widget_2);
    up_right->setObjectName("up_right");

    //set the pix for these buttons
    //load the images first

    QIcon* icon1=(new QIcon("C:/Users/Dell/Desktop/textures/arrows/arrow_up_left.png"));
    QIcon* icon2=(new QIcon("C:/Users/Dell/Desktop/textures/arrows/arrow_up.png"));
    QIcon* icon3=(new QIcon("C:/Users/Dell/Desktop/textures/arrows/arrow_up_right.png"));
    QIcon* icon4=(new QIcon("C:/Users/Dell/Desktop/textures/arrows/arrow_left.png"));
    QIcon* icon5=(new QIcon("C:/Users/Dell/Desktop/textures/arrows/arrow_skip.png"));
    QIcon* icon6=(new QIcon("C:/Users/Dell/Desktop/textures/arrows/arrow_right.png"));
    QIcon* icon7=(new QIcon("C:/Users/Dell/Desktop/textures/arrows/arrow_down_left.png"));
    QIcon* icon8=(new QIcon("C:/Users/Dell/Desktop/textures/arrows/arrow_down.png"));
    QIcon* icon9=(new QIcon("C:/Users/Dell/Desktop/textures/arrows/arrow_down_right.png"));

    //set the images
    up_left->setIcon(*icon1);//dereferencing the pointer to an actual object of type QIcon
    up->setIcon(*icon2);
    up_right->setIcon(*icon3);
    left->setIcon(*icon4);
    stay->setIcon(*icon5);
    right->setIcon(*icon6);
    down_left->setIcon(*icon7);
    down->setIcon(*icon8);
    down_right->setIcon(*icon9);

    //add the arrow buttons in a GridLayout
    ui->gridLayout_2->addWidget(up_left,0,0,Qt::AlignCenter);   //(<name of widget>,<cordinates inside grid>,<alignment>)
    ui->gridLayout_2->addWidget(up,0,1,Qt::AlignCenter);
    ui->gridLayout_2->addWidget(up_right,0,2,Qt::AlignCenter);
    ui->gridLayout_2->addWidget(left,1,0,Qt::AlignCenter);
    ui->gridLayout_2->addWidget(stay,1,1,Qt::AlignCenter);
    ui->gridLayout_2->addWidget(right,1,2,Qt::AlignCenter);
    ui->gridLayout_2->addWidget(down_left,2,0,Qt::AlignCenter);
    ui->gridLayout_2->addWidget(down,2,1,Qt::AlignCenter);
    ui->gridLayout_2->addWidget(down_right,2,2,Qt::AlignCenter);

    //display the widgets in a 3*3 square
    up_left->resize(ui->widget_2->width() / 3, ui->widget_2->height() / 3 );
    up_left->setIconSize( up_left->size() );

    up->resize(ui->widget_2->width() / 3, ui->widget_2->height() / 3);
    up->setIconSize( up->size() );

    up_right->resize(ui->widget_2->width() / 3, ui->widget_2->height() / 3);
    up_right->setIconSize( up_right->size() );

    left->resize(ui->widget_2->width() / 3, ui->widget_2->height() / 3);
     left->setIconSize( left->size() );

    stay->resize(ui->widget_2->width() / 3, ui->widget_2->height() / 3);
    stay->setIconSize( stay->size() );

    right->resize(ui->widget_2->width() / 3, ui->widget_2->height() / 3);
     right->setIconSize( right->size() );

    down_left->resize(ui->widget_2->width() / 3, ui->widget_2->height() / 3);
     down_left->setIconSize( down_left->size() );

    down->resize(ui->widget_2->width() / 3, ui->widget_2->height() / 3);
     down->setIconSize( down->size() );

    down_right->resize(ui->widget_2->width() / 3, ui->widget_2->height() / 3);
    down_right->setIconSize( down_right->size() );

// because it was recommended in the question
    up_left->setStyleSheet("border:none");
    up->setStyleSheet("border:none");
    up_right->setStyleSheet("border:none");
    left->setStyleSheet("border:none");
    stay->setStyleSheet("border:none");
    right->setStyleSheet("border:none");
    down_left->setStyleSheet("border:none");
    down->setStyleSheet("border:none");
    down_right->setStyleSheet("border:none");

    //establish a connection
    connect( qobject_cast<MoveButton*>(ui->gridLayout_2->itemAtPosition(0,0)->widget()), &MoveButton::movementDone, this, &MainWindow::moveSlot );
    connect( qobject_cast<MoveButton*>(ui->gridLayout_2->itemAtPosition(0,1)->widget()), &MoveButton::movementDone, this, &MainWindow::moveSlot );
    connect( qobject_cast<MoveButton*>(ui->gridLayout_2->itemAtPosition(0,2)->widget()), &MoveButton::movementDone, this, &MainWindow::moveSlot );
    connect( qobject_cast<MoveButton*>(ui->gridLayout_2->itemAtPosition(1,0)->widget()), &MoveButton::movementDone, this, &MainWindow::moveSlot );
    connect( qobject_cast<MoveButton*>(ui->gridLayout_2->itemAtPosition(1,1)->widget()), &MoveButton::movementDone, this, &MainWindow::moveSlot );
    connect( qobject_cast<MoveButton*>(ui->gridLayout_2->itemAtPosition(1,2)->widget()), &MoveButton::movementDone, this, &MainWindow::moveSlot );
    connect( qobject_cast<MoveButton*>(ui->gridLayout_2->itemAtPosition(2,0)->widget()), &MoveButton::movementDone, this, &MainWindow::moveSlot );
    connect( qobject_cast<MoveButton*>(ui->gridLayout_2->itemAtPosition(2,1)->widget()), &MoveButton::movementDone, this, &MainWindow::moveSlot );
    connect( qobject_cast<MoveButton*>(ui->gridLayout_2->itemAtPosition(2,2)->widget()), &MoveButton::movementDone, this, &MainWindow::moveSlot );
}

void MainWindow::setInputChanged(bool status)
{
    has_button_been_pressed = status;
}

bool MainWindow::hasButtonBeenPressed()
{
    return has_button_been_pressed;
}

int MainWindow::getLastButtonPressed()
{
    return last_button_pressed;
}

void MainWindow::moveSlot(int move)
{
    has_button_been_pressed = true;
    last_button_pressed = move;
    //after the button has been pressed, the signal is set to true and with that the last_button_pressed gets the int value of the button that was pressed
}



void MainWindow::resizeEvent(QResizeEvent* event)
{
    ui->widget->resize( this->width() * 0.75, this->height() - 40 );
    ui->widget_2->resize( this->width() * 0.22 , this->height() * 0.31 );
    ui->widget_2->move( this->width() * 0.78, this->height() * 0.28 );
    ui->label->resize( this->width(), this->height() );

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            //resize all the Tiles
            QLabel* tmp = qobject_cast<QLabel*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            tmp->setMinimumSize( ui->widget->width() / (column-1), ui->widget->height() / (row-1) );
            tmp->resize( ui->widget->width() / column, ui->widget->height() / row );
            for(auto& x : tmp->children())
            {
                QLabel* tmpChild = qobject_cast<QLabel*>(x);
                tmpChild->resize( tmp->size() );
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            QPushButton* tmp = qobject_cast<QPushButton*>( ui->gridLayout_2->itemAtPosition(i,j)->widget() );
            if( tmp )
            {
                tmp->resize( ui->widget_2->width() / 2.5, ui->widget_2->height() / 2.5 );
            }

        }
    }
}
