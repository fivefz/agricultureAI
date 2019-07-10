#include "paint.h"
#include "ui_paint.h"

Paint::Paint(QString filePath,QWidget *parent) :
    path(filePath),
    QWidget(parent),
    ui(new Ui::Paint)
{
    ui->setupUi(this);
    QImage ima;
    ima.load(filePath);
    this->setFixedSize(ima.width()*11/10,ima.height());

    ui->image->resize(ima.size());
    ui->image->move(0,0);
    ui->bts->resize(this->width()/11,this->height());
    ui->bts->move(ui->image->width(),this->height()/2);

    ui->image->setPixmap(QPixmap(filePath));

//    QPalette palette(this->palette());
//        palette.setColor(QPalette::Background, Qt::white);
//        this->setPalette(palette);
//        //初始化变量
//        this->mousedown=false;
//        this->release=false;
//        this->h=900;
//        this->w=1440;
//        //初始化画布
//        pix=new QPixmap(w,h);
//        pix->fill(Qt::white);

}

Paint::~Paint()
{
    delete ui;
}

void Paint::on_submit_clicked()
{

}
