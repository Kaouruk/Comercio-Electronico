#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>

using namespace std;

class Registro
{
public:

    Registro(string = "");

    virtual ~Registro();

    string getCodigo() const;
    void setCodigo(string);

    virtual string mostrarInformacion() const;

private:

    string codigo;
};

#endif // REGISTRO_H
