#include "forget.h"
#include "ui_forget.h"
#include "check.h"
#include "network.h"
#include "ok.h"
#include <QDebug>

forget::forget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forget)
{
    ui->setupUi(this);
//    QPalette pal(palette());
//    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/image/First.jpg")));
//    setPalette(pal);
    setWindowTitle("多人农业图像分析平台");
    setWindowIcon(QIcon(QPixmap(":/image/First.jpg")));
//    ui->background->setPixmap(QPixmap(":/image/First.jpg"));
    ui->label->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->label_2->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->label_3->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->pushButton->setStyleSheet("color:rgb(0, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    ui->idin->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->pasin->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->pasin2->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");



}

forget::~forget()
{
    delete ui;
}

void forget::on_pushButton_clicked()
{
    bool flag=true;
    ui->err->setStyleSheet("color:rgb(255,0,0)");
    if(ui->idin->text()=="")
    {
        ui->err->setText("请输入账号！");
        flag=false;
    }
    else if(ui->pasin->text()=="")
    {
        ui->err->setText("请输入新密码！");
        flag=false;
    }
    else if(ui->pasin->text()!=ui->pasin2->text())
    {
        ui->err->setText("两次密码输入不同！");
        flag=false;
    }

    if (flag)
    {
        this->newPasList<<ui->idin->text()<<ui->pasin->text();
        Network n1;
        QStringList list1;
        list1<<ui->idin->text()<<"";
        QString code=QString(n1.doPost("getcode",list1));
        if (code=="-1")
        {
            ui->err->setText("id不存在");
        }
        else
        {
            check *c=new check(code,"");
            c->setWindowModality(Qt::ApplicationModal);
            connect(c, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            c->show();
            ui->err->setText("");
        }



    }


}

void forget::receiveData(QString data)
{
    if(data=="OK")
    {
        Network n;
        QString result=QString(n.doPost("updatepassword",this->newPasList));
        ok o("修改密码成功");
        qDebug()<<result;
        o.exec();
        this->newPasList.clear();
        this->close();
    }
}
