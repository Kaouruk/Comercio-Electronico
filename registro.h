#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>
#include <QString>

using namespace std;

class Registro
{
public:

    Registro(string = "");

    virtual ~Registro();

    string getCodigo() const;
    void setCodigo(string);

    virtual QString mostrarInformacion() const;

private:

    string codigo;
};

#endif // REGISTRO_H
