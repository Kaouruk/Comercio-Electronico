#include "producto.h"
#include <QTextStream>

Producto::Producto(string codigo, string nombre, double precio, int cantidad):Registro(codigo)
{
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
}

Producto::~Producto()
{

}

string Producto::getNombre() const
{
    return nombre;
}

void Producto::setNombre(string nombre)
{
    this->nombre = nombre;
}

double Producto::getPrecio() const
{
    return precio;
}

void Producto::setPrecio(double precio)
{
    if(precio > 0.0)
    {
        this->precio = precio;
    }
}

int Producto::getCantidad() const
{
    return cantidad;
}

void Producto::setCantidad(int cantidad)
{
    if(cantidad >= 0)
    {
        this->cantidad = cantidad;
    }
}

QString Producto::mostrarInformacion() const
{
    QString datos;

    QTextStream(&datos)
        << "Codigo: " << QString::fromStdString(getCodigo())
        << "\nProducto: " << QString::fromStdString(nombre)
        << "\nPrecio: " << precio
        << "\nCantidad: " << cantidad
        << Qt::endl;

    return datos;
}
