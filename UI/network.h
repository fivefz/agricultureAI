#ifndef NETWORK_H
#define NETWORK_H

#include <QString>

class Network
{

public:
    explicit Network();
    ~Network();

    QString doGet(QString fuction);

    QByteArray doPost(QString fuction,QStringList list);

private:
    QString url="http://192.168.43.252:80/";


};

#endif // NETWORK_H
