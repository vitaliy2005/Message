#include "mainwindow.h"
#include <QtCore/qdebug.h>

TcpSocketsServer::TcpSocketsServer()
{
    if (this->listen(QHostAddress::Any, 8080))
    {
        qDebug() << "ready";
    }
    else
    {
        qDebug() << "error";
    }
}


void TcpSocketsServer::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);


    connect(socket, &QTcpSocket::readyRead, this, &TcpSocketsServer::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &TcpSocketsServer::deleteSockets);

    sockets.push_back(socket);
    socketDescriptors.push_back(socketDescriptor);

    qDebug() << "Client connection " << socketDescriptor;
}

void TcpSocketsServer::slotReadyRead()
{
    socket = reinterpret_cast<QTcpSocket*>(sender());
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok)
    {
        qDebug() << "read";
        QString message;
        in >> message;
        qDebug() << message;
        sendToClient(message);
    }
    else
    {
        qDebug() << "error read";
    }
}

void TcpSocketsServer::sendToClient(QString message)
{
    bArray.clear();
    QDataStream out(&bArray, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << message;
    for (auto s : sockets)
    {
        s->write(bArray);
    }
}

void TcpSocketsServer::deleteSockets()
{
     socket = reinterpret_cast<QTcpSocket*>(sender());
     sockets.erase(std::remove(sockets.begin(),sockets.end(),socket), sockets.end());
     socket->deleteLater();
}



