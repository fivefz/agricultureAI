#include "network.h"
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


#include <QBuffer>
#include <QImageReader>
#include <QPixmap>


Network::Network()
{
//    QNetworkAccessManager *m_pHttpMgr = new QNetworkAccessManager();
//    //设置url
//    QString url = "http://192.168.43.252:8080/avatar/downloadAvatar?id=2";//fae4b325e52c
//    QNetworkRequest requestInfo;
//    requestInfo.setUrl(QUrl(url));

//    //添加事件循环机制，返回后再运行后面的
//    QEventLoop eventLoop;
//    QNetworkReply *reply =  m_pHttpMgr->get(requestInfo);
//    connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
//    eventLoop.exec();       //block until finish
//    //错误处理
//    if (reply->error() == QNetworkReply::NoError)
//    {
//        qDebug() << "request protobufHttp NoError";
//    }
//    else
//    {
//        qDebug()<<"request protobufHttp handle errors here";
//        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
//        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
//        qDebug( "request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
//        qDebug(qPrintable(reply->errorString()));
//    }
//    //请求返回的结果
//    QByteArray responseByte = reply->readAll();
//    qDebug() << responseByte;
}

Network::~Network()
{

}

QString Network::doGet(QString fuction)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest req;


    req.setUrl(QUrl(this->url+fuction));
    QNetworkReply *reply=manager->get(req);

    //添加事件循环机制，返回后再运行后面的
    QEventLoop eventLoop;

    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish
    //错误处理

    if (reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "request protobufHttp NoError";
    }
    else
    {
        qDebug()<<"request protobufHttp handle errors here";
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
        qDebug( "request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
        qDebug(qPrintable(reply->errorString()));
    }
    //请求返回的结果
    QByteArray responseByte = reply->readAll();


    QJsonObject json_array2 = QJsonDocument::fromJson(responseByte).object();

    int s=json_array2.value("id").toInt();

    qDebug()<<s;


 qDebug()<<responseByte;
//    qDebug()<<"*****************************************" << responseByte;

//    QBuffer buffer(&responseByte);
//    buffer.open(QIODevice::ReadOnly);
//    QImageReader reader(&buffer,"JPG");
//    QImage img = reader.read();
//    if(!img.isNull()){
//        QPixmap pix = QPixmap::fromImage(img);

//        pix.save("E://save.jpg");
    QString res=QString(responseByte);


    return res;


 }






QByteArray Network::doPost(QString fuction,QStringList list)
{

    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QJsonObject obj;
    QNetworkRequest req;

    if (fuction=="login")
    {
        obj.insert("id",list[0]);
        obj.insert("password",list[1]);
    }
    else if(fuction=="register")
    {
        obj.insert("userName",list[0]);
        obj.insert("password",list[1]);
        obj.insert("email",list[2]);
        obj.insert("phone",list[3]);
        obj.insert("province",list[4]);
        obj.insert("city",list[5]);
        obj.insert("role",list[6]);
    }
    else if(fuction=="getcode")
    {
        if (list.count()==1)
        {
            obj.insert("id",list[0]);
        }
        else
        {
            obj.insert("id",list[0]);
            obj.insert("email",list[0]);
        }
    }
    else if(fuction=="updatepassword")
    {
        obj.insert("id",list[0]);
        obj.insert("password",list[1]);
    }
    else if(fuction=="update")
    {
        obj.insert("userName",list[0]);
        obj.insert("password",list[1]);
        obj.insert("email",list[2]);
        obj.insert("phone",list[3]);
    }












        req.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
        req.setUrl(QUrl(this->url+fuction));
        QNetworkReply *reply=manager->post(req, QJsonDocument(obj).toJson());

        //添加事件循环机制，返回后再运行后面的
        QEventLoop eventLoop;

        QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
        eventLoop.exec();       //block until finish
        //错误处理

        if (reply->error() == QNetworkReply::NoError)
        {
            qDebug() << "request protobufHttp NoError";
        }
        else
        {
            qDebug()<<"request protobufHttp handle errors here";
            QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
            //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
            qDebug( "request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
            qDebug(qPrintable(reply->errorString()));
        }
        //请求返回的结果
        QByteArray responseByte = reply->readAll();
        qDebug()<<"*****************************************" << responseByte;


        //QString res=QString(responseByte);
        return responseByte;

}

