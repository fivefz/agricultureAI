#ifndef OK_H
#define OK_H

#include <QDialog>

namespace Ui {
class ok;
}

class ok : public QDialog
{
    Q_OBJECT

public:
    explicit ok(QString s,QWidget *parent = 0);
    ~ok();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ok *ui;
    QString str;
};

#endif // OK_H
