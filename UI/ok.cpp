#include "ok.h"
#include "ui_ok.h"

ok::ok(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ok)
{
    ui->setupUi(this);
}

ok::~ok()
{
    delete ui;
}

void ok::on_pushButton_clicked()
{
    this->close();
}
