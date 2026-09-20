#include "registro.h"

Registro::Registro(string codigo)
{
    this->codigo = codigo;
}

Registro::~Registro()
{

}

string Registro::getCodigo() const
{
    return codigo;
}

void Registro::setCodigo(string codigo)
{
    this->codigo = codigo;
}

QString Registro::mostrarInformacion() const
{
    QString datos;

    datos = "Codigo: " + QString::fromStdString(codigo);

    return datos;
}
