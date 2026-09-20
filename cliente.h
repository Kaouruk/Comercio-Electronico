#ifndef CLIENTE_H
#define CLIENTE_H
#include "registro.h"

class Cliente : public Registro
{
public:

    Cliente(string = "", string = "", string = "");
    ~Cliente();

    string getNombre() const;
    void setNombre(string);

    string getCorreo() const;
    void setCorreo(string);

    QString mostrarInformacion() const;

private:

    string nombre;
    string correo;
};

#endif // CLIENTE_H
