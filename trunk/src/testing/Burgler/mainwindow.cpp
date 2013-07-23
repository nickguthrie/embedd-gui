////////////////////////////////////////////////////////////////////////////////
/**
 *  @file mainwindow.cpp
 *  @brief A basic 5 channel controller program.
 *
 *  The program allows a person to turn a light on and off, as well as control 5
 *  channels.
 *  
 *  @title Burgler
 *  @author Nicholas Guthrie
 *  @web http//nickguthrie.com
 *  @created July 23, 2013
 * 
 */
////////////////////////////////////////////////////////////////////////////////
/**
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------ :Libraries:
//                      _    _ _                 _        
//                     | |  (_) |__ _ _ __ _ _ _(_)___ ___
//                     | |__| | '_ \ '_/ _` | '_| / -_|_-<
//                     |____|_|_.__/_| \__,_|_| |_\___/__/
//                                                        
// -----------------------------------------------------------------------------
#include "mainwindow.h"
#include "channel.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <string>

//--------------------------------------------------------------------- :Global:
//                            ___ _     _          _ 
//                           / __| |___| |__  __ _| |
//                          | (_ | / _ \ '_ \/ _` | |
//                           \___|_\___/_.__/\__,_|_|
//                                                   
// -----------------------------------------------------------------------------
#define INCRAMENT 10
#define NUM_CHAN 5

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
    // connect(ui->hslider_01, SIGNAL(valueChanged(int)),
    // 	    ui->lcd_01, SLOT(display(int)));
    // connect(ui->hslider_02, SIGNAL(valueChanged(int)),
    // 	    ui->lcd_02, SLOT(display(int)));
    // connect(ui->hslider_03, SIGNAL(valueChanged(int)),
    // 	    ui->lcd_03, SLOT(display(int)));
    // connect(ui->hslider_04, SIGNAL(valueChanged(int)),
    // 	    ui->lcd_04, SLOT(display(int)));
    // connect(ui->hslider_05, SIGNAL(valueChanged(int)),
    // 	    ui->lcd_05, SLOT(display(int)));

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
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Window deconstructor.
 */
////////////////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete ui;
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Updates the LCD of the current mode set.  This function should be
 *  called every time a channel value is modified with the appropriate mode.
 *  @warning Does not verify the mode is valid.
 */
////////////////////////////////////////////////////////////////////////////////
wvoid MainWindow::UpdateLCD()
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
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Modifies the mode for button 0.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_cbutton_0_clicked()
{
    mode = 0;
    ui->mode_label->setText("Channel 0");
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Modifies the mode for button 1.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_cbutton_1_clicked()
{
    mode = 1;
    ui->mode_label->setText("Channel 1");
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Modifies the mode for button 2.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_cbutton_2_clicked()
{
    mode = 2;
    ui->mode_label->setText("Channel 2");
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Modifies the mode for button 3.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_cbutton_3_clicked()
{
    mode = 3;
    ui->mode_label->setText("Channel 3");
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Modifies the mode for button 4.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_cbutton_4_clicked()
{
    mode = 4;
    ui->mode_label->setText("Channel 4");
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Sets a channel to its minimum value.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pb_value_off_clicked()
{
    cholder[mode].set_value(cholder[mode].get_min());
    UpdateLCD();
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Sets a channel to its maximum
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pb_value_full_clicked()
{
    cholder[mode].set_value(cholder[mode].get_max());
    UpdateLCD();
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Sets a channel to half of its value (max - min)/2.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pb_value_half_clicked()
{
    int val = (cholder[mode].get_max()
	       - cholder[mode].get_min()) / 2;
    cholder[mode].set_value(val);
    UpdateLCD();
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Watches if the slider value changes and modifies the channel.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_channelSlider_valueChanged(int value)
{
    int val = ui->channelSlider->value();
    cholder[mode].set_value(val);
    UpdateLCD();
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Incraments the channel while the incrament button is held down.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pb_value_incrament_pressed()
{
    incrament = true;
    timerTimeout = 2000;
    doIncrement();
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Decraments the channel while the incrament button is held down.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pb_value_decrament_pressed()
{
    incrament = false;
    timerTimeout = 2000;
    doIncrement();

}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief A timer function for the incrament/decrament buttons.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::buttonPressed()
{
    timerTimeout = 2000;
    doIncrement();
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief A timer function for the incrament/decrament buttons.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::buttonReleased()
{
    timer->stop();
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Timer function that modifies the values for incrament and decrament.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::doIncrement()
{
    // If the incrament button, incrament channel
    if( incrament )
	cholder[mode].incrament();
    // If the decrament button, decrament channel
    else
	cholder[mode].decrament();
    //ui->label->setText(QString("Value: %1").arg(number));
    if( timerTimeout > 10 )
        timerTimeout = timerTimeout / 4;
    timer->start(timerTimeout);
    UpdateLCD();
}
