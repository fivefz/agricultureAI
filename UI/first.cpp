#include "first.h"
#include "ui_first.h"
#include <QPainter>
#include <QDateTime>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include "check.h"
#include "ok.h"

First::First(QString i,QString p,QWidget *parent) :
    ID(i),pow(p),
    QWidget(parent),
    ui(new Ui::First)
{
    ui->setupUi(this);
//    QPixmap pixmap("E:\\QTProject\\Agricultural\\image\\First.jpg");//这个图片路径写自己的.
//    QPalette palette=this->palette();
//    palette.setBrush(QPalette::Background,QBrush(pixmap));
//    this->setPalette(palette);


//       this->setStyleSheet("background-image: url(:/image/First.jpg)");
//    QPalette pal(palette());
//    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/image/left.jpg")));
//    ui->left->setPalette(pal);
//    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/image/right.jpg")));
//    ui->in->setPalette(pal);
//    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/image/date.jpg")));
//    ui->d->setPalette(pal);
//    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/image/head.png")));
//    ui->head->setPalette(pal);


    if(this->getPow()=="1")
    {
        ui->func->setText("病虫害识别");
    }
    else ui->func->setText("农田统计");

    ui->left->setStyleSheet("border-image: url(:/image/left.jpg)");
    ui->in->setStyleSheet("border-image: url(:/image/right.jpg)");
    ui->d->setStyleSheet("border-image: url(:/image/date.jpg)");
    ui->head->setStyleSheet("border-image: url(:/image/head.png)");

    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->h->setStyleSheet("background:transparent;border-image: url(:/image/h.png);");

    ui->date->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/90)+"px;background:transparent;");
    ui->time->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/90)+"px;background:transparent;");

    ui->in->setCurrentIndex(0);
    QTimer *time_clock=new QTimer(parent);
    connect(time_clock,SIGNAL(timeout()),this,SLOT(changeTime()));
    time_clock->start(1);
    QDateTime *d=new QDateTime(QDateTime::currentDateTime());
    ui->date->setText(d->date().toString("yyyy.MM.dd"));
    ui->time->setText(d->time().toString("hh:mm:ss"));


    ui->iderr->setText("ID无法更改！");
    ui->areaerr->setText("地区无法更改！");
    ui->powerr->setText("角色无法更改！");


















}

First::~First()
{
    delete ui;
}

void First::changeTime()
{
    QDateTime *d=new QDateTime(QDateTime::currentDateTime());
    ui->date->setText(d->date().toString());
    ui->time->setText(d->time().toString());
}

void First::on_notice_clicked()
{
    ui->in->setCurrentIndex(0);
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}

void First::on_forum_clicked()
{
    ui->in->setCurrentIndex(1);
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}

void First::on_letter_clicked()
{
    ui->in->setCurrentIndex(2);
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}

void First::on_expert_clicked()
{
    ui->in->setCurrentIndex(3);
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}

void First::on_help_clicked()
{
    ui->in->setCurrentIndex(4);
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}

void First::on_h_clicked()
{
     ui->in->setCurrentIndex(5);
     ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}


void First::on_func_clicked()
{
    ui->in->setCurrentIndex(6);
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}

void First::paintEvent ( QPaintEvent *e )
{
//    QPainter painter1(ui);
//    painter.drawPixmap(rect(),QPixmap(":/image/First.jpg"),QRect());


    ui->left->resize(this->width()/4,this->height()*9/10);
    ui->in->resize(this->width()*3/4,this->height());
    ui->d->resize(this->width()/4,this->height()/10);
    ui->d->move(0,this->height()*9/10);
    ui->in->move(this->width()/4,0);
    ui->date->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/90)+"px;background:transparent;");
    ui->time->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/90)+"px;background:transparent;");
    switch (ui->in->currentIndex()) {
    case 0:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 1:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 2:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 3:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 4:
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 5:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 6:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    default:
        break;
    }

    ui->head->resize(ui->left->width()/2,ui->left->width()/2);
    ui->help->resize(ui->left->width(),ui->left->height()/12);
    ui->expert->resize(ui->left->width(),ui->left->height()/12);
    ui->forum->resize(ui->left->width(),ui->left->height()/12);
    ui->notice->resize(ui->left->width(),ui->left->height()/12);
    ui->letter->resize(ui->left->width(),ui->left->height()/12);
    ui->func->resize(ui->left->width(),ui->left->height()/12);

    ui->h->resize(ui->head->width(),ui->head->height());


    ui->head->move(ui->left->width()/2-ui->head->width()/2,ui->head->width()/4);

    ui->notice->move(0,ui->head->height()+ui->left->height()/8);
    ui->forum->move(0,ui->head->height()+ui->left->height()/8+ui->left->height()/12+ui->left->height()/60);
    ui->func->move(0,ui->head->height()+ui->left->height()/8+ui->left->height()*2/12+ui->left->height()*2/60);
    ui->letter->move(0,ui->head->height()+ui->left->height()/8+ui->left->height()*3/12+ui->left->height()*3/60);
    ui->expert->move(0,ui->head->height()+ui->left->height()/8+ui->left->height()*4/12+ui->left->height()*4/60);
    ui->help->move(0,ui->head->height()+ui->left->height()/8+ui->left->height()*5/12+ui->left->height()*5/60);


    //个人信息修改
    ui->table->resize(ui->in->width()*3/4,ui->in->height()*3/4);
    ui->table->move(ui->in->width()/2-ui->table->width()/2,ui->in->height()/2-ui->table->height()/2);
    ui->table->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->iderr->setStyleSheet("color:rgb(255, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->areaerr->setStyleSheet("color:rgb(255, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->powerr->setStyleSheet("color:rgb(255, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    if (ui->alter->isEnabled())
    {
        ui->alter->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
        ui->submit->hide();
        ui->cancel->hide();
        ui->thr->hide();
    }
    else
    {
        ui->alter->hide();
        ui->submit->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
        ui->alter->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    }
}





void First::on_alter_clicked()
{
    ui->alter->setDisabled(true);
    ui->alter->hide();
    ui->submit->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    ui->cancel->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    ui->namein->setStyleSheet("border-image: url(:/image/in.jpg)");
    ui->pasin->setStyleSheet("border-image: url(:/image/in.jpg)");
    ui->phonein->setStyleSheet("border-image: url(:/image/in.jpg)");
    ui->addrin->setStyleSheet("border-image: url(:/image/in.jpg)");
    ui->thr->show();
    ui->submit->show();
    ui->cancel->show();


}

void First::on_cancel_clicked()
{
    ui->alter->setEnabled(true);
    ui->submit->hide();
    ui->cancel->hide();
    ui->thr->hide();
    ui->alter->show();
}

void First::on_submit_clicked()
{
    bool flag=true;
    if(ui->addrin->text()==""&&ui->phonein->text()==""&&ui->namein->text()=="")
    {
        ui->err->setText("未修改任何内容");
        flag=false;
    }
    else
    {
        if(ui->addrin->text()!="")
        {
            if(!ui->addrin->text().contains("@"))
            {
                ui->err->setText("邮箱格式错误！");
                flag=false;
            }
        }
        else if (ui->phonein->text()!="")
        {
            if(ui->phonein->text().count()!=11)
            {
                ui->err->setText("手机号格式错误！");
                flag=false;
            }
        }
    }

    if(flag)
    {
        if(ui->addrin->text()!="")
        {
            check *c=new check("111",ui->addrin->text());
            c->setWindowModality(Qt::ApplicationModal);
            connect(c, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            c->show();
        }
        else
        {
            ok o(this);
            o.exec();
            change();
        }
    }

}


void First::receiveData(QString data)
{
     if(data=="1")
     {
         change();
     }
}

void First::change()
{
    qDebug()<<"111";
}
