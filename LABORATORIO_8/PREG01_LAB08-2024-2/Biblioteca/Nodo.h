//
// Created by USER on 18/06/2026.
//

#ifndef PREG01_LAB08_2024_2_NODO_H
#define PREG01_LAB08_2024_2_NODO_H
#include "DetalleComanda.h"


class Nodo {
private:
    DetalleComanda dato;
    Nodo *sig;

public:
    Nodo();
    virtual ~Nodo();

    void carganodo(ifstream &arch);
    void imprimenodo(ofstream &arch);

    friend class Cola;

};


#endif //PREG01_LAB08_2024_2_NODO_H
