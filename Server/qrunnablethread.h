#ifndef QRUNNABLETHREAD_H
#define QRUNNABLETHREAD_H

#include <QObject>
#include <QRunnable>
#include <QTcpSocket>

class QRunnableThread : public QRunnable, QObject
{
public:
    QRunnableThread(QVector<QTcpSocket*> sockets, QTcpSocket* socket);
    void sendToClient(QString message);
    void run();
private:
    QByteArray bArray;
    QVector<QTcpSocket*> __sockets;
    QTcpSocket* __socket;
};

#endif // QRUNNABLETHREAD_H
