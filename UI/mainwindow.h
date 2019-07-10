#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "res.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setID(QString s)
    {
        this->ID=s;
    }

    void setPow(QString s)
    {
        this->pow=s;
    }

    QString getID()
    {
        return this->ID;
    }

    QString getPow()
    {
        return this->pow;
    }

private slots:
    void on_ok_clicked();

    void paintEvent(QPaintEvent *e);

    void on_forget_clicked();

private:
    Ui::MainWindow *ui;

    QString ID;

    QString pow;
};

#endif // MAINWINDOW_H
