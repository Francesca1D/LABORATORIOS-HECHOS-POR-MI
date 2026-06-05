//
// Created by USER on 5/06/2026.
//

#ifndef LAB08_PREG02_SEMIPRESENCIAL_H
#define LAB08_PREG02_SEMIPRESENCIAL_H
#include "Alumno.h"


class Semipresencial: public Alumno {
public:
    Semipresencial();
    double get_descuento() const;
    void set_descuento(double descuento);
    double get_total() const;
    void set_total(double total);
    void leeSemipresencial(ifstream &arch);
    void imprimeSemipresencial(ofstream &arch);

private:
    double descuento;
    double total;
};


#endif //LAB08_PREG02_SEMIPRESENCIAL_H
