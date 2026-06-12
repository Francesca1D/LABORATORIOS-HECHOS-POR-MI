//
// Created by USER on 11/06/2026.
//

#ifndef STREAMERSPOLIMORFISMO_2025_2_METRICA_H
#define STREAMERSPOLIMORFISMO_2025_2_METRICA_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

class Metrica {
public:
    Metrica();
    virtual ~Metrica();
    int get_id() const;
    void set_id(int id);
    int get_fecha_calculo() const;
    void set_fecha_calculo(int fecha_calculo);
    int get_fecha_expiracion() const;
    void set_fecha_expiracion(int fecha_expiracion);
    bool is_estado() const;
    void set_estado(bool estado);
    void get_descripcion(char *cad);
    void set_descripcion(const char *cad);
    virtual void leer(ifstream &arch);
    virtual void imprimir(ofstream &arch) const;
    int obtenerID();

private:
    int id;
    char *descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;



};


#endif //STREAMERSPOLIMORFISMO_2025_2_METRICA_H
