#ifndef CLIENTE_H
#define CLIENTE_H

#include "registro.h"

class Cliente : public Registro
{
public:
    Cliente();
    ~Cliente();

    string getNombre() const;
    void setNombre(string);

    string getCorreo() const;
    void setCorreo(string);

private:
    string nombre;
    string correo;
};

#endif // CLIENTE_H
