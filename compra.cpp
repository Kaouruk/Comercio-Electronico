#include "compra.h"
#include <QTextStream>

Compra::Compra(string codigo, string cliente, string producto,int cantidad, double precio)
    : Registro(codigo)
{
    this->cliente = cliente;
    this->producto = producto;
    this->cantidad = cantidad;
    this->precio = precio;
}

Compra::~Compra()
{

}

string Compra::getCliente() const
{
    return cliente;
}

void Compra::setCliente(string cliente)
{
    this->cliente = cliente;
}

string Compra::getProducto() const
{
    return producto;
}

void Compra::setProducto(string producto)
{
    this->producto = producto;
}

int Compra::getCantidad() const
{
    return cantidad;
}

void Compra::setCantidad(int cantidad)
{
    if(cantidad > 0)
    {
        this->cantidad = cantidad;
    }
}

double Compra::getPrecio() const
{
    return precio;
}

void Compra::setPrecio(double precio)
{
    if(precio > 0.0)
    {
        this->precio = precio;
    }
}

double Compra::calcularTotal() const
{
    return cantidad * precio;
}

QString Compra::mostrarInformacion() const
{
    QString datos;

    QString code = QString::fromStdString(getCodigo());
    QString client = QString::fromStdString(cliente);
    QString prod = QString::fromStdString(producto);

    QString rowInfo = QString("%1%2%3%4%5").arg(code, 5).arg(client, 25).arg(prod, 25).arg(cantidad, 12).arg(precio, 17);

    QTextStream(&datos)  << "\n" << rowInfo
        // << "Codigo: " << QString::fromStdString(getCodigo())
        // << "\nCliente: " << QString::fromStdString(cliente)
        // << "\nProducto: " << QString::fromStdString(producto)
        // << "\nCantidad: " << cantidad
        //     << "\nPrecio: " << precio << "$"
        // << "\nTotal: " << calcularTotal()
        << Qt::endl;

    return datos;
}
