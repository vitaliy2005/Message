#include "mtcpsocket.h"

MTcpSocket::MTcpSocket(qintptr socketDescriptor)
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &MTcpSocket::readyRead_slot);
    connect(socket, &QTcpSocket::disconnected, this, &MTcpSocket::socketClientDisconnected_slot);
}

void MTcpSocket::readyRead_slot()
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
        emit readyToSend_signal(message);
    }
    else
    {
        qDebug() << "error read";
    }
}

void MTcpSocket::socketClientDisconnected_slot()
{
    // повторное использование объекта доделать
    socket = reinterpret_cast<QTcpSocket*>(sender());
    socket->deleteLater();
    emit socketClientDisconnected_signal();
    this->deleteLater();
}

void MTcpSocket::writeInSoket(QString message)
{
    bArray.clear();
    QDataStream out(&bArray, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << message;
    socket->write(bArray);
}

