#include "cliente.h"

Cliente::Cliente(string codigo, string nombre, string correo)
    : Registro(codigo)
{
    this->nombre = nombre;
    this->correo = correo;
}

Cliente::~Cliente()
{

}

string Cliente::getNombre() const
{
    return nombre;
}

void Cliente::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Cliente::getCorreo() const
{
    return correo;
}

void Cliente::setCorreo(string correo)
{
    this->correo = correo;
}

string Cliente::mostrarInformacion() const
{
    return "Codigo: " + getCodigo() + "\nNombre: " + nombre + "\nCorreo: " + correo;
}
