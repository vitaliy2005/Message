#include "chats.h"
#include "ui_chats.h"

Chats::Chats(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Chats)
{
    ui->setupUi(this);

    QListWidgetItem* item1 = new QListWidgetItem(QIcon(":/my.jpg"), "dfs");
    this->ui->listWidget->addItem(item1);
}

Chats::~Chats()
{
    delete ui;
}

