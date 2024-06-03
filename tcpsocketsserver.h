#ifndef TCPSOCKETSSERVER_H
#define TCPSOCKETSSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class TcpSocketsServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpSocketsServer();
};

#endif // TCPSOCKETSSERVER_H
