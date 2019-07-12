#ifndef RES_H
#define RES_H

#include <QWidget>
#include <QStringList>

namespace Ui {
class res;
}

class res : public QWidget
{
    Q_OBJECT

public:
    explicit res(QWidget *parent = 0);
    ~res();

private slots:

    void on_pro_currentIndexChanged();

    void on_submit_clicked();

    void receiveData(QString data);

private:
    Ui::res *ui;
    QStringList list;
};

#endif // RES_H
