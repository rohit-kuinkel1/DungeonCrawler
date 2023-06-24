#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class GraphicalUI;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int rows = 1, int cols = 1,GraphicalUI* gpt=nullptr, QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow* getUI();
    void setAndConnectButtons();
    void setInputChanged(bool status);
    bool hasButtonBeenPressed();
    int getLastButtonPressed();
    //MoveButton *down,*down_left,*down_right,*left,*right,*stay,*up_left,*up_right,*up;
    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::MainWindow *ui=nullptr;
    int row;
    int column;
    bool has_button_been_pressed;
    int last_button_pressed;
    GraphicalUI* gptr=nullptr;

public slots:
    void moveSlot(int move);

};
#endif // MAINWINDOW_H

