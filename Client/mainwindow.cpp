#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost("217.71.129.139", 4800);
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
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if(in.status() == QDataStream::Ok)
    {
        QString message;
        in >> message;
        ui->textBrowser->append(message);
    }
    else
    {
        ui->textBrowser->append("error read");
    }
}

void MainWindow::sendToServer(QString message)
{
    bArray.clear();
    QDataStream out(&bArray, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << message;
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


