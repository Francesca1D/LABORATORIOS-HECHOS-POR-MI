//
// Created by USER on 25/06/2026.
//

#include "Etiqueta.h"

Etiqueta::Etiqueta() {

}

Etiqueta::~Etiqueta() {

}

Etiqueta::Etiqueta(const Etiqueta &orig) {
    *this = orig;
}


string Etiqueta::get_codigo() const {
    return codigo;
}

void Etiqueta::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Etiqueta::get_nombre() const {
    return nombre;
}

void Etiqueta::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

void Etiqueta::operator = (const Etiqueta &orig) {
    codigo = orig.codigo;
    nombre= orig.nombre;
}
// AAM100,dropsenabled
// BKY101,chill
// DOL102,vtuber
// NOV103,gaming
void Etiqueta::operator >>(ifstream &arch) {
    getline(arch, codigo,',');
    if (arch.eof())return;
    getline(arch, nombre,'\n');

}

void Etiqueta::operator <<(ofstream &arch) {
    arch<<codigo<<" "<<nombre<<endl;
}

