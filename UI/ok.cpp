#include "ok.h"
#include "ui_ok.h"

ok::ok(QString s,QWidget *parent) :
    str(s),
    QDialog(parent),
    ui(new Ui::ok)
{
    ui->setupUi(this);
    setWindowTitle("多人农业图像分析平台");
    setWindowIcon(QIcon(QPixmap(":/image/First.jpg")));

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
