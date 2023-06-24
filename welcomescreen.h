#ifndef WELCOME_SCREEN_H
#define WELCOME_SCREEN_H

#include "qlabel.h"
#include <QDialog>
#include <QDebug>
#include <QPushButton>

class GraphicalUI;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QLabel* label;
    explicit Dialog(GraphicalUI* gui,QWidget *parent = nullptr);
    ~Dialog();
    Ui::Dialog* getUI();
    QPushButton* tmp;
    //QPushButton* getStartButton();

private:
    Ui::Dialog *ui;
    GraphicalUI* GUI;

protected:
    void resizeEvent(QResizeEvent* event) override;

public slots:
    void gameStart();
};

#endif // WELCOME_SCREEN_H

