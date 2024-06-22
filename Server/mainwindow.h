
#ifndef TCPSOCKETSSERVER_H
#define TCPSOCKETSSERVER_H
#include <QTcpSocket>
#include "mtcpsocket.h"
#include<QThread>
#include<QTcpServer>
#include <QtCore/qdebug.h>


class TcpSocketsServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpSocketsServer();

private:
    const int m_idealThreadCount = qMax(QThread::idealThreadCount()-1,1);

    MTcpSocket* newSocket_interface;
    MTcpSocket* socket_interface;
    QByteArray bArray;

    QVector<QThread*> m_availableThreads;
    QVector<int> m_threadsLoad;
    QVector<MTcpSocket*> newSockets_interface;
    QVector<qintptr> socketDescriptors;

    void incomingConnection(qintptr socketDescriptor);

public slots:
    void sendToSockets(QString);
    void deleteSockets();
};

#endif // TCPSOCKETSSERVER_H4
