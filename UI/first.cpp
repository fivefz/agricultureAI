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
#include "network.h"
#include <QJsonObject>
#include <iterator>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QVariantList>
#include <QVariantMap>
#include <QDesktopServices>
#include <QUrl>
#include <QPalette>
#include <QBrush>
#include <QPixmap>


//构造函数

First::First(QString i,QString p,QWidget *parent) :
    ID(i),pow(p),
    QWidget(parent),
    ui(new Ui::First)
{
    ui->setupUi(this);

    qDebug()<<"当前ID："+this->ID;

    if(this->getPow()=="farmer")
    {
        ui->func->setText("病虫害识别");
        ui->pushButton->hide();
    }
    else if(this->getPow()=="officer")
    {
        ui->func->setText("农田统计");
        ui->pushButton->show();
    }

    Network n;
    this->imagePath=n.doImageGet(this->ID);

    qDebug()<<"**********当前头像存储位置："+ this->imagePath;

    setWindowTitle("多人农业图像分析平台");
    setWindowIcon(QIcon(QPixmap(":/image/First.jpg")));

    ui->left->setStyleSheet("border-image: url(:/image/left.jpg)");
    ui->in->setStyleSheet("border-image: url(:/image/right.jpg)");
    ui->d->setStyleSheet("border-image: url(:/image/date.jpg)");

    ui->head->setStyleSheet("border-image: url("+this->imagePath+");");
    ui->head->show();





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

//********************************************************************************************************
//个人资料修改
//入口初始化
void First::on_h_clicked()
{
     setUpInfo();
     ui->alter->show();
     ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
     ui->in->setCurrentIndex(4);
}
//当前资料获得
void First::setUpInfo()
{
    Network n;
    QJsonObject result= QJsonDocument::fromJson(n.doGet("personalInfo/"+this->ID)).object();
    qDebug()<<"first输出："+result.value("id").toInt();
    ui->idout->setText(QString::number(result.value("id").toInt()));
    ui->addrout->setText(result.value("email").toString());
    ui->areaout->setText(result.value("province").toString()+result.value("city").toString());
    ui->nameout->setText(result.value("userName").toString());
    ui->pasout->setText(result.value("password").toString());
    ui->phoneout->setText(result.value("phone").toString());
    ui->powout->setText(result.value("role").toString());
    ui->head->setStyleSheet("border-image: url("+this->imagePath+")");
    ui->submit->hide();
    ui->cancel->hide();
    ui->thr->hide();
    ui->headalter->hide();
    ui->phonein->setText("");
    ui->addrin->setText("");
    ui->namein->setText("");
    ui->pasin->setText("");
    this->imagePath=n.doImageGet(this->ID);
    QPalette pal(ui->head->palette());
    pal.setBrush(QPalette::Background, QBrush(QPixmap(imagePath)));
    ui->head->setPalette(pal);
}
//点击修改按键事件
void First::on_alter_clicked()
{
    ui->alter->setDisabled(true);
    ui->alter->hide();
    ui->submit->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    ui->headalter->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    ui->cancel->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    ui->namein->setStyleSheet("border-image: url(:/image/in.jpg)");
    ui->pasin->setStyleSheet("border-image: url(:/image/in.jpg)");
    ui->phonein->setStyleSheet("border-image: url(:/image/in.jpg)");
    ui->addrin->setStyleSheet("border-image: url(:/image/in.jpg)");
    ui->headalter->show();
    ui->thr->show();
    ui->submit->show();
    ui->cancel->show();
}
void First::on_cancel_clicked()
{
    ui->err->setText("");
    ui->alter->setEnabled(true);
    ui->submit->hide();
    ui->cancel->hide();
    ui->thr->hide();
    ui->headalter->hide();
    ui->alter->show();
    ui->phonein->setText("");
    ui->addrin->setText("");
    ui->namein->setText("");
    ui->pasin->setText("");
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
        list<<this->ID;
        if(ui->namein->text()!="") this->list<<ui->namein->text();
        else this->list<<ui->nameout->text();
        if(ui->pasin->text()!="") this->list<<ui->pasin->text();
        else this->list<<ui->pasout->text();
        if(ui->addrin->text()!="") this->list<<ui->addrin->text();
        else this->list<<ui->addrout->text();
        if(ui->phonein->text()!="") this->list<<ui->phonein->text();
        else this->list<<ui->phoneout->text();
        ui->err->setText("");
        if(ui->addrin->text()!="")
        {
            Network n;
            QStringList list;
            list<<""<<ui->addrin->text();
            QString code=QString(n.doPost("getcode",list));
            check *c=new check(code,ui->addrin->text());
            c->setWindowModality(Qt::ApplicationModal);
            connect(c, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            c->show();
        }
        else
        {
            change();
            ok o("修改成功！",this);
            o.exec();
            change();
        }
        ui->phonein->setText("");
        ui->addrin->setText("");
        ui->namein->setText("");
        ui->pasin->setText("");
        ui->submit->hide();
        ui->cancel->hide();
        ui->thr->hide();
        ui->headalter->hide();
        ui->alter->show();
    }


}
//验证码接受
void First::receiveData(QString data)
{
     if(data=="OK")
     {
         change();
         ok o("修改成功！");
         o.exec();
         ui->phonein->setText("");
         ui->addrin->setText("");
         ui->namein->setText("");
         ui->pasin->setText("");
         ui->submit->hide();
         ui->cancel->hide();
         ui->thr->hide();
         ui->headalter->hide();
         ui->alter->show();
     }
}
//修改
void First::change()
{
    Network n;
    n.doPost("editpersonalInfo",this->list);

}
//修改头像
void First::on_headalter_clicked()
{
    QString filePath= QFileDialog::getOpenFileName(this,"选择文件","","(*.jpg)");
    Network n;
    n.doImagePost(filePath,this->ID);
    ok o("修改成功");
    o.exec();
}


//********************************************************************************************************



//********************************************************************************************************
//通知公告
//入口初始化
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
//当前通知列表获得
QStringList First::getNoticeList()
{
    Network n;
    QByteArray result=n.doGet("notify");
    QStringList noticeList;

    QJsonDocument document2=QJsonDocument::fromJson(result);
    QJsonArray array2 = document2.array();

   for(int i = 0; i<array2.count(); i++)
      {
            QJsonObject now=array2.at(i).toObject();
            qDebug()<<"当前通知id："+QString::number(now.value("id").toInt());
            this->noticeNo[i]=QString::number(now.value("id").toInt());

            QString s=(now.value("publisher").toObject()).value("userName").toString()
                    +now.value("title").toString()
                    +now.value("publishDate").toString();
            noticeList<<s;
        }

    return noticeList;
}
//通知列表建立
void First::setUpNotice()
{
    QStringList noticeList=getNoticeList();
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
    ui->pushButton->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/h.png);");


    qDebug()<<pagenum;

    switch (pagenum) {
    case 0:
        ui->next1->hide();
        ui->last1->hide();
        ui->page2->setDisabled(true);
        ui->page3->setDisabled(true);
        ui->page4->setDisabled(true);
        break;
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
        label->setText(noticeList[j]);
        label->move(ui->notice1->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/70)+"px;border-image: url(:/image/btbt.png);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
              getNotice(j);
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
        label->setText(noticeList[j]);
        label->move(ui->notice2->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/70)+"px;border-image: url(:/image/btbt.png);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
              getNotice(j);
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
        label->setText(noticeList[j]);
        label->move(ui->notice3->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/70)+"px;border-image: url(:/image/btbt.png);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
              getNotice(j);
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
        label->setText(noticeList[j]);
        label->move(ui->notice4->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/70)+"px;border-image: url(:/image/btbt.png);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
              getNotice(j);
        });
        i++;

    }

}
//详细通知展示
void First::getNotice(int nno)
{
    Network n;
    QJsonObject result=QJsonDocument::fromJson(n.doGet("notify/"+this->noticeNo[nno])).object();

    ui->noticetitle->setText(result.value("title").toString());
    ui->noticename->setText((result.value("publisher").toObject()).value("userName").toString());
    ui->noticetime->setText(result.value("publishDate").toString());
    ui->noticecontent->setPlainText(result.value("content").toString());

    ui->in->setCurrentIndex(11);

}
//返回按键
void First::on_noticereturn_clicked()
{
    ui->in->setCurrentIndex(6);
}
//发通知
void First::on_noticeset_clicked()
{

}

//分页
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


//********************************************************************************************************



//********************************************************************************************************
//站内信
//入口初始化
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
}
//写信
void First::on_w_clicked()
{
    ui->message->setCurrentIndex(1);
}

void First::on_sendbt_clicked()
{
    bool flag=true;
    ui->merr->setStyleSheet("color:rgb(255,0,0);");
    if(ui->midin->text()==""||ui->textin->toPlainText()=="")
    {
        ui->merr->setText("请输入对方id或信件内容");
        flag=false;
    }
    if(flag)
    {
        Network n;
        QStringList list;
        list<<this->ID<<ui->midin->text()<<ui->textin->toPlainText();
        QString result=QString(n.doPost("sendmessage",list));
        if(result=="1")
        {
            ok o("发送成功！",this);
            o.exec();
            ui->midin->setText("");
            ui->textin->setPlainText("");
            ui->message->setCurrentIndex(0);
        }
        else if(result=="-1") ui->merr->setText("对方id不存在");
        else ui->merr->setText("发送失败");

    }

}
//收件箱
void First::on_r_clicked()
{
    QStringList list=getFromList();


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
        label->setStyleSheet("font-size:"+QString::number(this->width()/70)+"px;border-image: url(:/image/in.jpg);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
            showFromLetter(j);
        });
        i++;

    }
    ui->message->setCurrentIndex(2);
    ui->receivepage->setCurrentIndex(0);
}

QStringList First::getFromList()
{
    Network n;
    QByteArray result=n.doGet("inbox/"+this->ID);
    QStringList noticeList;

    QJsonDocument document2=QJsonDocument::fromJson(result);
    QJsonArray array2 = document2.array();

   for(int i = 0; i<array2.count(); i++)
      {
            QJsonObject now=array2.at(i).toObject();
            qDebug()<<"当前通知id："+QString::number(now.value("id").toInt());
            this->fromNo[i]=QString::number(now.value("id").toInt());
            QString status;
            if(now.value("readed").toBool()) status="已读";
            else   status="未读";
            QString s=QString::number(i+1)+". From:"
                    +(now.value("from").toObject()).value("userName").toString()
                    +"   Date:"
                    +now.value("data").toString()
                    +"   Status："
                    +status;
            noticeList<<s;
        }

    return noticeList;
}

void First::showFromLetter(int fno)
{
    Network n;
    QJsonObject result=QJsonDocument::fromJson(n.doGet("message/"+this->fromNo[fno])).object();
    QString status;
    if(result.value("readed").toBool()) status="已读";
    else   status="未读";
    ui->rname->setText((result.value("from").toObject()).value("userName").toString());
    ui->rdate->setText(result.value("date").toString());
    ui->rflag->setText(status);
    ui->rshow->setPlainText(result.value("content").toString());
    ui->receivepage->setCurrentIndex(1);
}

//发件箱
void First::on_s_clicked()
{
    QStringList list=getToList();


    QLabel *label1=new QLabel(ui->seshow);

    label1->setStyleSheet("border-image: url(:/image/notice.jpg);");
    label1->resize(ui->seshow->width(),ui->seshow->height());

    label1->show();
    int i=0;
    for (int j=0;j<7;j++)
    {
        if(j>=list.count()) break;

        QPushButton *bt=new QPushButton(ui->seshow);
        bt->resize(ui->seshow->width()*9/10,ui->seshow->height()/10);
        bt->move(ui->seshow->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        bt->setStyleSheet("border-image: url(:/image/in.jpg);");
        bt->show();
        QLabel *l=new QLabel(ui->seshow);
        l->setText(QString::number(i));
        QLabel *label=new QLabel(ui->seshow);
        label->resize(bt->width(),bt->height());
        label->setText("  "+list[j]);
        label->move(ui->seshow->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/70)+"px;border-image: url(:/image/in.jpg);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
            showToLetter(j);
        });
        i++;

    }

    ui->message->setCurrentIndex(3);
    ui->sendpage->setCurrentIndex(0);
}

QStringList First::getToList()
{
    Network n;
    QByteArray result=n.doGet("outbox/"+this->ID);
    QStringList noticeList;

    QJsonDocument document2=QJsonDocument::fromJson(result);
    QJsonArray array2 = document2.array();

   for(int i = 0; i<array2.count(); i++)
      {
            QJsonObject now=array2.at(i).toObject();
            qDebug()<<"当前通知id："+QString::number(now.value("id").toInt());
            this->toNo[i]=QString::number(now.value("id").toInt());
            QString s=QString::number(i+1)+".  To:"
                    +(now.value("to").toObject()).value("userName").toString()
                    +"   Date:"
                    +now.value("data").toString();
            noticeList<<s;
        }

    return noticeList;
}

void First::showToLetter(int tno)
{
    qDebug()<<"NONONONO************************************"+tno;
    Network n;
    QJsonObject result=QJsonDocument::fromJson(n.doGet("message/"+this->toNo[tno])).object();
    QString status;
    ui->sname->setText((result.value("to").toObject()).value("userName").toString());
    ui->sdate->setText(result.value("date").toString());
    ui->sshow->setPlainText(result.value("content").toString());
    ui->sendpage->setCurrentIndex(1);
}

//返回键
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

//********************************************************************************************************


//********************************************************************************************************
//专家咨询(接口核对）
//入口初始化
void First::on_expert_clicked()
{
    ui->in->setCurrentIndex(2);

    ui->exin->setPlainText("");
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");


        ui->expertpage->setCurrentIndex(0);
        setUpExpert();


}
//查看历史咨询
void First::on_exprebt_clicked()
{

    QStringList list=getExperList();
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
            showExpert(j);
        });
        i++;

    }
    ui->expertpage->setCurrentIndex(1);
}

QStringList First::getExperList()
{
    Network n;
    QByteArray result=n.doGet("consult/getallfromme"+this->ID);
    QStringList expertList;

    QJsonDocument document2=QJsonDocument::fromJson(result);
    QJsonArray array2 = document2.array();

   for(int i = 0; i<array2.count(); i++)
      {
            QJsonObject now=array2.at(i).toObject();
            qDebug()<<"当前通知id："+QString::number(now.value("id").toInt());
            this->fromNo[i]=QString::number(now.value("id").toInt());

            QString s=QString::number(i)
                    +(now.value("to").toObject()).value("userName").toString()
                    +now.value("data").toString()
                    +now.value("readed").toString();
            expertList<<s;
        }

    return expertList;
}

//查看咨询详情
void First::showExpert(int eno)
{
    Network n;
    QJsonObject result=QJsonDocument::fromJson(n.doGet("consult/getInfo/"+this->experno[eno])).object();

    ui->aname->setText((result.value("from").toObject()).value("userName").toString());
    ui->qname->setText((result.value("to").toObject()).value("userName").toString());
    ui->qdate->setText(result.value("date").toString());
    ui->ashow->setPlainText(result.value("reply").toString());
    ui->qshow->setPlainText(result.value("question").toString());
    ui->expertpage->setCurrentIndex(2);
}

//建立专家咨询
void First::setUpExpert()
{
    Network n;
    QByteArray result=n.doGet("consult/getexperts");
    QStringList expertList;

    QJsonDocument document2=QJsonDocument::fromJson(result);
    QJsonArray array2 = document2.array();

     for(int i = 0; i<array2.count(); i++)
     {
         expertList<<QString::number((array2.at(i).toObject()).value("id").toInt());
     }

    ui->expertcho->addItems(expertList);
}

//咨询确认
void First::on_exsub_clicked()
{
    bool flag=true;
    if(ui->exin->toPlainText()=="")
    {
        ui->exin->setStyleSheet("color:rgb(255,0,0);");
        ui->exin->setPlainText("未输入内容");
        ui->exin->setStyleSheet("color:rgb(0,0,0);");
        flag=false;
    }
    if(flag)
    {
        Network n;
        QStringList list;
        list<<this->ID<<ui->expertcho->currentText()<<ui->exin->toPlainText();
        QString result=QString(n.doPost("consult/consult",list));
        if(result=="1")
        {
            ok o("发送成功！",this);
            o.exec();
            ui->midin->setText("");
            ui->textin->setPlainText("");
            ui->message->setCurrentIndex(0);
        }
        else if(result=="-1") ui->merr->setText("对方id不存在");
        else ui->merr->setText("发送失败");

    }
}
//返回按钮
void First::on_exre1_clicked()
{
    ui->expertpage->setCurrentIndex(0);
}
void First::on_exre2_clicked()
{
    ui->expertpage->setCurrentIndex(1);
}

//********************************************************************************************************


//********************************************************************************************************
//核心功能
//入口初始化
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

//选择图片
void First::on_choosebt_clicked()
{
    QString filePath= QFileDialog::getOpenFileName(this,"选择文件","","(*.jpg *.jpeg *.png *.bmp)");
//    ui->imain->setDisabled(true);
//    ui->imain->setText(filePath);
//    Paint *p=new Paint(filePath);
//    p->show();
    ui->imain->setText("  "+filePath);
    qDebug()<<filePath;
    QImage im;
    im.load(filePath);
    int x=im.width();
    int y=im.height();
    qDebug()<<x<<y;
    while(x>ui->in->width())
    {
        x=x*9/10;
        y=y*9/10;
    }
    qDebug()<<x<<y;
    if (y>ui->in->height()/3)
    {
        while(y>ui->in->height()*3/4)
        {
            y=y*9/10;
            x=x*9/10;
        }
    }
    qDebug()<<x<<y;
    ui->imshow->resize(x,y);
    ui->imshow->move(ui->in->width()/2-ui->imshow->width()/2,ui->in->height()/2-ui->imshow->height()/2);
    ui->imshow->setStyleSheet("border-image: url("+filePath+");");
    ui->imshow->show();
//    ui->imshow->setPixmap(QPixmap(filePath));
//    ui->imshow->show();
    qDebug()<<ui->imshow->width()<<ui->imshow->height();
    ui->sub->setEnabled(true);
    this->hexinPath=filePath;
}
//提交判断
void First::on_sub_clicked()
{
    Network n;

    if (this->getPow()=="farmer")
    {
        n.doImportantPost1(this->hexinPath,this->ID);
        pests();
    }
    else
    {
        qDebug()<<"发送。。。。。";
        n.doImportantPost2(this->hexinPath,this->ID);
        statistics();
    }
}

void First::pests()
{
    Network n;
    QStringList flist=this->hexinPath.split("/");
    QStringList list;
    list<<this->ID<<flist[flist.count()-1];

    QJsonObject result=QJsonDocument::fromJson(n.doPost("analyse/farmer",list)).object();
    ui->con->setText("疑似病虫害："+result.value("msg").toString());
}

void First::statistics()
{
    Network n;
    QStringList flist=this->hexinPath.split("/");
    QStringList list;
    list<<this->ID<<flist[flist.count()-1];
    qDebug()<<"&&&&&开始。。。";
    n.doPost("analyse/officer",list);
    QString path;
    while(true)
    {
        qDebug()<<"处理中。。。。";
        QTime time;
        time.start();
        while(time.elapsed() < 20000);
        path=n.doImportantGet(this->ID);
        if(path!="-1") break;
    }
    QImage im;
    im.load(path);
    int x=im.width();
    int y=im.height();
    while(x>ui->in->width())
    {
        x=x*9/10;
        y=y*9/10;
    }
    if (y>ui->in->height()/3)
    {
        while(y>ui->in->height()*3/4)
        {
            y=y*9/10;
            x=x*9/10;
        }
    }
    ui->imshow->resize(x,y);
    ui->imshow->move(ui->in->width()/2-ui->imshow->width()/2,ui->in->height()/2-ui->imshow->height()/2);
    ui->imshow->setStyleSheet("border-image: url("+path+");");
    ui->imshow->show();



}
//农业小知识
void First::on_knowsearch_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.nongyezhishi.com"));
}

//********************************************************************************************************


//********************************************************************************************************
//论坛功能
//入口初始化
void First::on_forum_clicked()
{
    ui->in->setCurrentIndex(0);
    ui->forumpage->setCurrentIndex(0);
    ui->help->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->expert->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->notice->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->forum->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btin.jpg);");
    ui->letter->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    ui->func->setStyleSheet("color:rgb(255, 255, 255);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:normal;border-image: url(:/image/bt.jpg);");
    setUpForum();
}

void First::setUpForum()
{
    QStringList list=getFormList();
    QLabel *label1=new QLabel(ui->forumlist);

    label1->setStyleSheet("border-image: url(:/image/notice.jpg);");
    label1->resize(ui->forumlist->width(),ui->forumlist->height());

    label1->show();
    int i=0;
    for (int j=0;j<7;j++)
    {
        if(j>=list.count()) break;

        QPushButton *bt=new QPushButton(ui->forumlist);
        bt->resize(ui->forumlist->width()*9/10,ui->forumlist->height()/10);
        bt->move(ui->forumlist->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        bt->setStyleSheet("border-image: url(:/image/in.jpg);");
        bt->show();
        QLabel *l=new QLabel(ui->forumlist);
        l->setText(QString::number(i));
        QLabel *label=new QLabel(ui->forumlist);
        label->resize(bt->width(),bt->height());
        label->setText("  "+list[j]);
        label->move(ui->forumlist->width()/20,bt->height()*i+bt->height()/3*i+bt->height()*2/3);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setStyleSheet("font-size:"+QString::number(this->width()/35)+"px;border-image: url(:/image/in.jpg);");
        label->show();
        connect(bt,&QPushButton::clicked,[=](){
            showForum(j);
        });
        i++;

    }



}

QStringList First::getFormList()
{
    Network n;
    QByteArray result=n.doGet("forum/getallposter");
    QStringList formList;

    QJsonDocument document2=QJsonDocument::fromJson(result);
    QJsonArray array2 = document2.array();

   for(int i = 0; i<array2.count(); i++)
      {
            QJsonObject now=array2.at(i).toObject();
            qDebug()<<"当前通知id："+QString::number(now.value("id").toInt());
            this->forumno[i]=QString::number(now.value("id").toInt());

            QString s=(now.value("user").toObject()).value("userName").toString()
                    +now.value("title").toString()
                    +now.value("date").toString();
            formList<<s;
        }

    return formList;
}

void First::showForum(int fno)
{
    Network n;
    QJsonObject result=QJsonDocument::fromJson(n.doGet("forum/getposterInfo/"+this->forumno[fno])).object();

    ui->fname->setText((result.value("user").toObject()).value("userName").toString());
    ui->fdate->setText(result.value("date").toString());
    ui->fout->setPlainText(result.value("title").toString());
    ui->forumpage->setCurrentIndex(1);
}
void First::on_forumbt_clicked()
{
    bool flag=true;
    if(ui->forumin->toPlainText()=="")
    {
        ui->forumin->setStyleSheet("color:rgb(255,0,0)");
        ui->forumin->setPlainText("未输入内容");
        ui->forumin->setStyleSheet("color:rgb(0,0,0)");
        flag=false;
    }

    if(flag)
    {
        Network n;
        QStringList list;
        list<<this->ID<<ui->forumin->toPlainText();
        n.doPost("/forum/addposter",list);
    }
}

void First::on_fre_clicked()
{
    ui->forumpage->setCurrentIndex(0);
}

//********************************************************************************************************



//********************************************************************************************************
//客服咨询
//入口初始化
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





//********************************************************************************************************









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
    ui->h->move(ui->left->width()/2-ui->head->width()/2,ui->head->width()/4);
    ui->head->move(ui->left->width()/2-ui->head->width()/2,ui->head->width()/4);
    ui->head->setAttribute(Qt::WA_TransparentForMouseEvents);
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
    ui->err->setStyleSheet("color:rgb(255, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->iderr->setStyleSheet("color:rgb(255, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->areaerr->setStyleSheet("color:rgb(255, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->powerr->setStyleSheet("color:rgb(255, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    if (ui->alter->isEnabled())
    {
        ui->alter->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
        ui->headalter->hide();
        ui->submit->hide();
        ui->cancel->hide();
        ui->thr->hide();
    }
    else
    {
        ui->alter->hide();
        ui->headalter->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
        ui->submit->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
        ui->alter->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
        ui->cancel->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    }

    ui->page1->resize(ui->in->width()/2,ui->in->height()/8);
    ui->page2->resize(ui->in->width()/2,ui->in->height()/8);
    ui->page3->resize(ui->in->width()/2,ui->in->height()/8);
    ui->page4->resize(ui->in->width()/2,ui->in->height()/8);

    ui->page1->move(ui->in->width()-ui->page1->width(),ui->in->height()/20);
    ui->page2->move(ui->in->width()-ui->page2->width(),ui->in->height()/20);
    ui->page3->move(ui->in->width()-ui->page3->width(),ui->in->height()/20);
    ui->page4->move(ui->in->width()-ui->page4->width(),ui->in->height()/20);
    ui->pushButton->resize(ui->in->width()/3,ui->in->height()/8);
    ui->pushButton->move(0,ui->in->height()/20);

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

    ui->forumlist->resize(ui->in->width(),ui->in->height()*8/10);
    ui->forumlist->move(0,ui->in->height()/8+ui->in->height()/20);
    ui->seshow->resize(ui->in->width(),ui->in->height()*8/10);
    ui->seshow->move(0,ui->in->height()/8+ui->in->height()/20);
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

    ui->p2->setStyleSheet("background:transparent;border-image: url(:/image/h.png);");
    ui->forumbt->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    ui->forumbt->resize(ui->in->width()/10,ui->in->height()/10);
    ui->forumbt->move(0,0);
    ui->forumin->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/in.jpg);");
    ui->forumin->resize(ui->in->width()*9/10,ui->in->height()/10);
    ui->forumin->move(ui->in->width()/10,0);

    ui->noticeshow->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->noticecontent->setStyleSheet("border-image: url(:/image/in.jpg);");

    ui->noticereturn->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/70)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");

    ui->label_5->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/30)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->label_5->resize(ui->in->width()*9/10,ui->in->height()/10);
}

//重新绘制函数结束


//退出按钮
void First::on_exit_clicked()
{
    this->close();
}












void First::on_pushButton_clicked()
{
    ui->in->setCurrentIndex(12);
}

void First::on_nwsub_clicked()
{
    bool flag=true;
    if(ui->nwin->toPlainText()==""||ui->ntin->text()=="")
    {
        ui->nwin->setStyleSheet("color:rgb(255,0,0)");
        ui->nwin->setPlainText("未输入文本");
        ui->nwin->setStyleSheet("color:rgb(0,0,0)");
        flag=false;
    }
    if(flag)
    {
//        Network n;
//        n.doPost();
    }

}

void First::on_nwre_clicked()
{
    ui->nwin->setPlainText("");
    ui->in->setCurrentIndex(6);
}
