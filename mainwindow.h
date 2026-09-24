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

    void on_cbxGestionar_activated();

    void on_btnAgregarCliente_clicked();
    void on_btnBuscarCliente_clicked();
    void on_btnModificarCliente_clicked();
    void on_btnEliminarCliente_clicked();


    void on_btnAgregarProducto_clicked();
    void on_btnEliminarProducto_clicked();
    void on_btnBuscarProducto_clicked();
    void on_btnModificarProducto_clicked();

    void on_btnAgregarCompra_clicked();
    void on_btnEliminarCompra_clicked();
    void on_btnBuscarCompra_clicked();
    void on_btnModificarCompra_clicked();

private:

    Ui::MainWindow *ui;

    vector<Cliente> clientes;
    list<Producto> productos;
    queue<Compra> compras;
};

#endif // MAINWINDOW_H
