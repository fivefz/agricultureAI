#ifndef SOCKET_H
#define SOCKET_H
#include <QTcpSocket>

class Socket:public QObject
{
    Q_OBJECT
public:
    Socket():m_socket(0){}
    ~Socket(){}

    void startConnect();

protected slots:
    void onConnected();
    void onReadyRead();

private:
    QTcpSocket *m_socket;
};

#endif // SOCKET_H
