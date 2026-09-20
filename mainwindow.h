#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <list>
#include <queue>
#include <QList>
#include <QString>
#include <QMainWindow>

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

private slots:


    void on_buttonMostrarListado_clicked();

private:
    Ui::MainWindow *ui;
    std::queue<QString> compras;
    std::list<QString> productos;
    std::vector<QString> clientes;
};
#endif // MAINWINDOW_H
