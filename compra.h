#ifndef COMPRA_H
#define COMPRA_H
#include "registro.h"

class Compra : public Registro
{
public:

    Compra(string = "", string = "", string = "",int = 0, double = 0.0);

    ~Compra();

    string getCliente() const;
    void setCliente(string);

    string getProducto() const;
    void setProducto(string);

    int getCantidad() const;
    void setCantidad(int);

    double getPrecio() const;
    void setPrecio(double);

    double calcularTotal() const;

    QString mostrarInformacion() const;

private:

    string cliente;
    string producto;
    int cantidad;
    double precio;
};

#endif // COMPRA_H
