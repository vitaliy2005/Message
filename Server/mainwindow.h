
#ifndef TCPSOCKETSSERVER_H
#define TCPSOCKETSSERVER_H
#include<QThreadPool>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtCore/qdebug.h>
#include "qrunnablethread.h"

class TcpSocketsServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpSocketsServer();
    QTcpSocket* socket;
    QThreadPool* threadPool;
    QRunnableThread* qrunnable;
private:
    QVector<QTcpSocket*> sockets;
    QVector<qintptr> socketDescriptors;
    // QByteArray bArray;
    void sendToClient(QString message);
public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void deleteSockets();
};

#endif // TCPSOCKETSSERVER_H
