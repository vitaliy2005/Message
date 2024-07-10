#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

class Connection
{
public:
    Connection();
    bool newConnection();
private:
    QSqlDatabase* dataBase;
    QSqlQuery* query;


};

#endif // CONNECTION_H
