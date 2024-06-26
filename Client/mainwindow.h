#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket* socket;
    QByteArray bArray;
public slots:
    void slotReadyRead();
    void sendToServer(QString message);
private slots:
    void on_pushButton_clicked();
    void on_lineEdit_returnPressed();
};
#endif // MAINWINDOW_H
