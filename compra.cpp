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

    QTextStream(&datos)
        << "Codigo: " << QString::fromStdString(getCodigo())
        << "\nCodigo cliente: " << QString::fromStdString(cliente)
        << "\nProducto: " << QString::fromStdString(producto)
        << "\nCantidad: " << cantidad
        << "\nPrecio: " << precio
        << "\nTotal: " << calcularTotal()
        << Qt::endl;

    return datos;
}
