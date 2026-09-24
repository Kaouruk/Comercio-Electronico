#ifndef CLIENTE_H
#define CLIENTE_H
#include "registro.h"

class Cliente : public Registro
{
public:

    Cliente(string = "", string = "", string = "");
    ~Cliente();

    string getClienteCodigo() const;
    // void setNombre(string);

    string getNombre() const;
    void setNombre(string);

    string getCorreo() const;
    void setCorreo(string);

    QString mostrarInformacion() const;

private:
    string codigo;
    string nombre;
    string correo;
};

#endif // CLIENTE_H
