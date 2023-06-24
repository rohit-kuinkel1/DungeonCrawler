#ifndef MOVEBUTTON_H
#define MOVEBUTTON_H

#include <QPushButton>

class MoveButton: public QPushButton
{
    Q_OBJECT //macro sodass unsere Klasse richtig funktioniert
public:
    MoveButton(int, QWidget* parent = nullptr);
private:
    int last_input;
public slots:
    void clickMe();
signals:
    void movementDone(int);
};

#endif
