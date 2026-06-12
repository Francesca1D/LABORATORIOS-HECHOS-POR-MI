//
// Created by USER on 11/06/2026.
//

#ifndef PREG01_LAB08_2024_2_BEBIDA_H
#define PREG01_LAB08_2024_2_BEBIDA_H
#include "Producto.h"


class Bebida: public Producto{
private:
    char *tamano;

public:
    Bebida();
    virtual ~Bebida();
    void get_tamano(char *cad);
    void set_tamano(const char *cad);
    void lee(ifstream &arch);
    void imprimir(ofstream &arch);


};


#endif //PREG01_LAB08_2024_2_BEBIDA_H
