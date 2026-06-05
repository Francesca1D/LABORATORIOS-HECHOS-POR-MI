//
// Created by USER on 13/05/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_EMPRESA_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_EMPRESA_H
#include "Multa.h"
#include <fstream>

using namespace std;

class Empresa {
public:
    Empresa();
    virtual ~Empresa();
    // Empresa(Empresa &);
    int get_dni() const;
    void set_dni(int dni);
    int get_num_placas() const;
    void set_num_placas(int num_placas);
    int get_num_multas() const;
    void set_num_multas(int num_multas);
    void get_nombre(char *cad);
    void set_nombre(const char *cad);
    void leeplacas(ifstream &arch);
    void operator += (Multa &);
    void getPlacaI(char *, int);
    void setPlacaI(const char *, int i);
private:
    int dni;
    char *nombre;
    char *placas[10];
    int numPlacas;
    Multa multas[100];
    int numMultas;

};
void operator >>(ifstream &, Empresa &);
void operator <<(ofstream &, Empresa &);

#endif //CLASES_OBJETOS_Y_SOBRECARGAS_EMPRESA_H
