#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QMessageBox>

#include "cliente.h"
#include "producto.h"
#include "compra.h"

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


//*****Cambios Kathia🗣️🗣️********
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

//int index lo removi, porque no parece que se implemente dentro de la funcion
void MainWindow::on_cbxGestionar_activated()
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
    if(ui->txtCodigoCrearClientes->text().isEmpty() ||
        ui->txtNombreCliente->text().isEmpty() ||
        ui->txtCorreoCliente->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Complete todos los datos");
        return;
    }

    Cliente cliente(
        ui->txtCodigoCrearClientes->text().toStdString(),
        ui->txtNombreCliente->text().toStdString(),
        ui->txtCorreoCliente->text().toStdString()
        );

    clientes.push_back(cliente);

    QMessageBox::information(this, "Cliente", "Cliente agregado");

    ui->txtCodigoCrearClientes->clear();
    ui->txtNombreCliente->clear();
    ui->txtCorreoCliente->clear();

}



void MainWindow::on_btnBuscarCliente_clicked()
{
    if(ui->txtCodigoCrearClientes->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Ingrese el codigo del cliente");
        return;
    }

    string codigo = ui->txtCodigoCrearClientes->text().toStdString();

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
    if(ui->txtCodigoCrearClientes->text().isEmpty() ||
        ui->txtNombreCliente->text().isEmpty() ||
        ui->txtCorreoCliente->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Complete todos los datos");
        return;
    }

    string codigo = ui->txtCodigoCrearClientes->text().toStdString();

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
    if(ui->txtCodigoCrearClientes->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Ingrese el codigo del cliente");
        return;
    }

    string codigo = ui->txtCodigoCrearClientes->text().toStdString();

    vector<Cliente>::iterator it;

    for(it = clientes.begin(); it != clientes.end(); ++it)
    {
        if(it->getCodigo() == codigo)
        {
            clientes.erase(it);

            QMessageBox::information(this, "Cliente", "Cliente eliminado");

            ui->txtCodigoCrearClientes->clear();
            ui->txtNombreCliente->clear();
            ui->txtCorreoCliente->clear();

            return; }
    }
    QMessageBox::warning(this, "Cliente", "Cliente no se ha encontrado");
}



//AGREGAR PROPDUCTO

void MainWindow::on_btnAgregarProducto_clicked()
{
    if(ui->txtCodigoClientes->text().isEmpty() ||
        ui->txtNombreProducto->text().isEmpty() ||
        ui->txtCantidadProducto->text().isEmpty() ||
        ui->txtPrecioProducto->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Complete todos los datos");
        return;
    }

    Producto producto(
        ui->txtCodigoClientes->text().toStdString(),
        ui->txtNombreProducto->text().toStdString(),
        ui->txtPrecioProducto->text().toDouble(),
        ui->txtCantidadProducto->text().toInt()
        );

    productos.push_front(producto);

    QMessageBox::information(this, "Producto", "Producto agregado");

    ui->txtCodigoClientes->clear();
    ui->txtNombreProducto->clear();
    ui->txtPrecioProducto->clear();
    ui->txtCantidadProducto->clear();

}



void MainWindow::on_btnBuscarProducto_clicked()
{
    if(ui->txtCodigoClientes->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Ingrese el codigo del producto");
        return;
    }

    string codigo = ui->txtCodigoClientes->text().toStdString();

    list<Producto>::iterator it;

    for(it = productos.begin(); it != productos.end(); ++it)
    {
        if(it->getCodigo() == codigo)
        {
            ui->txtNombreProducto->setText(
                QString::fromStdString(it->getNombre())
                );

            ui->txtPrecioProducto->setText(
                 QString::number(it->getPrecio())

                );
            ui->txtCantidadProducto->setText(
                 QString::number(it->getCantidad())

                );

            return;
        }
    }QMessageBox::warning(this, "Producto", "Producto no encontrado");
}


void MainWindow::on_btnModificarProducto_clicked()
{
    if(ui->txtCodigoClientes->text().isEmpty() ||
        ui->txtNombreProducto->text().isEmpty() ||
        ui->txtCantidadProducto->text().isEmpty() ||
        ui->txtPrecioProducto->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Complete todos los datos");
        return;
    }

    string codigo = ui->txtCodigoClientes->text().toStdString();

    list<Producto>::iterator it;

    for(it = productos.begin(); it != productos.end(); ++it)
    {
        if(it->getCodigo() == codigo)
        {
            it->setNombre(
                ui->txtNombreProducto->text().toStdString()
                );

            it->setPrecio(
                ui->txtCantidadProducto->text().toDouble()
                );
            it->setCantidad(
                ui->txtCantidadProducto->text().toInt()
                );

            QMessageBox::information(this, "Producto", "Producto modificado.");
            ui->txtCodigoClientes->clear();
            ui->txtNombreProducto->clear();
            ui->txtPrecioProducto->clear();
            ui->txtCantidadProducto->clear();
            return;
        }
    }

    QMessageBox::warning(this, "Proucto", "Producto no encontrado.");
}

void MainWindow::on_btnEliminarProducto_clicked()
{
    if(ui->txtCodigoClientes->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Ingrese el codigo del producto.");
        return;
    }

    string codigo = ui->txtCodigoClientes->text().toStdString();

    list<Producto>::iterator it;

    for(it = productos.begin(); it != productos.end(); ++it)
    {
        if(it->getCodigo() == codigo)
        {
            productos.erase(it);

            QMessageBox::information(this, "Producto", "Producto eliminado");

            ui->txtCodigoClientes->clear();
            ui->txtNombreProducto->clear();
            ui->txtPrecioProducto->clear();
            ui->txtCantidadProducto->clear();

            return; }
    }
    QMessageBox::warning(this, "Producto", "Producto no se ha encontrado");
}



//AGREGAR COMPRA

void MainWindow::on_btnAgregarCompra_clicked()
{
    if(ui->txtCodigoCompras->text().isEmpty() ||
        ui->txtClienteCompras->text().isEmpty() ||
        ui->txtProductoCompras->text().isEmpty() ||
        ui->txtPrecioCompras->text().isEmpty() ||
        ui->txtCantidadCompras->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Complete todos los datos");
        return;
    }

    Compra compra(
        ui->txtCodigoCompras->text().toStdString(),
        ui->txtClienteCompras->text().toStdString(),
        ui->txtProductoCompras->text().toStdString(),
        ui->txtCantidadCompras->text().toInt(),
        ui->txtPrecioCompras->text().toDouble()
        );

    compras.push(compra);

    QMessageBox::information(this, "Compra", "Compra agregada");

    ui->txtCodigoCompras->clear();
    ui->txtClienteCompras->clear();
    ui->txtProductoCompras->clear();
    ui->txtCantidadCompras->clear();
    ui->txtPrecioCompras->clear();

}



void MainWindow::on_btnBuscarCompra_clicked()
{
    if(ui->txtCodigoCompras->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Ingrese el codigo de la compra.");
        return;
    }

    string codigo = ui->txtCodigoCompras->text().toStdString();


    queue<Compra> copia_compra = compras;


    while(!copia_compra.empty()){
        auto& current_item = copia_compra.front();
        ui->txtCodigoCompras->clear();
        ui->txtClienteCompras->clear();
        ui->txtProductoCompras->clear();
        ui->txtCantidadCompras->clear();
        ui->txtPrecioCompras->clear();

        if(current_item.getCodigo() == codigo){
            ui->txtCodigoCompras->setText(QString::fromStdString(current_item.getCodigo()));
            ui->txtClienteCompras->setText(QString::fromStdString(current_item.getCliente()));
            ui->txtProductoCompras->setText(QString::fromStdString(current_item.getProducto()));
            ui->txtCantidadCompras->setText(QString::number(current_item.getCantidad()));
            ui->txtPrecioCompras->setText(QString::number(current_item.getPrecio()));

            QMessageBox::information(this, "Compra", "Compra Encontrada");

            return;
        }//if validation end
        copia_compra.pop();
    }
    QMessageBox::warning(this, "Compra", "Compra no encontrada.");
}


void MainWindow::on_btnModificarCompra_clicked()
{
    if(ui->txtCodigoCompras->text().isEmpty() ||
        ui->txtClienteCompras->text().isEmpty() ||
        ui->txtProductoCompras->text().isEmpty() ||
        ui->txtPrecioCompras->text().isEmpty() ||
        ui->txtCantidadCompras->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Complete todos los datos");
        return;
    }

    string codigo = ui->txtCodigoCompras->text().toStdString();


    while(!compras.empty()){
         auto& current_item = compras.front();


        if(current_item.getCodigo() == codigo){
             current_item.setCliente(ui->txtClienteCompras->text().toStdString());
             current_item.setProducto(ui->txtProductoCompras->text().toStdString());
             current_item.setCantidad(ui->txtCantidadCompras->text().toInt());
             current_item.setPrecio(ui->txtPrecioCompras->text().toDouble());

             QMessageBox::information(this, "Compra", "Compra modificada.");
             ui->txtCodigoCompras->clear();
             ui->txtClienteCompras->clear();
             ui->txtProductoCompras->clear();
             ui->txtCantidadCompras->clear();
             ui->txtPrecioCompras->clear();
             return;

        }//end if condition
        compras.pop();
    }//end while statement

    QMessageBox::warning(this, "Compra", "Compra no encontrada.");
}

void MainWindow::on_btnEliminarCompra_clicked()
{
    if(ui->txtCodigoCompras->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Ingrese el codigo del producto.");
        return;
    }

    string codigo = ui->txtCodigoCompras->text().toStdString();

    while(!compras.empty()){
        auto& current_item = compras.front();
        if(current_item.getCodigo() == codigo){
           compras.pop();
            QMessageBox::information(this, "Compra", "Compra eliminada");

            ui->txtCodigoCompras->clear();
            ui->txtClienteCompras->clear();
            ui->txtProductoCompras->clear();
            ui->txtPrecioCompras->clear();
            ui->txtCantidadCompras->clear();

            return;
        }//end if statement
    }//end while statement
    QMessageBox::warning(this, "Compra", "La Compra no se ha encontrado");
}














