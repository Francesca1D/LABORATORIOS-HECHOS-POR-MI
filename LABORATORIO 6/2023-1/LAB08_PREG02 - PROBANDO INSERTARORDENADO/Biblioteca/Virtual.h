//
// Created by USER on 5/06/2026.
//

#ifndef LAB08_PREG02_VIRTUAL_H
#define LAB08_PREG02_VIRTUAL_H
#include "Alumno.h"


class Virtual:public Alumno {
private:
    char *licencia;
    double total;

public:
    Virtual();
    virtual ~Virtual();
    double get_total() const;
    void set_total(double total);
    void get_licencia(char *cad);
    void set_licencia(const char *cad);
    void leeVirtual(ifstream &arch);
    void imprimeVirtual(ofstream &arch);
    void operator = (Virtual &v);

};


#endif //LAB08_PREG02_VIRTUAL_H
