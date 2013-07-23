#include "mainwindow.h"
#include "channel.h"
#include "ui_mainwindow.h"

#define INCRAMENT 10
#define NUM_CHAN 5

int PUSHED;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    PUSHED = 0;
    ui->setupUi(this); 
    
    ////////////////////
    // Sliders
    ////////////////////
    /*connect(ui->verticalSlider,SIGNAL(valueChanged(int)),
      ui->progressBar,SLOT(setValue(int))); */
    connect(ui->hslider_01, SIGNAL(valueChanged(int)),
	    ui->lcd_01, SLOT(display(int)));
    connect(ui->hslider_02, SIGNAL(valueChanged(int)),
	    ui->lcd_02, SLOT(display(int)));
    connect(ui->hslider_03, SIGNAL(valueChanged(int)),
	    ui->lcd_03, SLOT(display(int)));
    connect(ui->hslider_04, SIGNAL(valueChanged(int)),
	    ui->lcd_04, SLOT(display(int)));
    connect(ui->hslider_05, SIGNAL(valueChanged(int)),
	    ui->lcd_05, SLOT(display(int)));

    ////////////////////
    // Channels
    ////////////////////
    int mode;
    channel * cholder = new channel[NUM_CHAN];


    // Testing
    for( int i=0; i<NUM_CHAN; i++ )
    {
	cholder[i].set_value(i+5);
    }

    ui->cbutton_01->setText("Foo");
    //cholder.get_channel(0)->get_value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_up_pressed()
{
    /*ui->pb_up->setText("Pushed");
    if(PUSHED < 100)
	PUSHED += INCRAMENT;
    ui->progressBar->setValue(PUSHED);
    */
}

void MainWindow::on_pb_down_pressed()
{
    /*if(PUSHED >= INCRAMENT)
	PUSHED -= INCRAMENT;
	ui->progressBar->setValue(PUSHED);*/
}

/*void MainWindow::on_hslider_01_sliderMoved(int position)
{
    ui->lcd_01->setDecMode();
}

void MainWindow::on_hslider_01_sliderPressed()
{
    ui->lcd_01->display(20);
}

void MainWindow::on_hslider_02_actionTriggered(int action)
{
    
}
*/
