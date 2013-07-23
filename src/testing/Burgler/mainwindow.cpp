#include "mainwindow.h"
#include "channel.h"
#include "ui_mainwindow.h"

#include <QTimer>


#define INCRAMENT 10
#define NUM_CHAN 5

#include <string>

int PUSHED;
int mode;
channel * cholder;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    PUSHED = 0;
    ui->setupUi(this); 
    
    ////////////////////////////////////////
    // Sliders - Connect sliders to LCD
    ////////////////////////////////////////
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

    ////////////////////////////////////////
    // Channels
    ////////////////////////////////////////
    cholder = new channel[NUM_CHAN];

    // Testing
    for( int i=0; i<NUM_CHAN; i++ )
    {
	mode = i;
	cholder[i].set_value(i+50);
	UpdateLCD();
    }


    ////////////////////////////////////////
    // Button Incramenting
    ////////////////////////////////////////
    number = 0;
    timerTimeout = 0;
    timer = new QTimer(this);

    // Incrament Button Connections
    connect(timer, SIGNAL(timeout()), this, SLOT(doIncrement()));
    connect(ui->pb_value_incrament, SIGNAL(pressed()), this, SLOT(buttonPressed()));
    connect(ui->pb_value_incrament, SIGNAL(released()), this, SLOT(buttonReleased()));
    connect(ui->pb_value_decrament, SIGNAL(pressed()), this, SLOT(buttonPressed()));
    connect(ui->pb_value_decrament, SIGNAL(released()), this, SLOT(buttonReleased()));


    

    //ui->lcd_0->display(55);
    //ui->lcd_2->display(cholder[2].get_value());
    
    //ui->cbutton_01->setText("Foo");
    //std::string foo = cholder[2].get_svalue();
    //ui->cbutton_02->setText( foo );
    //cholder.get_channel(0)->get_value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_pb_up_pressed()
//{
    /*ui->pb_up->setText("Pushed");
    if(PUSHED < 100)
	PUSHED += INCRAMENT;
    ui->progressBar->setValue(PUSHED);
    */
//}

//void MainWindow::on_pb_down_pressed()
//{
    /*if(PUSHED >= INCRAMENT)
	PUSHED -= INCRAMENT;
	ui->progressBar->setValue(PUSHED);*/
//}

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

void MainWindow::ModeButton( int num )
{
    mode = num;
    UpdateLCD();
    //ui->mode_label->setText("foo");
}

void MainWindow::UpdateLCD()
{
    // Update Slider
    ui->channelSlider->setRange(cholder[mode].get_min(), cholder[mode].get_max());
    ui->channelSlider->setValue(cholder[mode].get_value());

    // Update LCD Screens
    switch (mode)
    {
    case 0:
	ui->lcd_0->display(cholder[0].get_value());
	break;
    case 1:
	ui->lcd_1->display(cholder[1].get_value());
	break;
    case 2:
	ui->lcd_2->display(cholder[2].get_value());
	break;
    case 3:
	ui->lcd_3->display(cholder[3].get_value());
	break;
    case 4:
	ui->lcd_4->display(cholder[4].get_value());
	break;
    default:
	// ERROR
	break;
    }    
}

void MainWindow::on_cbutton_0_clicked()
{
    mode = 0;
    ui->mode_label->setText("Channel 0");
}

void MainWindow::on_cbutton_1_clicked()
{
    mode = 1;
    ui->mode_label->setText("Channel 1");
}

void MainWindow::on_cbutton_2_clicked()
{
    mode = 2;
    ui->mode_label->setText("Channel 2");
}

void MainWindow::on_cbutton_3_clicked()
{
    mode = 3;
    ui->mode_label->setText("Channel 3");
}

void MainWindow::on_cbutton_4_clicked()
{
    mode = 4;
    ui->mode_label->setText("Channel 4");
}

void MainWindow::on_pb_value_off_clicked()
{
    cholder[mode].set_value(0);
    UpdateLCD();
}

void MainWindow::on_pb_value_full_clicked()
{
    cholder[mode].set_value(cholder[mode].get_max());
    UpdateLCD();
}

void MainWindow::on_pb_value_decrament_clicked()
{
    //incrament = true;
    // int val = cholder[mode].get_value();
    // val--;
    // cholder[mode].set_value(val);
    // UpdateLCD();
}

void MainWindow::on_pb_value_incrament_clicked()
{
    //incrament = false;
    // int val = cholder[mode].get_value();
    // val++;
    // cholder[mode].set_value(val);
    // UpdateLCD();
}

void MainWindow::on_pb_value_half_clicked()
{
    int val = (cholder[mode].get_max()
	       - cholder[mode].get_min()) / 2;
    cholder[mode].set_value(val);
    UpdateLCD();
}

void MainWindow::on_channelSlider_valueChanged(int value)
{
    int val = ui->channelSlider->value();
    cholder[mode].set_value(val);
    UpdateLCD();
}

void MainWindow::on_pb_value_incrament_pressed()
{
    incrament = true;
    timerTimeout = 2000;
    doIncrement();
}

void MainWindow::on_pb_value_decrament_pressed()
{
    incrament = false;
    timerTimeout = 2000;
    doIncrement();

}

void MainWindow::buttonPressed()
{
    timerTimeout = 2000;
    doIncrement();
}
 
void MainWindow::buttonReleased()
{
    timer->stop();
}

void MainWindow::doIncrement()
{
    if( incrament )
	cholder[mode].incrament();
    else
	cholder[mode].decrament();
    //ui->label->setText(QString("Value: %1").arg(number));
    if(timerTimeout > 50)
        timerTimeout = timerTimeout / 2;
    timer->start(timerTimeout);
    UpdateLCD();
}

// void MainWindow::doDecrement()
// {
//     cholder[mode].decrament();
//     if(timerTimeout > 50)
//         timerTimeout = timerTimeout / 2;
//     timer->start(timerTimeout);
//     UpdateLCD();
// }

