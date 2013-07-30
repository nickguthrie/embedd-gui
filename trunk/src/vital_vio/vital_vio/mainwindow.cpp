////////////////////////////////////////////////////////////////////////////////
/**
 *  @file mainwindow.cpp
 *  @brief A basic Vital Vio Controller.
 *
 *  Detailed Description
 *
 *  @title Vital Vio
 *  @author Nicholas Guthrie
 *  @web http//nickguthrie.com/embedd_gui/doc/
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
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Sets up the Main Interface.
 */
////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Set up User Interface
    ui->setupUi(this);
    this->DeleteButtonInit();
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
    //this->deleteButton->setStyleSheet("background-color: rgb(90, 90, 90);border-color: rgb(170, 0, 0);");
                                       
    this->deleteButton->setMinimumSize(280,172);
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
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Makes the screen go blank (turns the lights off).
 */
////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_offButton_clicked()
{
    this->deleteButton->setVisible(true);
}
