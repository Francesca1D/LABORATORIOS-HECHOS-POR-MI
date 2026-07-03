//
// Created by USER on 18/06/2026.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_2025_2_LISTA_H
#define STREAMERSPOLIMORFISMOYLISTAS_2025_2_LISTA_H
#include "Nodo.h"
#include <fstream>

using namespace std;

class Lista {
private:
    class Nodo *listaDoblementeLigada;

public:
    Lista();
    virtual ~Lista();

    void crearLista(ifstream &arch);
    void insertarNodo();
    void crearReporte();
    void actualizar();

};


#endif //STREAMERSPOLIMORFISMOYLISTAS_2025_2_LISTA_H
