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
    void ModeButton( int num );
    void UpdateLCD();
    ~MainWindow();
    
private slots:
    //void on_pb_up_pressed();
    //void on_pb_down_pressed();
    //void on_hslider_01_sliderMoved(int position);
    //void on_hslider_01_sliderPressed();
    //void on_hslider_02_actionTriggered(int action);
    void on_cbutton_0_clicked();
    void on_cbutton_1_clicked();
    void on_cbutton_2_clicked();
    void on_cbutton_3_clicked();
    void on_cbutton_4_clicked();
    //void on_pb_up_3_clicked();
    void on_pb_value_off_clicked();
    void on_pb_value_full_clicked();
    void on_pb_value_decrament_clicked();
    void on_pb_value_incrament_clicked();
    void on_pb_value_half_clicked();
    void on_channelSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
