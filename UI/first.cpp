#include "first.h"
#include "ui_first.h"
#include <QPainter>
#include <QDateTime>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include "check.h"
#include "ok.h"
#include <QPushButton>
#include <QLabel>
#include <QAction>
#include "mypaint.h"
#include "paint.h"

//构造函数

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
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;font-weight:bold;border-image: url(:/image/bt.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:15px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->h->setStyleSheet("background:transparent;border-image: url(:/image/h.png);");

    ui->date->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/90)+"px;background:transparent;");
    ui->time->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/90)+"px;background:transparent;");

    QDateTime *d=new QDateTime(QDateTime::currentDateTime());
    ui->date->setText(d->date().toString("yyyy.MM.dd"));
    ui->time->setText(d->time().toString("hh:mm:ss"));
    ui->in->setCurrentIndex(10);
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        changeTime();

    });
    timer->start(1000);



    ui->iderr->setText("ID无法更改！");
    ui->areaerr->setText("地区无法更改！");
    ui->powerr->setText("角色无法更改！");
    ui->phonein->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));


    ui->imshow->hide();















}

First::~First()
{
    delete ui;
}


//构造函数结束


//获取实时时间
void First::changeTime()
{
    QDateTime *d=new QDateTime(QDateTime::currentDateTime());
    ui->date->setText(d->date().toString("yyyy.MM.dd"));
    ui->time->setText(d->time().toString("hh:mm:ss"));
}



//主菜单栏初始化
void First::on_notice_clicked()
{
    ui->in->setCurrentIndex(6);
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");

    setUpNotice();
}

void First::on_forum_clicked()
{
    ui->in->setCurrentIndex(0);
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}

void First::on_letter_clicked()
{
    ui->in->setCurrentIndex(1);
    ui->message->setCurrentIndex(0);
    ui->midin->setText("");
    ui->textin->setPlainText("");
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    setUpLetter();
}

void First::on_expert_clicked()
{
    ui->in->setCurrentIndex(2);
    ui->expertpage->setCurrentIndex(0);
    ui->exin->setPlainText("");
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    setUpExpert();
}

void First::on_help_clicked()
{
    ui->in->setCurrentIndex(3);
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}

void First::on_h_clicked()
{
     ui->in->setCurrentIndex(4);
     ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}


void First::on_func_clicked()
{
    ui->in->setCurrentIndex(5);
    ui->sub->setDisabled(true);
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
}

//主菜单栏初始化结束


//重新绘制函数
void First::paintEvent ( QPaintEvent *e )
{
//    QPainter painter1(ui);
//    painter.drawPixmap(rect(),QPixmap(":/image/First.jpg"),QRect());

    ui->wel->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/30)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->wel->resize(ui->in->width()*9/10,ui->in->height()/10);
    ui->wel->move(this->width()/2-ui->wel->width()/2,ui->in->height()/2-ui->wel->height()/2);
    ui->left->resize(this->width()/4,this->height()*9/10);
    ui->in->resize(this->width()*3/4,this->height());
    ui->d->resize(this->width()/4,this->height()/10);
    ui->d->move(0,this->height()*9/10);
    ui->in->move(this->width()/4,0);
    ui->date->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/90)+"px;background:transparent;");
    ui->time->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/90)+"px;background:transparent;");
    ui->exit->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/90)+"px;background:transparent;");
    switch (ui->in->currentIndex()) {
    case 6:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 0:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 1:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 2:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 3:
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 4:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 5:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
        ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        break;
    case 10:
        ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
        ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
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

    ui->page1->resize(ui->in->width()/2,ui->in->height()/8);
    ui->page2->resize(ui->in->width()/2,ui->in->height()/8);
    ui->page3->resize(ui->in->width()/2,ui->in->height()/8);
    ui->page4->resize(ui->in->width()/2,ui->in->height()/8);

    ui->page1->move(ui->in->width()-ui->page1->width(),ui->in->height()/20);
    ui->page2->move(ui->in->width()-ui->page2->width(),ui->in->height()/20);
    ui->page3->move(ui->in->width()-ui->page3->width(),ui->in->height()/20);
    ui->page4->move(ui->in->width()-ui->page4->width(),ui->in->height()/20);


    ui->choose->setStyleSheet("background:transparent;border-image: url(:/image/h.png);");
    ui->choosebt->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    ui->imain->setStyleSheet("border-image: url(:/image/in.jpg)");
    ui->imain->setDisabled(true);

    ui->choose->resize(ui->in->width()*9/10,ui->in->height()/5);
    ui->choose->move(ui->in->width()/20,ui->in->height()/20);
    ui->result->setStyleSheet("background:transparent;border-image: url(:/image/h.png);");
    ui->result->resize(ui->in->width()*7/10,ui->in->height()/10);
    ui->result->move(ui->in->width()*5/20,ui->in->height()*17/20);
    ui->sub->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");

    ui->notice1->setStyleSheet("border-image: url(:/image/notice.jpg);");
    ui->notice1->resize(ui->in->width(),ui->in->height()*8/10);
    ui->notice1->move(0,ui->in->height()/8+ui->in->height()/20);

    ui->notice2->setStyleSheet("border-image: url(:/image/notice.jpg);");
    ui->notice2->resize(ui->in->width(),ui->in->height()*8/10);
    ui->notice2->move(0,ui->in->height()/8+ui->in->height()/20);

    ui->notice3->setStyleSheet("border-image: url(:/image/notice.jpg);");
    ui->notice3->resize(ui->in->width(),ui->in->height()*8/10);
    ui->notice3->move(0,ui->in->height()/8+ui->in->height()/20);

    ui->notice4->setStyleSheet("border-image: url(:/image/notice.jpg);");
    ui->notice4->resize(ui->in->width(),ui->in->height()*8/10);
    ui->notice4->move(0,ui->in->height()/8+ui->in->height()/20);


    ui->message->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");

    ui->mbts->resize(ui->message->width()/5,ui->message->height()/2);
    ui->mbts->move(ui->message->width()/8,ui->message->height()/10);

    ui->w->resize(ui->mbts->width()*8/10,ui->mbts->height()/6);
    ui->r->resize(ui->mbts->width()*8/10,ui->mbts->height()/6);
    ui->s->resize(ui->mbts->width()*8/10,ui->mbts->height()/6);

    ui->w->setStyleSheet("border-image: url(:/image/btbt.png)");
    ui->r->setStyleSheet("border-image: url(:/image/btbt.png)");
    ui->s->setStyleSheet("border-image: url(:/image/btbt.png)");


    ui->midin->setStyleSheet("border-image: url(:/image/nin.jpg)");
    ui->textin->setStyleSheet("border-image: url(:/image/nin.jpg)");
    ui->sendbt->setStyleSheet("border-image: url(:/image/btbt.png)");
    ui->re1->setStyleSheet("border-image: url(:/image/btbt.png)");


    ui->reshow->resize(ui->in->width(),ui->in->height()*8/10);
    ui->reshow->move(0,ui->in->height()/8+ui->in->height()/20);
    ui->rebts->resize(ui->receivepage->width(),ui->receivepage->height()/10);
    ui->rebts->move(0,ui->rebts->height()/2);
    ui->re2->setStyleSheet("border-image: url(:/image/btbt.png)");


    ui->sendshow->resize(ui->in->width(),ui->in->height()*8/10);
    ui->sendshow->move(0,ui->in->height()/8+ui->in->height()/20);
    ui->sebts->resize(ui->sendpage->width(),ui->sendpage->height()/10);
    ui->sebts->move(0,ui->sebts->height()/2);
    ui->re3->setStyleSheet("border-image: url(:/image/btbt.png)");






    ui->expertpage->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->expertcho->setStyleSheet("border-image: url(:/image/btbt.png)");
    ui->exprebt->setStyleSheet("border-image: url(:/image/btbt.png)");
    ui->exin->setStyleSheet("border-image: url(:/image/nin.jpg)");
    ui->exsub->setStyleSheet("border-image: url(:/image/btbt.png)");

    ui->exre1->setStyleSheet("border-image: url(:/image/btbt.png)");
    ui->exbts->resize(ui->expertpage->width(),ui->expertpage->height()/10);
    ui->exbts->move(0,ui->exbts->height()/2);

    ui->expreshow->resize(ui->in->width(),ui->in->height()*8/10);
    ui->expreshow->move(0,ui->in->height()/8+ui->in->height()/20);



}

//重新绘制函数结束



//个人信息修改

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
            ok o("修改成功！",this);
            o.exec();
            change();
        }
    }

}


void First::receiveData(QString data)
{
     if(data=="alter")
     {
         change();
     }
     else
     {
         this->ntno=data;
         getNotice();
     }
}

void First::change()
{
    qDebug()<<"111";
}

void First::getNotice()
{
    qDebug()<<this->ntno;
}

QStringList First::getNoticeList()
{
    QStringList list;
    list<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"<<"17"<<"18";
    return list;
}

//公告通知功能
//建立通知
void First::setUpNotice()
{
    this->noticeList=getNoticeList();
    int count=noticeList.count();
    int pagenum;
    if (count%5!=0) pagenum=count/5+1;
    else pagenum=count/5;

    ui->tishi1->setText("第1页，共"+QString::number(pagenum)+"页");
    ui->tishi2->setText("第2页，共"+QString::number(pagenum)+"页");
    ui->tishi3->setText("第3页，共"+QString::number(pagenum)+"页");
    ui->tishi4->setText("第4页，共"+QString::number(pagenum)+"页");

    ui->page1->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/h.png);");
    ui->page2->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/h.png);");
    ui->page3->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/h.png);");
    ui->page4->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/h.png);");


    qDebug()<<pagenum;

    switch (pagenum) {
    case 1:
        ui->next1->hide();
        ui->last1->hide();
        ui->page2->setDisabled(true);
        ui->page3->setDisabled(true);
        ui->page4->setDisabled(true);
        break;
    case 2:
        ui->next1->show();
        ui->last1->show();
        ui->next2->hide();
        ui->last2->hide();
        ui->page2->setEnabled(true);
        ui->page3->setDisabled(true);
        ui->page4->setDisabled(true);
        break;
    case 3:
        ui->next1->show();
        ui->last1->show();
        ui->next2->show();
        ui->last2->show();
        ui->next3->hide();
        ui->last3->hide();
        ui->page2->setEnabled(true);
        ui->page3->setEnabled(true);
        ui->page4->setDisabled(true);
        break;
    case 4:
        ui->next1->show();
        ui->last1->show();
        ui->next2->show();
        ui->last2->show();
        ui->next3->show();
        ui->last3->show();
        ui->page2->setEnabled(true);
        ui->page2->setEnabled(true);
        ui->page3->setEnabled(true);
        break;
    default:
        break;
    }

    QLabel *label1=new QLabel(ui->notice1);
    QLabel *label2=new QLabel(ui->notice2);
    QLabel *label3=new QLabel(ui->notice3);
    QLabel *label4=new QLabel(ui->notice4);

    label1->setStyleSheet("border-image: url(:/image/notice.jpg);");
    label1->resize(ui->notice1->width(),ui->notice1->height());
    label2->setStyleSheet("border-image: url(:/image/notice.jpg);");
    label2->resize(ui->notice2->width(),ui->notice2->height());
    label3->setStyleSheet("border-image: url(:/image/notice.jpg);");
    label3->resize(ui->notice3->width(),ui->notice3->height());
    label4->setStyleSheet("border-image: url(:/image/notice.jpg);");
    label4->resize(ui->notice4->width(),ui->notice4->height());

    label1->show();
    label2->show();
    label3->show();
    label4->show();

    int i=0;
    for (int j=0;j<5;j++)
    {
        if(j>=count) break;

        QPushButton *bt=new QPushButton(ui->notice1);
        bt->resize(ui->notice1->width()*9/10,ui->in->height()/10);
        bt->move(ui->notice1->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        bt->setStyleSheet("border-image: url(:/image/btbt.png);");
        bt->show();
        QLabel *label=new QLabel(ui->notice1);
        label->resize(ui->notice1->width()*9/10,bt->height());
        label->setText(this->noticeList[j]);
        label->move(ui->notice1->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/35)+"px;border-image: url(:/image/btbt.png);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
              qDebug()<<label->text();
        });
        i++;

    }

    i=0;
    for (int j=5;j<10;j++)
    {
        if(j>=count) break;

        QPushButton *bt=new QPushButton(ui->notice2);
        bt->resize(ui->notice2->width()*9/10,ui->in->height()/10);
        bt->move(ui->notice2->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        bt->setStyleSheet("border-image: url(:/image/btbt.png);");
        bt->show();
        QLabel *label=new QLabel(ui->notice2);
        label->resize(ui->notice2->width()*9/10,bt->height());
        label->setText(this->noticeList[j]);
        label->move(ui->notice2->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/35)+"px;border-image: url(:/image/btbt.png);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
              qDebug()<<label->text();
        });
        i++;

    }


    i=0;
    for (int j=10;j<15;j++)
    {
        if(j>=count) break;

        QPushButton *bt=new QPushButton(ui->notice3);
        bt->resize(ui->notice3->width()*9/10,ui->in->height()/10);
        bt->move(ui->notice3->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        bt->setStyleSheet("border-image: url(:/image/btbt.png);");
        bt->show();
        QLabel *label=new QLabel(ui->notice3);
        label->resize(ui->notice3->width()*9/10,bt->height());
        label->setText(this->noticeList[j]);
        label->move(ui->notice3->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/35)+"px;border-image: url(:/image/btbt.png);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
              qDebug()<<label->text();
        });
        i++;

    }

    i=0;
    for (int j=15;j<20;j++)
    {
        if(j>=count) break;

        QPushButton *bt=new QPushButton(ui->notice4);
        bt->resize(ui->notice4->width()*9/10,ui->in->height()/10);
        bt->move(ui->notice4->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        bt->setStyleSheet("border-image: url(:/image/btbt.png);");
        bt->show();
        QLabel *label=new QLabel(ui->notice4);
        label->resize(ui->notice4->width()*9/10,bt->height());
        label->setText(this->noticeList[j]);
        label->move(ui->notice4->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/35)+"px;border-image: url(:/image/btbt.png);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
              qDebug()<<label->text();
        });
        i++;

    }




}
//获取最后一页
void First::getLast()
{
    if (ui->page4->isEnabled()) ui->in->setCurrentIndex(9);
    else if(ui->page3->isEnabled()) ui->in->setCurrentIndex(8);
    else if(ui->page2->isEnabled()) ui->in->setCurrentIndex(7);
}
void First::on_next1_clicked()
{
    ui->in->setCurrentIndex(7);
}

void First::on_last1_clicked()
{
    getLast();
}

void First::on_first2_clicked()
{
    ui->in->setCurrentIndex(6);
}

void First::on_pre2_clicked()
{
    ui->in->setCurrentIndex(6);
}

void First::on_next2_clicked()
{
    ui->in->setCurrentIndex(8);
}

void First::on_last2_clicked()
{
    getLast();
}

void First::on_first3_clicked()
{
    ui->in->setCurrentIndex(6);
}

void First::on_pre3_clicked()
{
    ui->in->setCurrentIndex(7);
}

void First::on_next3_clicked()
{
    ui->in->setCurrentIndex(9);
}

void First::on_last3_clicked()
{
    getLast();
}

void First::on_first4_clicked()
{
    ui->in->setCurrentIndex(6);
}

void First::on_pre4_clicked()
{
    ui->in->setCurrentIndex(8);
}


//退出按钮
void First::on_exit_clicked()
{
    this->close();
}


//核心功能
//选择图片
void First::on_choosebt_clicked()
{
    QString filePath= QFileDialog::getOpenFileName(this,"选择文件","","(*.jpg *.jpeg *.png *.bmp)");
//    ui->imain->setDisabled(true);
//    ui->imain->setText(filePath);
//    Paint *p=new Paint(filePath);
//    p->show();
    ui->imain->setText("  "+filePath);

    QImage im;
    im.load(filePath);
    int x=im.width();
    int y=im.height();
    qDebug()<<x<<y;
    double s=y/x;
    while(x>ui->in->width())
    {
        x=x*9/10;
    }
    y=x*s;
    if (y>ui->in->height()/2)
    {
        while(y>ui->in->height()*3/4)
        {
            y=y*9/10;
        }
        x=y/s;
    }
    qDebug()<<x<<y;
    ui->imshow->resize(x,y);
    ui->imshow->move(ui->in->width()/2-ui->imshow->width()/2,ui->in->height()/2-ui->imshow->height()/2);
    ui->imshow->setStyleSheet("border-image: url("+filePath+");");
    ui->imshow->show();
    //ui->image->setPixmap(QPixmap(filePath));
    qDebug()<<ui->imshow->width()<<ui->imshow->height();
    ui->sub->setEnabled(true);

}
//提交判断
void First::on_sub_clicked()
{
    ui->con->setText("蝗虫");
}




//站内信功能
//初始化
void First::on_w_clicked()
{
    ui->message->setCurrentIndex(1);
}


//初始化
void First::on_r_clicked()
{
    QStringList list;
    list<<"1"<<"2"<<"3"<<"4"<<"1"<<"2"<<"3"<<"4"<<"1"<<"2"<<"3"<<"4";

    QLabel *label1=new QLabel(ui->reshow);

    label1->setStyleSheet("border-image: url(:/image/notice.jpg);");
    label1->resize(ui->reshow->width(),ui->reshow->height());

    label1->show();
    int i=0;
    for (int j=0;j<7;j++)
    {
        if(j>=list.count()) break;

        QPushButton *bt=new QPushButton(ui->reshow);
        bt->resize(ui->reshow->width()*9/10,ui->reshow->height()/10);
        bt->move(ui->reshow->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        bt->setStyleSheet("border-image: url(:/image/in.jpg);");
        bt->show();
        QLabel *l=new QLabel(ui->reshow);
        l->setText(QString::number(i));
        QLabel *label=new QLabel(ui->reshow);
        label->resize(bt->width(),bt->height());
        label->setText("  "+list[j]);
        label->move(ui->reshow->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/35)+"px;border-image: url(:/image/in.jpg);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
            showExpert(l->text());
            qDebug()<<l->text();
        });
        i++;

    }


    ui->message->setCurrentIndex(2);
}

void First::on_s_clicked()
{
    ui->message->setCurrentIndex(3);
}

void First::on_re1_clicked()
{
    ui->message->setCurrentIndex(0);
}

void First::on_re3_clicked()
{
    ui->message->setCurrentIndex(0);
}

void First::on_re2_clicked()
{
    ui->message->setCurrentIndex(0);
}

void First::on_rere_clicked()
{
    ui->receivepage->setCurrentIndex(0);
}

void First::on_sre1_clicked()
{
    ui->sendpage->setCurrentIndex(0);
}

//写信
void First::on_sendbt_clicked()
{
    bool flag=true;
    if(ui->midin->text()==""||ui->textin->toPlainText()=="")
    {
        ui->merr->setText("请输入对方id或信件内容");
        ui->merr->setStyleSheet("color:rgb(255,0,0);");
        flag=false;
    }
    if(flag)
    {
        qDebug()<<ui->textin->toPlainText();
        ok o("发送成功！",this);
        o.exec();
        ui->midin->setText("");
        ui->textin->setPlainText("");
        ui->message->setCurrentIndex(0);
    }

}

void First::setUpLetter()
{

}







//专家咨询功能
//查看历史咨询
void First::on_exprebt_clicked()
{
    QStringList list;
    list<<"1"<<"2"<<"3"<<"4"<<"1"<<"2"<<"3"<<"4"<<"1"<<"2"<<"3"<<"4";

    QLabel *label1=new QLabel(ui->expreshow);

    label1->setStyleSheet("border-image: url(:/image/notice.jpg);");
    label1->resize(ui->expreshow->width(),ui->expreshow->height());

    label1->show();
    int i=0;
    for (int j=0;j<7;j++)
    {
        if(j>=list.count()) break;

        QPushButton *bt=new QPushButton(ui->expreshow);
        bt->resize(ui->expreshow->width()*9/10,ui->expreshow->height()/10);
        bt->move(ui->expreshow->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        bt->setStyleSheet("border-image: url(:/image/in.jpg);");
        bt->show();
        QLabel *l=new QLabel(ui->expreshow);
        l->setText(QString::number(i));
        QLabel *label=new QLabel(ui->expreshow);
        label->resize(bt->width(),bt->height());
        label->setText("  "+list[j]);
        label->move(ui->expreshow->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/35)+"px;border-image: url(:/image/in.jpg);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
            showExpert(l->text());
            qDebug()<<l->text();
        });
        i++;

    }



    ui->expertpage->setCurrentIndex(1);
}

//查看咨询详情
void First::showExpert(QString no)
{




}


//建立专家咨询
void First::setUpExpert()
{
    QStringList list;
    list<<"..."<<"专家1"<<"专家2";
    ui->expertcho->addItems(list);


}

void First::on_exre1_clicked()
{
    ui->expertpage->setCurrentIndex(0);
}








