#include "mainwindow.h"



TcpSocketsServer::TcpSocketsServer()
{
    if (this->listen(QHostAddress::LocalHost, 1801))
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
    newSocket_interface = new MTcpSocket(socketDescriptor);

    newSockets_interface.push_back(newSocket_interface);
    socketDescriptors.push_back(socketDescriptor);


    int threadIdx = m_availableThreads.size();

    if (threadIdx < m_idealThreadCount)
    {
        m_availableThreads.append(new QThread());
        m_threadsLoad.append(1);
        m_availableThreads.last()->start();
    }
    else
    {
        threadIdx = std::distance(m_threadsLoad.cbegin(),std::min_element(m_threadsLoad.cbegin(), m_threadsLoad.cend()));
        ++m_threadsLoad[threadIdx];
    }
    newSocket_interface->moveToThread(m_availableThreads.at(threadIdx));

    connect(newSocket_interface, &MTcpSocket::socketClientDisconnected_signal, this, [this, threadIdx]() {--m_threadsLoad[threadIdx];}, Qt::QueuedConnection);
    connect(newSocket_interface, &MTcpSocket::readyToSend_signal, this, &TcpSocketsServer::sendToSockets);
}



void TcpSocketsServer::sendToSockets(QString message)
{
    for (auto socket : newSockets_interface)
    {
        socket->writeInSoket(message);
    }
}

void TcpSocketsServer::deleteSockets()
{
    socket_interface = reinterpret_cast<MTcpSocket*>(sender());
    newSockets_interface.erase(std::remove(newSockets_interface.begin(),newSockets_interface.end(),socket_interface), newSockets_interface.end());
    //socket_interface->deleteLater();
}







