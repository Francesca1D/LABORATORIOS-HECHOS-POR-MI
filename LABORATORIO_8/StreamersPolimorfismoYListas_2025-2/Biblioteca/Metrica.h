//
// Created by USER on 18/06/2026.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_2025_2_METRICA_H
#define STREAMERSPOLIMORFISMOYLISTAS_2025_2_METRICA_H
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


class Metrica {
private:
    int id;
    char *descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;

public:
    Metrica();
    virtual ~Metrica();
    void get_descripcion(char *cad);
    void set_descripcion(const char *cad);
    int get_id() const;
    void set_id(int id);
    int get_fecha_calculo() const;
    void set_fecha_calculo(int fecha_calculo);
    int get_fecha_expiracion() const;
    void set_fecha_expiracion(int fecha_expiracion);
    bool is_estado() const;
    void set_estado(bool estado);

    virtual void leer(ifstream &);
    virtual void imprimir(ofstream &);

};


#endif //STREAMERSPOLIMORFISMOYLISTAS_2025_2_METRICA_H
