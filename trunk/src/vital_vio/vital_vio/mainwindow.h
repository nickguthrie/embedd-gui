#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProxyStyle>
#include <QScrollBar>

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

    //void on_label_3_linkActivated();

private:
    Ui::MainWindow *ui;
    QPushButton *deleteButton;
};


// Override style for better Touchscreen handling
class MyProxyStyle : public QProxyStyle
{
  public:
    int pixelMetric ( PixelMetric metric, const QStyleOption * option = 0,
		      const QWidget * widget = 0 ) const
    {
        switch(metric) {
          case PM_SliderControlThickness  : return 50;
          default                         : return
		(QProxyStyle::pixelMetric(metric,option,widget));
        }
    }
    
};




#endif // MAINWINDOW_H
