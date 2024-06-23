#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 1801);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::slotReadyRead()
{
    socket = reinterpret_cast<QTcpSocket*>(sender());
    QDataStream out(socket);
    out.setVersion(QDataStream::Qt_6_4);
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
            ui->textBrowser->append(message);
            break;
        }
    }
    else
    {
        ui->textBrowser->append("error read");
    }
}

void MainWindow::sendToServer(QString message)
{
    bArray.clear();
    QDataStream in(&bArray, QIODevice::WriteOnly);
    in.setVersion(QDataStream::Qt_6_2);

    in << qint16(0) << message;
    in.device()->seek(0);
    in << qint16(bArray.size() - sizeof(qint16));

    socket->write(bArray);
    socket->flush();
}

void MainWindow::on_pushButton_clicked()
{

    sendToServer(ui->lineEdit->text());
}


void MainWindow::on_lineEdit_returnPressed()
{
    sendToServer(ui->lineEdit->text());
}


