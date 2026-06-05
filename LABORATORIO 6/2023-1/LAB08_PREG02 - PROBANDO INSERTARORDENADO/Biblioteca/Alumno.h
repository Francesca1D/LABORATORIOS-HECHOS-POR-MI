//
// Created by USER on 5/06/2026.
//

#ifndef LAB08_PREG02_ALUMNO_H
#define LAB08_PREG02_ALUMNO_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

class Alumno {
public:
    Alumno();
    virtual ~Alumno();
    int get_codigo() const;
    void set_codigo(int codigo);
    int get_escala() const;
    void set_escala(int escala);
    double get_total() const;
    void set_total(double total);
    void get_nombre(char *cad);
    void set_nombre(const char *cad);
    void leeAlumnno(ifstream &arch);
    void imprimeAlumnno(ofstream &arch);


private:
    int codigo;
    char *nombre;
    int escala;
    double total;
};


#endif //LAB08_PREG02_ALUMNO_H
