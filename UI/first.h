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

    void getNotice();

    QStringList getNoticeList();

    void setUpNotice();

    void getLast();

    void setUpLetter();

    void setUpExpert();
    void showExpert(QString no);

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

    void on_next1_clicked();

    void on_last1_clicked();

    void on_first2_clicked();

    void on_pre2_clicked();

    void on_next2_clicked();

    void on_last2_clicked();

    void on_first3_clicked();

    void on_pre3_clicked();

    void on_next3_clicked();

    void on_last3_clicked();

    void on_first4_clicked();

    void on_pre4_clicked();

    void on_exit_clicked();

    void on_choosebt_clicked();

    void on_sub_clicked();

    void on_w_clicked();

    void on_r_clicked();

    void on_s_clicked();

    void on_re1_clicked();

    void on_re3_clicked();

    void on_re2_clicked();

    void on_sendbt_clicked();

    void on_exprebt_clicked();

    void on_exre1_clicked();

    void on_rere_clicked();

    void on_sre1_clicked();

private:
    Ui::First *ui;

    QString ID;

    QString pow;

    bool success=false;

    QString ntno;

    QStringList noticeList;
};

#endif // FIRST_H
