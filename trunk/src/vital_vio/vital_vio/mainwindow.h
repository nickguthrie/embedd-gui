#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
    void DeleteButtonInit();
    void DeleteButtonHide();
    void on_offButton_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *deleteButton;}
;

#endif // MAINWINDOW_H
