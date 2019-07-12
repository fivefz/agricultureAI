#ifndef FORGET_H
#define FORGET_H

#include <QWidget>

namespace Ui {
class forget;
}

class forget : public QWidget
{
    Q_OBJECT

public:
    explicit forget(QWidget *parent = 0);
    ~forget();

private slots:
    void on_pushButton_clicked();

    void receiveData(QString data);

private:
    Ui::forget *ui;

    QStringList newPasList;
};

#endif // FORGET_H
