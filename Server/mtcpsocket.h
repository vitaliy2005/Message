#ifndef MTCPSOCKET_H
#define MTCPSOCKET_H

#include <QTcpSocket>
#include <QThread>

class MTcpSocket : public QObject
{
    Q_OBJECT
public:
    MTcpSocket(qintptr socketDescriptor);
    void writeInSoket(QString message);

private:
    QTcpSocket* socket;
    QByteArray bArray;
    quint16 nextBlockSize = 0;

    void sendToClient(QString);

private slots:
    void readyRead_slot();
    void socketClientDisconnected_slot();

signals:
    void readyToSend_signal(QString message);
    void socketClientDisconnected_signal();
};

#endif // MTCPSOCKET_H
