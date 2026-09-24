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

    QString code = QString::fromStdString(getCodigo());
    QString prod = QString::fromStdString(nombre);


    QString rowInfo = QString("%1%2%3%4").arg(code, -5).arg(prod, 20).arg(precio, 28).arg(cantidad, 28);
    QTextStream(&datos) << "\n" << rowInfo
        << Qt::endl;

    return datos;
}
