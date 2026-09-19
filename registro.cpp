#include "registro.h"

Registro::Registro()
{
    codigo = "";
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
