
#ifndef TCPSOCKETSSERVER_H
#define TCPSOCKETSSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QtCore/qdebug.h>

class TcpSocketsServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpSocketsServer();
    QTcpSocket* socket;
private:
    QVector<QTcpSocket*> sockets;
    QVector<qintptr> socketDescriptors;
    QByteArray bArray;
    void sendToClient(QString message);
public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void deleteSockets();
};

#endif // TCPSOCKETSSERVER_H
