#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>

using namespace std;

class Registro
{
public:
    Registro();
    virtual ~Registro();

    string getCodigo() const;
    void setCodigo(string);

private:
    string codigo;
};

#endif // REGISTRO_H
