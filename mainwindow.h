#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <list>
#include <queue>
#include <QString>
#include <QMainWindow>

#include "cliente.h"
#include "producto.h"
#include "compra.h"

using namespace std;

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

    vector<Cliente> clientes;
    list<Producto> productos;
    queue<Compra> compras;
};

#endif // MAINWINDOW_H
