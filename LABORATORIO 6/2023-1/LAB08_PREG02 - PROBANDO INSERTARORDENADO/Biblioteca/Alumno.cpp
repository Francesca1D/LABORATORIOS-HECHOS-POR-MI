//
// Created by USER on 5/06/2026.
//

#include "Alumno.h"

#include <cstring>

Alumno::Alumno() {
    codigo=0;
    nombre=nullptr;
    escala=0;
    total=0;
}

Alumno:: ~Alumno() {
    if (nombre != nullptr) delete nombre;
}

int Alumno::get_codigo() const {
    return codigo;
}

void Alumno::set_codigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::get_escala() const {
    return escala;
}

void Alumno::set_escala(int escala) {
    this->escala = escala;
}

double Alumno::get_total() const {
    return total;
}

void Alumno::set_total(double total) {
    this->total = total;
}

void Alumno::get_nombre(char *cad) {
    if (nombre == nullptr) cad[0]='\0';
    else strcpy(cad,nombre);
}

void Alumno::set_nombre(const char *cad) {
    if (nombre != nullptr) delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Alumno::leeAlumnno(ifstream &arch) {
    char c,cad[50];
    arch>>codigo>>c;
    arch.getline(cad,50,',');
    set_nombre(cad);
    arch>>escala>>c;
}

void Alumno::imprimeAlumnno(ofstream &arch) {
    
    arch<<codigo<<"  "<<left<<setw(40)<<nombre<<"   "<<right<<escala<<"  "<<total<<" ";
}



