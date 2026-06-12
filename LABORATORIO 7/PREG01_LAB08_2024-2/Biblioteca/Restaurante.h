//
// Created by USER on 11/06/2026.
//

#ifndef PREG01_LAB08_2024_2_RESTAURANTE_H
#define PREG01_LAB08_2024_2_RESTAURANTE_H
#include "DetalleComanda.h"


class Restaurante {
private:
    DetalleComanda comandas[120];

public:
    Restaurante();
    virtual ~Restaurante();
    void carga();
    void atiende();


};


#endif //PREG01_LAB08_2024_2_RESTAURANTE_H
