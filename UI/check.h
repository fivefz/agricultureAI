#ifndef CHECK_H
#define CHECK_H

#include <QWidget>

namespace Ui {
class check;
}

class check : public QWidget
{
    Q_OBJECT

public:
    explicit check(QString s,QString a,QWidget *parent = 0);
    ~check();

signals:
    void sendData(QString);

private slots:
    void on_submit_clicked();

    void on_cancel_clicked();

private:
    Ui::check *ui;
    QString code;
    QString addr;
};

#endif // CHECK_H
