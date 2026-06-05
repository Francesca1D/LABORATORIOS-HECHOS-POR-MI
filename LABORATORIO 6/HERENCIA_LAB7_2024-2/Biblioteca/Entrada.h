//
// Created by USER on 3/06/2026.
//

#ifndef HERENCIA_LAB7_2024_2_ENTRADA_H
#define HERENCIA_LAB7_2024_2_ENTRADA_H
#include "Producto.h"

class Entrada: public Producto {
private:
    bool picante;

public:
    Entrada();
    void operator = (Entrada &e);
    bool is_picante() const;
    void set_picante(bool picante);
    void leeentrada(ifstream &arch);
    void imprimeentradas(ofstream &arch);
};



#endif //HERENCIA_LAB7_2024_2_ENTRADA_H
