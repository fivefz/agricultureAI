#include "socket.h"
#include <QDebug>

void Socket::startConnect()
{
qDebug()<<"0000";
    QString host="http://10.147.179.138";
    quint16 port=8080;
    m_socket=new QTcpSocket(this);
    connect(m_socket,SIGNAL(connected()),
            this,SLOT(onConnected()));
    connect(m_socket,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));
    m_socket->connectToHost(host,port);
qDebug()<<"9999";
}

void Socket::onConnected()
{
    m_socket->write("GET / HTTP/1.1\r\n\r\n");
    qDebug()<<"11111";
}

void Socket::onReadyRead()
{
    qDebug()<<"6666";
    qDebug()<<m_socket->readAll();
}
