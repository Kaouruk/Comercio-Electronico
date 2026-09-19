#include "producto.h"

Producto::Producto() : Registro()
{
    nombre = "";
    precio = 0.0;
    cantidad = 0;
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
