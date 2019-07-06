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
    ui->phonein->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));

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
    case 2:{
        ui->city->clear();
        QStringList list;
        list<<"太原市"<<"大同市"<<"朔州市"<<"忻州市"<<"阳泉市"<<"吕梁市"<<"晋中市"<<"长治市"<<"晋城市"<<"临汾市"<<"运城市";
        ui->city->addItems(list);
        break;

    }
    case 3:{
        ui->city->clear();
        QStringList list;
        list<<"西安市"<<"宝鸡市"<<"咸阳市"<<"铜川市"<<"渭南市"<<"延安市"<<"榆林市"<<"汉中市"<<"安康市"<<"商洛市";
        ui->city->addItems(list);
        break;

    }
    default:
        break;
    }
}

void res::on_submit_clicked()
{
    bool flag=true;
    if(ui->addrin->text()==""){
        flag=false;
        ui->addrerr->setText("邮箱不能为空！");
        ui->addrerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else if(!ui->addrin->text().contains("@")){
        flag=false;
        ui->addrerr->setText("邮箱格式错误！");
        ui->addrerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else ui->addrerr->setText("");

    if(ui->namein->text()==""){
        flag=false;
        ui->nameerr->setText("姓名不能为空！");
        ui->nameerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else ui->nameerr->setText("");

    if(ui->pasin->text()==""){
        flag=false;
        ui->paserr->setText("密码不能为空！");
        ui->paserr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else ui->paserr->setText("");

    if(ui->phonein->text()==""){
        flag=false;
        ui->phoneerr->setText("手机号不能为空！");
        ui->phoneerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else if(ui->phonein->text().count()!=11){
        flag=false;
        ui->phoneerr->setText("手机号格式错误！");
        ui->phoneerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else ui->phoneerr->setText("");
    if(ui->pasin->text()!=ui->pas2in->text()){
        flag=false;
        ui->pas2err->setText("两次输入密码不同！");
        ui->pas2err->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else ui->pas2err->setText("");

    if(ui->pro->currentText()=="..."||ui->city->currentText()=="..."){
        flag=false;
        ui->areaerr->setText("请选择地区！");
        ui->areaerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else ui->areaerr->setText("");

    if(ui->powin->currentText()=="..."){
        flag=false;
        ui->powerr->setText("请选择角色！");
        ui->powerr->setStyleSheet("color:rgb(255, 0, 0);font-size:20px;font-family:楷体;font: bold;");
    }
    else ui->powerr->setText("");

    if(flag){
        QString res=ui->namein->text()+ui->pasin->text()+ui->phonein->text()+ui->addrin->text()+ui->pro->currentText()+ui->city->currentText()+ui->powin->currentText();
        qDebug()<<res;
    }

}
