#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include "res.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->background->setPixmap(QPixmap(":/image/First.jpg"));
    ui->num->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->pas->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->numin->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->pasin->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->reg->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;");
    ui->forget->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;");
    ui->ok->setStyleSheet("color:rgb(0, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    connect(ui->reg,&QPushButton::clicked,[=](){
        res *r=new res();
        r->show();
        r->setAttribute(Qt::WA_DeleteOnClose);
    });


}


MainWindow::~MainWindow()
{
    delete ui;
}
