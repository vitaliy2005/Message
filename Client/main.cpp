#include "mainwindow.h"
#include "connection.h"
#include "chats.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chats w;
    Connection h;
    w.show();
    return a.exec();
}
