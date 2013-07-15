#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pb_up_pressed();


    void on_pb_down_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
