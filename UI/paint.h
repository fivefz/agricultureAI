#ifndef PAINT_H
#define PAINT_H

#include <QWidget>

namespace Ui {
class Paint;
}

class Paint : public QWidget
{
    Q_OBJECT

public:
    explicit Paint(QString filePath,QWidget *parent = 0);
    ~Paint();
signals:
    void sendData(QString);

private slots:
    void on_submit_clicked();

private:
    Ui::Paint *ui;
    QString path;
};

#endif // PAINT_H
