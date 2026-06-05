//
// Created by USER on 5/06/2026.
//

#ifndef LAB08_PREG02_PRESENCIAL_H
#define LAB08_PREG02_PRESENCIAL_H
#include "Alumno.h"


class Presencial: public Alumno {
public:
    Presencial();

    double get_recargo() const;
    void set_recargo(double recargo);
    double get_total() const;
    void set_total(double total);
    void leePresencial(ifstream &arch);
    void imprimePresencial(ofstream &arch);
    void operator = (Presencial &p);


private:
    double recargo; //porcentaje de recargo sobre boleta
    double total; //monto total de recargo
};


#endif //LAB08_PREG02_PRESENCIAL_H
