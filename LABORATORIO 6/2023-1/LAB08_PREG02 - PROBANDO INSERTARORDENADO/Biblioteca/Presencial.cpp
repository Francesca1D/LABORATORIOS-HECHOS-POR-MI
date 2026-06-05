//
// Created by USER on 5/06/2026.
//

#include "Presencial.h"

Presencial::Presencial() {
    recargo=0;
    total=0;
}

double Presencial::get_recargo() const {
    return recargo;
}

void Presencial::set_recargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::get_total() const {
    return total;
}

void Presencial::set_total(double total) {
    this->total = total;
}
void Presencial::leePresencial(ifstream &arch) {
    leeAlumnno(arch);
    arch>>recargo;
}

void Presencial::imprimePresencial(ofstream &arch) {
    imprimeAlumnno(arch);
    arch<< recargo<< endl;
}

void Presencial:: operator = (Presencial &p) {
    char cad[50];
    p.get_nombre(cad);
    set_nombre(cad);
    set_codigo(p.get_codigo());
    set_escala(p.get_escala());
    set_total(p.get_total());
}

