#include "notice.h"
#include "ui_notice.h"

notice::notice(QString noin,QString titlein,QString namein,QString datein,QWidget *parent) :
    no(noin),title(titlein),name(namein),date(datein),
    QWidget(parent),
    ui(new Ui::notice)
{
    ui->setupUi(this);
    ui->no->setText(this->no);
    ui->title->setText(this->title);
    ui->name->setText(this->name);
    ui->date->setText(this->date);


}

notice::~notice()
{
    delete ui;
}

void notice::on_Button_clicked()
{
    emit sendData(ui->no->text());
}

void notice::paintEvent ( QPaintEvent *e )
{
//    ui->no->resize(this->width()/10,this->height()*3/4);
//    ui->title->resize(this->width()/10,this->height()*3/4);
//    ui->name->resize(this->width()/10,this->height()*3/4);
//    ui->date->resize(this->width()/10,this->height()*3/4);
//    ui->Button->resize(this->width()/10,this->height()*3/4);

    this->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/20)+"px;background:transparent;font-weight:bold;border-image: url(:/image/btbt.png);");
    ui->no->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/40)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->title->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/40)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->name->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/40)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->date->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/40)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");
    ui->Button->setStyleSheet("color:rgb(0, 0, 0);font-size:"+QString::number(this->width()/40)+"px;background:transparent;font-weight:bold;border-image: url(:/image/h.png);");

}
