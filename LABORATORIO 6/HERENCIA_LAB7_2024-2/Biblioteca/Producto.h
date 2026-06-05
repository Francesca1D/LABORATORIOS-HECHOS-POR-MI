//
// Created by USER on 3/06/2026.
//

#ifndef HERENCIA_LAB7_2024_2_PRODUCTO_H
#define HERENCIA_LAB7_2024_2_PRODUCTO_H
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Producto {
public:
    Producto();
    virtual ~Producto();
    double get_precio() const;
    void set_precio(double precio);
    void get_nombre(char *cad);
    void set_nombre(const char *cad);
    void leeproducto(ifstream &arch);
    void imprimeproducto(ofstream &arch);

private:
    char *nombre;
    double precio;
};


#endif //HERENCIA_LAB7_2024_2_PRODUCTO_H
