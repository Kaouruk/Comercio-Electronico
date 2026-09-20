#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Cliente cliente("cliente001", "Kathia", "ccccs@gmail.com");
    Producto producto("Producto001", "Tablet", 1500, 5);
    Compra compra("Compra001", "Cliente001", "Producto001", 2, 5500);

    clientes.push_back(cliente);//vector
    productos.push_back(producto);//lista
    compras.push(compra);//cola

}


//Estructuras
//Queue para la lista de compras
//List para la lista de productos
//Vector para la lista de clientes

//*****Cambios Kathia********
//Hice el cambio para que las clases usen mostrarinformacion() para mostrar los datos en la GUI
//Modifiqué los datos de prueba para que trabajaran segun los atributos de las clases
//Cambie el que las estructuras dejaran de trabajar con Qstring y trabajen con las clases
//Saqué los datos de prueba del boton


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
        for(Cliente &cliente : clientes)//recorremos las listas con un for

        {
            QTextStream(&datos) << cliente.mostrarInformacion() << "\n";
        }
    }

    else if(listado == "Productos")
    {
        QTextStream(&datos) << listado << "\n\n";

        for(Producto &producto : productos)//recorremos las listas con un for
        {
            QTextStream(&datos) << producto.mostrarInformacion() << "\n";
        }
    }

    else if(listado == "Ultimas Compras")
    {
        QTextStream(&datos) << listado << "\n\n";
        queue<Compra> lista = compras;//hace una copia de la cola compras


        while(!lista.empty())
        {
            Compra compra = lista.front();
            QTextStream(&datos) << compra.mostrarInformacion()<< "\n";
            lista.pop();
        }
    }


    ui->txtListas->setText(datos);
}


