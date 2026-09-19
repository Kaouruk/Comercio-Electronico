#include "cliente.h"

Cliente::Cliente() : Registro()
{
    nombre = "";
    correo = "";


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
