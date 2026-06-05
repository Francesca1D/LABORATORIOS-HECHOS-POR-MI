//
// Created by USER on 3/06/2026.
//

#ifndef HERENCIA_LAB7_2024_2_BEBIDA_H
#define HERENCIA_LAB7_2024_2_BEBIDA_H
#include "Producto.h"


class Bebida: public Producto {
private:
    char *tamano;

public:
    Bebida();
    virtual ~Bebida();
    void get_tamano(char *cad);
    void set_tamano(const char *cad);
    void leebebidas(ifstream &);
    void imprimebebida(ofstream &arch);
};


#endif //HERENCIA_LAB7_2024_2_BEBIDA_H
