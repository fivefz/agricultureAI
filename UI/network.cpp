#include "network.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include <QBuffer>
#include <QImageReader>
#include <QPixmap>
#include <QFile>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QIODevice>
#include <QStringList>
#include <QString>


Network::Network()
{

}

Network::~Network()
{

}

QByteArray Network::doGet(QString function)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest req;


    req.setUrl(QUrl(this->url+function));
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

    qDebug()<<"network输出："+responseByte;
    QJsonObject json = QJsonDocument::fromJson(responseByte).object();

    //int s=json_array2[0].value("id").toInt();

    //qDebug()<<s;


// qDebug()<<responseByte;
//    qDebug()<<"*****************************************" << responseByte;

//    QBuffer buffer(&responseByte);
//    buffer.open(QIODevice::ReadOnly);
//    QImageReader reader(&buffer,"JPG");
//    QImage img = reader.read();
//    if(!img.isNull()){
//        QPixmap pix = QPixmap::fromImage(img);

//        pix.save("E://save.jpg");
   // QString res=QString(responseByte);


    return responseByte;


 }

QByteArray Network::doPost(QString function,QStringList list)
{

    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QJsonObject obj;
    QNetworkRequest req;

    if (function=="login")
    {
        obj.insert("id",list[0]);
        obj.insert("password",list[1]);
    }
    else if(function=="register")
    {
        obj.insert("userName",list[0]);
        obj.insert("password",list[1]);
        obj.insert("email",list[2]);
        obj.insert("phone",list[3]);
        obj.insert("province",list[4]);
        obj.insert("city",list[5]);
        obj.insert("role",list[6]);
    }
    else if(function=="getcode")
    {
        obj.insert("id",list[0]);
        obj.insert("email",list[1]);
    }
    else if(function=="updatepassword")
    {
        obj.insert("id",list[0]);
        obj.insert("password",list[1]);
    }
    else if(function=="editpersonalInfo")
    {
        obj.insert("id",list[0]);
        obj.insert("userName",list[1]);
        obj.insert("password",list[2]);
        obj.insert("email",list[3]);
        obj.insert("phone",list[4]);
    }
    else if(function=="sendmessage")
    {
        QJsonObject o,p;
        o.insert("id",list[0]);
        p.insert("id",list[1]);
        obj.insert("from",o);
        obj.insert("to",p);
        obj.insert("content",list[2]);
    }
    else if(function=="consult/consult")
    {
        QJsonObject o,p;
        o.insert("id",list[0]);
        p.insert("id",list[1]);
        obj.insert("from",o);
        obj.insert("to",p);
        obj.insert("question",list[2]);
    }
    else if(function=="analyse/farmer")
    {
        function="analyse/farmer/"+list[0]+"/"+list[1];
        qDebug()<<"***********&&&&&&&&&&first的name"+list[1];
    }
    else if(function=="forum/addposter")
    {
        QJsonObject o;
        o.insert("id",list[0]);
        obj.insert("user",o);
        obj.insert("title",list[1]);
        obj.insert("content",list[1]);
    }
    else if(function=="analyse/officer")
    {
        function="analyse/officer/"+list[0]+"/"+list[1];
    }




        req.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
        req.setUrl(QUrl(this->url+function));
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

QString Network::doImageGet(QString id)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest req;
    req.setUrl(QUrl(this->url+"avatar/downloadAvatar/"+id));
    QNetworkReply *reply=manager->get(req);
    //添加事件循环机制，返回后再运行后面的
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
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

    QString path="E:/QTProject/Agricultural/head/"+id+".jpg";
    QBuffer buffer(&responseByte);
    buffer.open(QIODevice::ReadOnly);
    QImageReader reader(&buffer,"JPG");
    QImage img = reader.read();
    if(!img.isNull()){
        QPixmap pix = QPixmap::fromImage(img);
        pix.save(path);
    }
    return path;

}

void Network::doImagePost(QString filePath,QString id)
{
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest req;
        QHttpPart imagePart;
        imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
        imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"file\"; filename=\"image.jpg\""));
         QFile *image=new QFile(filePath);
        image->open(QIODevice::ReadOnly);
        imagePart.setBodyDevice(image);
        image->setParent(multiPart);
        multiPart->append(imagePart);
    req.setUrl(QUrl(this->url+"/avatar/uploadAvatar/"+id));


    QNetworkReply *reply=manager->post(req,multiPart);

    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
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

    qDebug() << responseByte;

    return ;
}


void Network::doImportantPost2(QString filepath,QString id)
{
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest req;
        QHttpPart imagePart;
        QFile *image=new QFile(filepath);
        QStringList l=filepath.split("/");
        imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
        QString s="form-data; name=\"file\"; filename=\""+l[l.count()-1]+"\"";
        imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(s));
        qDebug()<<"*********&&&&&&&&&&文件名字"+l[l.count()-1];
        image->open(QIODevice::ReadOnly);
        imagePart.setBodyDevice(image);
        image->setParent(multiPart);
        multiPart->append(imagePart);
    req.setUrl(QUrl(this->url+"file/upload/"+id));
    QNetworkReply *reply=manager->post(req,multiPart);

    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
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

    qDebug() << responseByte;

    return ;
}

void Network::doImportantPost1(QString filepath,QString id)
{
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest req;
        QHttpPart imagePart;
        QFile *image=new QFile(filepath);
        QStringList l=filepath.split("/");
        imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
        QString s="form-data; name=\"file\"; filename=\""+l[l.count()-1]+"\"";
        imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(s));
        qDebug()<<"*********&&&&&&&&&&文件名字"+l[l.count()-1];
        image->open(QIODevice::ReadOnly);
        imagePart.setBodyDevice(image);
        image->setParent(multiPart);
        multiPart->append(imagePart);
    req.setUrl(QUrl(this->url+"file/upload/"+id));
    QNetworkReply *reply=manager->post(req,multiPart);

    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
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

    qDebug() << responseByte;

    return ;
}


QString Network::doImportantGet(QString id)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest req;
    req.setUrl(QUrl(this->url+"analyse/result/"+id));
    QNetworkReply *reply=manager->get(req);
    //添加事件循环机制，返回后再运行后面的
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
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

    QString res=QString(responseByte);
    if(res=="-1")
    {
        return res;
    }

    QString path="E:/QTProject/Agricultural/result/"+id+".png";
    QBuffer buffer(&responseByte);
    buffer.open(QIODevice::ReadOnly);
    QImageReader reader(&buffer,"PNG");
    QImage img = reader.read();
    if(!img.isNull()){
        QPixmap pix = QPixmap::fromImage(img);
        pix.save(path);
    }
    qDebug()<<"**********************路径";
    return path;
}

