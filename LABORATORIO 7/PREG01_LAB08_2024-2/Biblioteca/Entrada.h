//
// Created by USER on 11/06/2026.
//

#ifndef PREG01_LAB08_2024_2_ENTRADA_H
#define PREG01_LAB08_2024_2_ENTRADA_H
#include "Producto.h"


class Entrada: public Producto{
private:
    bool picante;

public:
    Entrada();
    virtual ~Entrada();
    bool is_picante() const;
    void set_picante(bool picante);
    void lee(ifstream &arch);
    void imprimir(ofstream &arch);

};


#endif //PREG01_LAB08_2024_2_ENTRADA_H
