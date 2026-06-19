//
// Created by USER on 18/06/2026.
//

#ifndef PREG01_LAB08_2024_2_RESTAURANTE_H
#define PREG01_LAB08_2024_2_RESTAURANTE_H
#include "Cola.h"


class Restaurante {
private:
    Cola Ccomanda;
public:
    Restaurante();
    virtual ~Restaurante();

    void carga();
    // void elimina(int num);
    void atiende();

};


#endif //PREG01_LAB08_2024_2_RESTAURANTE_H
