#include "cliente.h"
#include <QTextStream>

Cliente::Cliente(string codigo, string nombre, string correo):Registro(codigo)
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

QString Cliente::mostrarInformacion() const
{
    QString datos;

    QTextStream(&datos)
        << "Codigo: " << QString::fromStdString(getCodigo())
        << "\nNombre: " << QString::fromStdString(nombre)
        << "\nCorreo: " << QString::fromStdString(correo)
        << Qt::endl;

    return datos;
}
