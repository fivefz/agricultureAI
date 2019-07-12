#include "ok.h"
#include "ui_ok.h"

ok::ok(QString s,QWidget *parent) :
    str(s),
    QDialog(parent),
    ui(new Ui::ok)
{
    ui->setupUi(this);

    ui->label->setText(this->str);
}

ok::~ok()
{
    delete ui;
}

void ok::on_pushButton_clicked()
{
    this->close();
}
