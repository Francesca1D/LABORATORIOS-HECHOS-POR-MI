//
// Created by USER on 11/06/2026.
//

#ifndef PREG01_LAB08_2024_2_PLATOFONDO_H
#define PREG01_LAB08_2024_2_PLATOFONDO_H
#include "Producto.h"


class PlatoFondo: public Producto {
private:
    int proteina;
public:
    PlatoFondo();
    virtual ~PlatoFondo();
    int get_proteina() const;
    void set_proteina(int proteina);
    void lee(ifstream &arch);
    void imprimir(ofstream &arch);

};


#endif //PREG01_LAB08_2024_2_PLATOFONDO_H
