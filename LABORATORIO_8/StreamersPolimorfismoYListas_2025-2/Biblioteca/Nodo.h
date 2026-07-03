//
// Created by USER on 18/06/2026.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_2025_2_NODO_H
#define STREAMERSPOLIMORFISMOYLISTAS_2025_2_NODO_H
#include "Metrica.h"

class Nodo {
private:
    class Metrica*metrica;
    class Nodo *anterior;
    class Nodo *siguiente;
public:
    Nodo();
    virtual ~Nodo();

    void carganodo(ifstream &arch);

    friend class Lista;

};


#endif //STREAMERSPOLIMORFISMOYLISTAS_2025_2_NODO_H
