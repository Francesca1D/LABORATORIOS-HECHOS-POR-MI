//
// Created by USER on 5/06/2026.
//

#include "Virtual.h"

Virtual::Virtual() {
    licencia=nullptr;
    total=100;
}

Virtual:: ~Virtual() {
    if(licencia!=nullptr) delete licencia;
}

double Virtual::get_total() const {
    return total;
}

void Virtual::set_total(double total) {
    this->total = total;
}

void Virtual::get_licencia(char *cad) {
    if(licencia==nullptr) cad[0]='\0';
    else strcpy(cad,licencia);
}

void Virtual::set_licencia(const char *cad) {
    if(licencia!=nullptr) delete licencia;
    licencia = new char[strlen(cad)+1];
    strcpy(licencia,cad);
}

void Virtual::leeVirtual(ifstream &arch) {
    char cad[20];
    leeAlumnno(arch);
    arch.getline(cad,20,'\n');
    set_licencia(cad);
}

// int Virtual::contarVirtual() {
//     if (licencia==nullptr) return 0;
// }


void Virtual::imprimeVirtual(ofstream &arch) {
    imprimeAlumnno(arch);
    arch<< licencia << endl;
}

void Virtual::operator = (Virtual &v) {
    char cad[50];
    v.get_nombre(cad);
    set_nombre(cad);
    set_codigo(v.get_codigo());
    set_escala(v.get_escala());
    set_total(v.get_total());
}
