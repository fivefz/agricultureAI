#ifndef RES_H
#define RES_H

#include <QWidget>

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

private:
    Ui::res *ui;
};

#endif // RES_H
