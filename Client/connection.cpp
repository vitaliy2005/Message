#include "connection.h"

Connection::Connection() {this->newConnection();}

bool Connection::newConnection()
{
    dataBase = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    dataBase->setDatabaseName("myChats.db");

    if(!dataBase->open())
    {
        QMessageBox::critical(nullptr, "sdas", "dsas", QMessageBox::Cancel);
        return false;
    }
    query = new QSqlQuery();
    query->exec("CREATE TABLE IF NOT EXISTS chats (ID integer primary key AUTOINCREMENT, Nummer VARCHAR(12), Name VARCHAR(20))");

    return true;
}
