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

    void getNotice(int nno);

    QStringList getNoticeList();

    void setUpNotice();

    void getLast();

    void setUpExpert();

    void showExpert(int no);

    void setUpInfo();

    QStringList getToList();

    QStringList getFromList();

    QStringList getExperList();

    QStringList getFormList();

    void showToLetter(int tno);

    void showFromLetter(int fno);

    void setUpExpertForExpert();

    void setUpForum();

    void showForum(int fno);

    void pests();

    void statistics();

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

    void on_headalter_clicked();

    void on_noticereturn_clicked();

    void on_exsub_clicked();

    void on_exre2_clicked();

    void on_knowsearch_clicked();

    void on_noticeset_clicked();

    void on_forumbt_clicked();

    void on_fre_clicked();

    void on_pushButton_clicked();

    void on_nwsub_clicked();

    void on_nwre_clicked();

private:
    Ui::First *ui;

    QString ID;

    QString pow;

    bool success=false;

    QString imagePath;

    QStringList list;

    QString noticeNo[20];

    QString fromNo[7];

    QString toNo[7];

    QString experno[7];

    QString forumno[7];

    QString hexinPath;

    QString resPath="";
};

#endif // FIRST_H
