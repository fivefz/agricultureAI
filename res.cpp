#include "res.h"
#include "ui_res.h"
#include <QDebug>
res::res(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::res)
{
    ui->setupUi(this);
    ui->background->setPixmap(QPixmap(":/image/First.jpg"));
    ui->name->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->pas->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->addr->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->area->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->pas2->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->phone->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->pow->setStyleSheet("color:rgb(255, 255, 255);font-size:20px;font-family:楷体;font: bold;");
    ui->submit->setStyleSheet("color:rgb(0, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    ui->namein->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->pasin->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->addrin->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->pas2in->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");
    ui->phonein->setStyleSheet("color:rgb(255, 255, 255);font-size:17px;background:transparent;");


}

res::~res()
{
    delete ui;
}


void res::on_pro_currentIndexChanged()
{
    switch (ui->pro->currentIndex()) {
    case 1:{
        ui->city->clear();
        QStringList list;
        list<<"长沙市"<<"株洲市"<<"湘潭市"<<"衡阳市"<<"邵阳市"<<"岳阳市"<<"常德市"<<"张家界市"<<"益阳市"<<"郴州市"
           <<"永州市"<<"怀化市"<<"娄底市"<<"湘西土家族苗族自治州";
        ui->city->addItems(list);


        break;
    }
    case 2:

        break;
    case 3:

        break;
    default:
        break;
    }
}

void res::on_submit_clicked()
{
    if(ui->addrin->text()==""){
        ui->addrerr->setText("地址不能为空！");
        ui->addrerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    if(ui->namein->text()==""){
        ui->nameerr->setText("姓名不能为空！");
        ui->nameerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    if(ui->namein->text()==""){
        ui->nameerr->setText("姓名不能为空！");
        ui->nameerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    if(ui->namein->text()==""){
        ui->nameerr->setText("姓名不能为空！");
        ui->nameerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }


}
