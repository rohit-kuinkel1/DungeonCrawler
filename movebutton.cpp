#include "movebutton.h"

MoveButton::MoveButton(int input, QWidget* parent)
    : QPushButton(parent), last_input(input)
{
    connect(this, &MoveButton::clicked, this, &MoveButton::clickMe);
    //clicked is the func of QPushButton, which is to be connected with the function clickMe from our button,movebutton through emit
}

void MoveButton::clickMe()
{
    emit movementDone(last_input); //giveback the last button user pressed as signal
}





