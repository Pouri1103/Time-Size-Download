#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->le_net,&QLineEdit::textEdited,this,&MainWindow::box1);
    connect(ui->le_speed,&QLineEdit::textEdited,this,&MainWindow::box1);

    connect(ui->le_time_2,&QLineEdit::textEdited,this,&MainWindow::box2);
    connect(ui->le_speed_2,&QLineEdit::textEdited,this,&MainWindow::box2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//---------------------------------------------

void MainWindow::box1()
{
    float time = (ui->le_net->text().toFloat()/(ui->le_speed->text().toFloat()/1000))/60;
    if (time < 60)
        ui->le_time->setText(QString::number(time,'f',2));
    else
        ui->le_time->setText("(" + QString::number(time/60,'f',2) + ")h");
}

//---------------------------------------------

void MainWindow::box2()
{
    ui->le_net_2->setText(QString::number((ui->le_time_2->text().toFloat()*60) * (ui->le_speed_2->text().toFloat()/1000),'f',2));
}

//---------------------------------------------
