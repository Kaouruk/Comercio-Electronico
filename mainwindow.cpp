#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Al iniciar solamente se muestra Clientes
    ui->grpClientes->setVisible(true);
    ui->grpProductos->setVisible(false);
    ui->grpCompras->setVisible(false);
}


//Estructuras
//Queue para la lista de compras
//List para la lista de productos
//Vector para la lista de clientes


//*****Cambios Kathia********
//Hice que las estructuras trabajaran con las clases
//Cliente, Producto y Compra en lugar de QString.
//Cada clase usa mostrarInformacion() para mostrar sus datos en la GUI.
//Los datos ahora se agregan desde los formularios.


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonMostrarListado_clicked()
{
    QString listado = ui->inputTipoListado->currentText();
    QString datos;

    if(listado == "Clientes")
    {
        QTextStream(&datos) << listado << "\n\n";

        for(Cliente &cliente : clientes)
        {
            QTextStream(&datos)
            << cliente.mostrarInformacion()
            << "\n";
        }
    }

    else if(listado == "Productos")
    {
        QTextStream(&datos) << listado << "\n\n";

        for(Producto &producto : productos)
        {
            QTextStream(&datos)
            << producto.mostrarInformacion()
            << "\n";
        }
    }

    else if(listado == "Ultimas Compras")
    {
        QTextStream(&datos) << listado << "\n\n";

        queue<Compra> lista = compras; //copia de la cola compras

        while(!lista.empty())
        {
            Compra compra = lista.front();

            QTextStream(&datos)
                << compra.mostrarInformacion()
                << "\n";

            lista.pop();
        }
    }

    ui->txtListas->setText(datos);
}


void MainWindow::on_cbxGestionar_activated(int index)
{
    QString opcion = ui->cbxGestionar->currentText();

    if(opcion == "Clientes")
    {
        ui->grpClientes->setVisible(true);
        ui->grpProductos->setVisible(false);
        ui->grpCompras->setVisible(false);
    }

    else if(opcion == "Productos")
    {
        ui->grpClientes->setVisible(false);
        ui->grpProductos->setVisible(true);
        ui->grpCompras->setVisible(false);
    }

    else if(opcion == "Compras")
    {
        ui->grpClientes->setVisible(false);
        ui->grpProductos->setVisible(false);
        ui->grpCompras->setVisible(true);
    }
}


//AGREGAR CLIENTE

void MainWindow::on_btnAgregarCliente_clicked()
{
    if(ui->txtCodigoClientes->text().isEmpty() ||
        ui->txtNombreCliente->text().isEmpty() ||
        ui->txtCorreoCliente->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Complete todos los datos");
        return;
    }

    Cliente cliente(
        ui->txtCodigoClientes->text().toStdString(),
        ui->txtNombreCliente->text().toStdString(),
        ui->txtCorreoCliente->text().toStdString()
        );

    clientes.push_back(cliente);

    QMessageBox::information(this, "Cliente", "Cliente agregado");

    ui->txtCodigoClientes->clear();
    ui->txtNombreCliente->clear();
    ui->txtCorreoCliente->clear();
}



void MainWindow::on_btnBuscarCliente_clicked()
{
    if(ui->txtCodigoClientes->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Ingrese el codigo del cliente");
        return;
    }

    string codigo = ui->txtCodigoClientes->text().toStdString();

    vector<Cliente>::iterator it;

    for(it = clientes.begin(); it != clientes.end(); ++it)
    {
        if(it->getCodigo() == codigo)
        {
            ui->txtNombreCliente->setText(
                QString::fromStdString(it->getNombre())
                );

            ui->txtCorreoCliente->setText(
                QString::fromStdString(it->getCorreo())
                );

            return;
        }
    }QMessageBox::warning(this, "Cliente", "Cliente no encontrado");
}


void MainWindow::on_btnModificarCliente_clicked()
{
    if(ui->txtCodigoClientes->text().isEmpty() ||
        ui->txtNombreCliente->text().isEmpty() ||
        ui->txtCorreoCliente->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Complete todos los datos");
        return;
    }

    string codigo = ui->txtCodigoClientes->text().toStdString();

    vector<Cliente>::iterator it;

    for(it = clientes.begin(); it != clientes.end(); ++it)
    {
        if(it->getCodigo() == codigo)
        {
            it->setNombre(
                ui->txtNombreCliente->text().toStdString()
                );

            it->setCorreo(
                ui->txtCorreoCliente->text().toStdString()
                );

            QMessageBox::information(this, "Cliente", "Cliente modificado.");

            return;
        }
    }

    QMessageBox::warning(this, "Cliente", "Cliente no encontrado.");
}

void MainWindow::on_btnEliminarCliente_clicked()
{
    if(ui->txtCodigoClientes->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Ingrese el codigo del cliente");
        return;
    }

    string codigo = ui->txtCodigoClientes->text().toStdString();

    vector<Cliente>::iterator it;

    for(it = clientes.begin(); it != clientes.end(); ++it)
    {
        if(it->getCodigo() == codigo)
        {
            clientes.erase(it);

            QMessageBox::information(this, "Cliente", "Cliente eliminado");

            ui->txtCodigoClientes->clear();
            ui->txtNombreCliente->clear();
            ui->txtCorreoCliente->clear();

            return; }
    }
    QMessageBox::warning(this, "Cliente", "Cliente no se ha encontrado");
}
