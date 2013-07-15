#include "mainwindow.h"
#include "ui_mainwindow.h"

#define INCRAMENT 10

int PUSHED;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    PUSHED = 0;
    ui->setupUi(this);
    ui->progressBar->setValue(1);
    ui->progressBar->setRange(-1,101);

    /*connect(ui->verticalSlider,SIGNAL(valueChanged(int)),
      ui->progressBar,SLOT(setValue(int))); */
                                    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_up_pressed()
{
    ui->pb_up->setText("Pushed");
    if(PUSHED < 100)
	PUSHED += INCRAMENT;
    ui->progressBar->setValue(PUSHED);
}

void MainWindow::on_pb_down_pressed()
{
    if(PUSHED >= INCRAMENT)
	PUSHED -= INCRAMENT;
   ui->progressBar->setValue(PUSHED);
}
