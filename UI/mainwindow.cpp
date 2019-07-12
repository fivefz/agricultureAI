#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include "res.h"
#include "first.h"
#include <QPainter>
#include "network.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette pal(palette());
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/image/First.jpg")));
    setPalette(pal);
    ui->num->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->pas->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->numin->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->pasin->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->reg->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;");
    ui->forget->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;");
    ui->ok->setStyleSheet("color:rgb(0, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    ui->in->move(this->width()*0.5-ui->in->width()*0.5,this->height()*0.4);


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

void MainWindow::on_ok_clicked()
{
    bool flag=true;
    if(ui->numin->text()==""||ui->pasin->text()==""){
        flag=false;
        ui->err->setAlignment(Qt::AlignHCenter);
        ui->err->setText("请输入账号和密码！");
        ui->err->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else ui->err->setText("");

    if(flag){

        //QString res=ui->numin->text()+ui->pasin->text();
//        Socket s;
//        s.startConnect();

        QStringList list;
        list<<ui->numin->text()<<ui->pasin->text();

        Network n;
        QString res=QString(n.doPost(list));

//        this->setPow(ui->numin->text());
//        this->setID(ui->numin->text());

        if(res!="1"){
            ui->err->setAlignment(Qt::AlignHCenter);
            ui->err->setText("账号或密码错误！");
            ui->err->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
        }
        else {
            First *f=new First(this->getID(),this->getPow());
            f->show();
            this->close();
        }


    }



}

void MainWindow::paintEvent ( QPaintEvent *e )
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/image/First.jpg"),QRect());
    ui->in->move(this->width()*0.5-ui->in->width()*0.5,this->height()*0.4);
}

void MainWindow::on_forget_clicked()
{

}
