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
    QDataStream out(socket);
    out.setVersion(QDataStream::Qt_6_2);
    if(out.status() == QDataStream::Ok)
    {
        for (;;)
        {
            if (nextBlockSize == 0)
            {
                if (socket->bytesAvailable() < 2)
                {
                    break;
                }
                out >> nextBlockSize;
            }

            if (socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            QString message;
            out >> message;
            nextBlockSize = 0;
            qDebug() << "read";
            qDebug() << message;
            emit readyToSend_signal(message);
            break;
        }
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
    QDataStream in(&bArray, QIODevice::WriteOnly);
    in.setVersion(QDataStream::Qt_6_2);

    in << qint16(0) << message;
    in.device()->seek(0);
    in << qint16(bArray.size() - sizeof(qint16));

    socket->write(bArray);
}

