//
// Created by USER on 5/06/2026.
//

#ifndef LAB08_PREG02_TESORERIA_H
#define LAB08_PREG02_TESORERIA_H
#include "Escala.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"


class Tesoreria {
private:
    Presencial lpresencial[80];
    Semipresencial lsemipresencial[80];
    Virtual *lvirtual;
    Escala lescala[5];
public:
    Tesoreria();
    virtual ~Tesoreria();
    void cargaescalas();
    void imprime();
    void cargaalumnos();

    void actualiza(int cred);
    void recorte();
    bool isnull();
    int cuentaVirtuales();
    int buscarPos(Presencial aux, int cant_presencial);

};


#endif //LAB08_PREG02_TESORERIA_H
