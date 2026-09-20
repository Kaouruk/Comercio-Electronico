#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Estructuras
//Queue para la listas de compras
//List para la lista de productos
//Vector para la lista de clientes



void MainWindow::on_buttonMostrarListado_clicked()
{
    clientes.push_back("Carlos");//vector
    productos.push_back("Tablet");//lista
    compras.push("TV LG");

    QString listado = ui->inputTipoListado->currentText();

    QString datos;

    QTextStream(&datos) << listado
                        << "\n Vector Clientes: " << clientes.front()//vector
                        <<  "\n Lista Productos: " <<productos.front() //lista
                        <<  "\n Cola Compras: " << compras.front()//queue
                        << Qt::endl;


    ui->txtListas->append(datos);

}

//trabajar en un metodo de impresion de cada clase que sea de tipo QString, por ende su valor de retorno sera un QString