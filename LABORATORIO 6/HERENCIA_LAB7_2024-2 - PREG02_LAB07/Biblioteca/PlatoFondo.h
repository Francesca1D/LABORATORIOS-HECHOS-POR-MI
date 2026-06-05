//
// Created by USER on 3/06/2026.
//

#ifndef HERENCIA_LAB7_2024_2_PLATOFONDO_H
#define HERENCIA_LAB7_2024_2_PLATOFONDO_H
#include "Producto.h"


class PlatoFondo: public Producto {
    private:
    int *proteina;

public:
    PlatoFondo();
    virtual ~PlatoFondo();
    int * get_proteina() const;
    void set_proteina(int *proteina);
    void leeplatos(ifstream &arch);
    void imprimeplatos_fondo(ofstream &arch);
    double calcularplatos_fondo();
};


#endif //HERENCIA_LAB7_2024_2_PLATOFONDO_H
