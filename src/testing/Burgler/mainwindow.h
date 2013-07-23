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
    void UpdateLCD();
    ~MainWindow();
    
private slots:
    void on_cbutton_0_clicked();
    void on_cbutton_1_clicked();
    void on_cbutton_2_clicked();
    void on_cbutton_3_clicked();
    void on_cbutton_4_clicked();
    void on_pb_value_off_clicked();
    void on_pb_value_full_clicked();
    void on_pb_value_half_clicked();
    void on_channelSlider_valueChanged(int value);
    void on_pb_value_incrament_pressed();
    void on_pb_value_decrament_pressed();

protected slots:
    void buttonPressed();
    void buttonReleased();
    void doIncrement();
 

private:
    Ui::MainWindow *ui;

    // Button Incramenter
    QTimer *timer;
    int timerTimeout;
    int number;
    bool incrament;
};

#endif // MAINWINDOW_H
