#include "qrunnablethread.h"

QRunnableThread::QRunnableThread(QVector<QTcpSocket*> sockets, QTcpSocket* socket)
{
    __sockets.clear();
    __sockets = sockets;
    __socket = socket;

}

void QRunnableThread::run()
{
    QDataStream in(__socket);
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
void QRunnableThread::sendToClient(QString message)
{
    bArray.clear();
    QDataStream out(&bArray, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << message;
    for (auto s : __sockets)
    {
        s->write(bArray);
    }
}
