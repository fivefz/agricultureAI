#ifndef NETWORK_H
#define NETWORK_H

#include <QString>
#include <QJsonObject>
class Network
{

public:
    explicit Network();
    ~Network();

    QByteArray doGet(QString function);

    QByteArray doPost(QString function,QStringList list);

    QString doImageGet(QString id);

    void doImagePost(QString filePath,QString id);

    void doImportantPost1(QString filepath,QString id);
    void doImportantPost2(QString filepath,QString id);
    QString doImportantGet(QString id);
private:
    QString url="http://192.168.43.252:80/";


};

#endif // NETWORK_H
