#ifndef FIRST_H
#define FIRST_H

#include <QWidget>

namespace Ui {
class First;
}

class First : public QWidget
{
    Q_OBJECT

public:
    explicit First(QString i,QString p,QWidget *parent = 0);
    ~First();


    void changeTime();

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

    void change();


private slots:
    void on_notice_clicked();

    void on_forum_clicked();

    void on_letter_clicked();

    void on_expert_clicked();

    void on_help_clicked();

    void paintEvent(QPaintEvent *e);

    void on_h_clicked();


    void on_func_clicked();

    void on_alter_clicked();

    void on_cancel_clicked();

    void on_submit_clicked();

    void receiveData(QString data);

private:
    Ui::First *ui;

    QString ID;

    QString pow;

    bool success=false;
};

#endif // FIRST_H
