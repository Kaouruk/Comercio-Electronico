#include "compra.h"

Compra::Compra() : Registro()
{
    cliente = "";
    producto = "";
    cantidad = 0;
    precio = 0.0;
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
