#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QMessageBox>
#include "xlsxdocument.h"
#include <QFileDialog>
#include <QStandardPaths>

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
        QString headerInfo = QString("%1%2%3")
                                 .arg("Codigo", -5)
                                 .arg("Cliente", 20)
                                 .arg("Correo ", 25);
        QTextStream(&datos)
            << listado << "\n\n"
            << headerInfo
            << "\n_________________________________________________";

        for(Cliente &cliente : clientes)
        {
            QTextStream(&datos)
            << cliente.mostrarInformacion()
            << "_________________________________________________"
            << "\n";
        }
    }

    else if(listado == "Productos")
    {

        QString headerInfo = QString("%1%2%3%4")
                                 .arg("Codigo", -5)
                                 .arg("Producto", 20)
                                 .arg("Precio $", 25)
                                 .arg("Cantidad", 20);

        QTextStream(&datos)
            << listado
            << "\n\n"
            << headerInfo  << "\n_________________________________________________";

        for(Producto &producto : productos)
        {
            QTextStream(&datos)
            << producto.mostrarInformacion()
            << "_________________________________________________"
            << "\n";
        }
    }

    else if(listado == "Ultimas Compras")
    {
        QString headerInfo = QString("%1%2%3%4%5")
                                .arg("Codigo", -5)
                                .arg("Cliente", 20)
                                .arg("Producto", 25)
                                .arg("Cantidad", 15)
                                .arg("Precio", 15);

        QTextStream(&datos)
            << listado
            << "\n\n"
            << headerInfo  << "\n________________________________________________________";

        queue<Compra> lista = compras; //copia de la cola compras

        while(!lista.empty())
        {
            Compra compra = lista.front();

            QTextStream(&datos)
                << compra.mostrarInformacion()
                << "\n________________________________________________________"
                << "\n";

            lista.pop();
        }
    }
    else if(listado == "Prod Existentes"){
        if(productos.empty()){
            QMessageBox::warning(this, "Error", "No hay productos!, Antes de realizar una compra, agregue un producto.");
            return;
        }
        QString headerInfo = QString("%1%2%3%4")
        .arg("Codigo", -5)
            .arg("Producto", 20)
            .arg("Precio $", 25)
            .arg("Cantidad", 20);

        QTextStream(&datos)
            << listado
            << "\n\n"
            << headerInfo  << "\n_________________________________________________";

        for(Producto &producto : productos)
        {
            QTextStream(&datos)
            << producto.mostrarInformacion()
            << "_________________________________________________"
            << "\n";
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
    string codigo = ui->txtCodigoCrearClientes->text().toStdString();
    vector<Cliente>::iterator it;

    //Search each object to see if the code already exist.
    for(it = clientes.begin(); it != clientes.end(); ++it)
    {
        if(it->getCodigo() == codigo)
        {
            QMessageBox::warning(this, "Error", "Ya existe un cliente con ese ID.");
            return;
        }
    }

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
    string codigo = ui->txtCodigoClientes->text().toStdString();

    list<Producto>::iterator it;
    //Search each object to see if the code already exist.
    for(it = productos.begin(); it != productos.end(); ++it)
    {
        if(it->getCodigo() == codigo)
        {
            QMessageBox::warning(this, "Error", "Ya existe un producto con ese ID.");
            return;
        }
    }
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
    if(productos.empty()){
        QMessageBox::warning(this, "Error", "No hay productos!, Antes de realizar una compra, agregue un producto.");
        return;
    }
    string codigo = ui->txtCodigoCompras->text().toStdString();

    queue<Compra> copia_compra = compras;

    //Search each object to see if the code already exist.
    while(!copia_compra.empty()){
        auto& current_item = copia_compra.front();
        if(current_item.getCodigo() != codigo){
            QMessageBox::warning(this, "Error", "No existe un producto con ese ID.");
            return;
        }
        copia_compra.pop();
    }

    if(ui->txtCodigoCompras->text().isEmpty()
       /* ui->txtClienteCompras->text().isEmpty() ||
        ui->txtProductoCompras->text().isEmpty() ||
        ui->txtPrecioCompras->text().isEmpty() ||
        ui->txtCantidadCompras->text().isEmpty()*/)
    {
        QMessageBox::warning(this, "Error", "Agregue el ID del producto");
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


void MainWindow::on_btnDescargarRegistros_clicked()
{
    QString rutaInicial = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Reporte.xlsx";

    //ventana para guardar el archivo
    QString rutaSeleccionada = QFileDialog::getSaveFileName(
        this,
        "Guardar Reporte de Excel",
        rutaInicial,
        "Archivos de Excel (*.xlsx)"
        );

    //valida si el usuario guardo el archivo o cancelo
    if (rutaSeleccionada.isEmpty()) {
        return;
    }

    QXlsx::Document xlsx;

    xlsx.renameSheet("Clientes", "Clientes");

    //cabecera del reporte "Clientes"
    xlsx.write(2, 2, "Reporte Clientes: ");
    xlsx.write(4, 2, "Codigo");
    xlsx.write(4, 3, "Cliente");
    xlsx.write(4, 4, "Correo");

    int rowCliente = 5;
    for(Cliente &cliente : clientes)
    {
        xlsx.write(rowCliente,2,QString::fromStdString(cliente.getCodigo()));
        xlsx.write(rowCliente,3,QString::fromStdString(cliente.getNombre()));
        xlsx.write(rowCliente,4,QString::fromStdString(cliente.getCorreo()));
        rowCliente++;
    }

    xlsx.addSheet("Productos");

    //cabecera del reporte "Productos"
    xlsx.write(2, 2, "Reporte Productos: ");
    xlsx.write(4, 2, "Codigo");
    xlsx.write(4, 3, "Producto");
    xlsx.write(4, 4, "Precio");
    xlsx.write(4, 5, "Cantidad");

    int rowProduct = 5;
    for(Producto &producto : productos)
    {
        xlsx.write(rowProduct,2,QString::fromStdString(producto.getCodigo()));
        xlsx.write(rowProduct,3,QString::fromStdString(producto.getNombre()));
        xlsx.write(rowProduct,4,producto.getPrecio());
        xlsx.write(rowProduct,5,producto.getCantidad());
        rowProduct++;
    }

    xlsx.addSheet("Ventas");

    //cabecera del reporte "Ventas"
    xlsx.write(2, 2, "Reporte Ventas: ");
    xlsx.write(4, 2, "Codigo");
    xlsx.write(4, 3, "Cliente");
    xlsx.write(4, 4, "Producto");
    xlsx.write(4, 5, "Cantidad");
    xlsx.write(4, 6, "Precio");

    queue<Compra> lista = compras; //copia de la cola compras
    int rowCompra = 5;
    while(!lista.empty())
    {
        Compra compra = lista.front();

        xlsx.write(rowProduct,2,QString::fromStdString(compra.getCodigo()));
        xlsx.write(rowProduct,3,QString::fromStdString(compra.getCliente()));
        xlsx.write(rowProduct,4,QString::fromStdString(compra.getProducto()));
        xlsx.write(rowProduct,5,compra.getCantidad());
        xlsx.write(rowProduct,6,compra.getPrecio());
        rowCompra++;

        lista.pop();
    }

    if (xlsx.saveAs(rutaSeleccionada)) {
        QMessageBox::information(this, "Éxito", "¡El archivo Excel se guardó correctamente!");
    } else {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo.\nVerifica si está abierto en Excel o si tienes permisos de escritura.");
    }
}

