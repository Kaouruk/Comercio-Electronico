#include "cliente.h"
#include <QTextStream>

Cliente::Cliente(string codigo, string nombre, string correo):Registro(codigo)
{
    this->nombre = nombre;
    this->correo = correo;
    this->codigo = codigo;
}

Cliente::~Cliente()
{

}

string Cliente::getClienteCodigo() const
{
    return codigo;
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

    QString code = QString::fromStdString(getCodigo());
    QString client = QString::fromStdString(nombre);
    QString mail = QString::fromStdString(correo);


    QString rowInfo = QString("%1%2%3").arg(code, 5).arg(client, 25).arg(mail, 28);
    QTextStream(&datos) << "\n" << rowInfo
        << Qt::endl;

    return datos;
}
