////////////////////////////////////////////////////////////////////////////////
/**
 *  @file mainwindow.cpp
 *  @brief 
 *
 *  Detailed Description
 *  
 *  @title Vital Vio
 *  @author Nicholas Guthrie
 *  @web http//nickguthrie.com
 *  @created July 29, 2013
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
#include "ui_mainwindow.h"
#include <QPushButton>
//--------------------------------------------------------------------- :Global:
//                            ___ _     _          _ 
//                           / __| |___| |__  __ _| |
//                          | (_ | / _ \ '_ \/ _` | |
//                           \___|_\___/_.__/\__,_|_|
//                                                   
// -----------------------------------------------------------------------------


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Set up User Interface
    ui->setupUi(this);
    this->DeleteButtonInit();

    //QPushButton *deleteButton = new QPushButton(this);
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
 *  @brief Initializes the on default "off state" buton.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::DeleteButtonInit()
{
    this->deleteButton = new QPushButton(this);
    this->deleteButton->setMinimumWidth(500);
    this->deleteButton->setMinimumHeight(300);
    this->deleteButton->setStyleSheet("background-color: rgb(0, 0, 0);");
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(DeleteButtonHide()));
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Hides the "off state" button.
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::DeleteButtonHide()
{
    this->deleteButton->setVisible(false);
    
}

void MainWindow::on_offButton_clicked()
{
    this->deleteButton->setVisible(true);
}
