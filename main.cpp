#include "mainwindow.h"
#include <QApplication> //应用程序类

//argc命令行变量数量  argv  命令行变量数组
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//a 应用程序对象，有且仅有一个
    MainWindow w; //创建自定义窗口对象
    w.show();//默认不弹出

    return a.exec();//进入消息循环机制
}
