#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "registro.h"

class Producto : public Registro
{
public:

    Producto(string = "", string = "", double = 0.0, int = 0);

    ~Producto();

    string getNombre() const;
    void setNombre(string);

    double getPrecio() const;
    void setPrecio(double);

    int getCantidad() const;
    void setCantidad(int);

    string mostrarInformacion() const override;

private:

    string nombre;
    double precio;
    int cantidad;
};

#endif // PRODUCTO_H
