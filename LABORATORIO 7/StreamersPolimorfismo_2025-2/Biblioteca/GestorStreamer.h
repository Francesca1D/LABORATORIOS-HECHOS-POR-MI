//
// Created by USER on 11/06/2026.
//

#ifndef STREAMERSPOLIMORFISMO_2025_2_GESTORSTREAMER_H
#define STREAMERSPOLIMORFISMO_2025_2_GESTORSTREAMER_H
#include "Metrica.h"


class GestorStreamer {
private:
    Metrica * ptrmetrica;

public:
    GestorStreamer();
    virtual ~GestorStreamer();
    void leeStreamer(ifstream &arch);
    int obtenerIDStreamer();
    void imprimirStreamer(ofstream &arch);

};


#endif //STREAMERSPOLIMORFISMO_2025_2_GESTORSTREAMER_H
