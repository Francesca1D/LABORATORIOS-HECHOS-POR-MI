//
// Created by USER on 11/06/2026.
//

#ifndef PREG01_LAB08_2024_2_PRODUCTO_H
#define PREG01_LAB08_2024_2_PRODUCTO_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Producto {
public:
    Producto();
    virtual ~Producto();
    double get_precio() const;
    void set_precio(double precio);
    void get_nombre(char * cad);
    void set_nombre(const char * cad);
    virtual void lee(ifstream &arch);
    virtual void imprimir(ofstream &arch);
private:
    char* nombre;
    double precio;
};


#endif //PREG01_LAB08_2024_2_PRODUCTO_H
