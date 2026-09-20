#include "producto.h"

Producto::Producto(string codigo, string nombre, double precio, int cantidad)
    : Registro(codigo)
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

string Producto::mostrarInformacion() const
{
    return "Codigo: " + getCodigo() + "\nProducto: " + nombre +
           "\nPrecio: " + to_string(precio) + "\nCantidad: " + to_string(cantidad);
}
