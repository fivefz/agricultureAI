#include "check.h"
#include "ui_check.h"
#include "ok.h"

check::check(QString s,QString a,QWidget *parent) :
    code(s),
    addr(a),
    QWidget(parent),
    ui(new Ui::check)
{
    ui->setupUi(this);
    ui->title->setText("请填写您的邮箱"+a+"收到的验证码");
}

check::~check()
{
    delete ui;
}

void check::on_submit_clicked()
{
    if(ui->in->text()==this->code)
    {
        ok o("验证成功！");
        o.exec();
        emit sendData("alter");
        this->close();
    }
    else
    {
        ui->err->setText("验证码错误！");
        ui->err->setStyleSheet("color:rgb(255,0,0);");
    }
}

void check::on_cancel_clicked()
{
    this->close();
}
