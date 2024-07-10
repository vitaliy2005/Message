#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QWidget>

namespace Ui {
class Authentication;
}

class Authentication : public QWidget
{
    Q_OBJECT

public:
    explicit Authentication(QWidget *parent = nullptr);
    ~Authentication();

private:
    Ui::Authentication *ui;
};

#endif // AUTHENTICATION_H
