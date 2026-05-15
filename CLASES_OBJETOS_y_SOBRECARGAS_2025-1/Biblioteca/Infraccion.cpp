//
// Created by USER on 13/05/2026.
//
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Infraccion.h"

Infraccion::Infraccion() {
    codigo = 0;
    descripcion = nullptr;
    gravedad = nullptr;
    multa=0;
}

Infraccion::~Infraccion() {
    delete descripcion;
    delete gravedad;
}

Infraccion::Infraccion(Infraccion &orig) {
    descripcion = nullptr;
    gravedad = nullptr;
    *this = orig;
}

void Infraccion::get_descripcion(char *cad) {
    if (this->descripcion == nullptr) cad[0]=0;
    else
        strcpy(cad, this->descripcion);
}
void Infraccion::set_descripcion(const char *cad) {
    if (this->descripcion!= nullptr)
        delete this->descripcion;
    this->descripcion = new char [strlen(cad)+1];
    strcpy(this->descripcion, cad);
}

void Infraccion::get_gravedad(char *cad) {
    if (this->gravedad == nullptr) cad[0] = 0;
    else
        strcpy(cad, this->gravedad);
}
void Infraccion::set_gravedad(const char *cad) {
    if (this->gravedad!= nullptr)
        delete this->gravedad;
    this->gravedad = new char [strlen(cad)+1];
    strcpy(this->gravedad, cad);
}

int Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(int codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

void Infraccion::operator=(Infraccion &obj) {
    char cad[200], grav[20];
    obj.get_descripcion(cad);
    set_descripcion(cad);
    obj.get_gravedad(grav);
    set_gravedad(grav);

    codigo = obj.codigo;
    multa = obj.multa;
}

void operator>>(ifstream &arch, Infraccion &obj) {
    int codigo;
    double multa;
    char cad[20],descripcion[200],c;

    arch>>codigo;
    if (arch.eof()) return;
    arch.get();
    obj.set_codigo(codigo);
    arch>>multa>>c;
    obj.set_multa(multa);
    arch.getline(cad, 20,',');
    obj.set_gravedad(cad);
    arch.getline(descripcion,200,'\n');
    obj.set_descripcion(descripcion);
}


// void operator<<(ofstream &arch, Infraccion &obj) {
//     char cad[10], descripcion[200];
//     obj.get_gravedad(cad);
//     obj.get_descripcion(descripcion);
//     arch<<right<<setw(6)<<obj.get_codigo()<<"  ";
//     arch<<setprecision(2)<<fixed<< setw(10)<<obj.get_multa()<<"      "
//     << left<<setw(10)<<cad<<"   "<<descripcion<<endl;
// }

ofstream &operator<<(ofstream &arch, Infraccion &obj) {
    char cad[10], descripcion[200];
    obj.get_gravedad(cad);
    obj.get_descripcion(descripcion);
    arch<<right<<setw(6)<<obj.get_codigo()<<"  ";
    arch<<setprecision(2)<<fixed<< setw(10)<<obj.get_multa()<<"      "
    << left<<setw(10)<<cad<<"   "<<descripcion<<endl;
    return arch;
}
