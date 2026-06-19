//
// Created by USER on 18/06/2026.
//

#ifndef PREG01_LAB08_2024_2_COLA_H
#define PREG01_LAB08_2024_2_COLA_H
#include "Nodo.h"


class Cola {
private:
    int longitud;
    Nodo *cabeza;
    Nodo *cola;

public:
    Cola();
    virtual ~Cola();
    int get_longitud() const;
    void set_longitud(int longitud);

    void encola(Nodo *);
    Nodo * desencola();

    void cargacola(ifstream &arch);
    void imprimecola(ofstream &arch);


};


#endif //PREG01_LAB08_2024_2_COLA_H
