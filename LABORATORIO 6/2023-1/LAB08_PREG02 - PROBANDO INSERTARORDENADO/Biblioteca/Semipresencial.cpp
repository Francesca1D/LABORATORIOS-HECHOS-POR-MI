//
// Created by USER on 5/06/2026.
//

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    descuento=0;
    total=0;
}


double Semipresencial::get_descuento() const {
    return descuento;
}

void Semipresencial::set_descuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::get_total() const {
    return total;
}

void Semipresencial::set_total(double total) {
    this->total = total;
}

    void Semipresencial::leeSemipresencial(ifstream &arch) {
    leeAlumnno(arch);
    arch>>descuento;
}

void Semipresencial::imprimeSemipresencial(ofstream &arch) {
    imprimeAlumnno(arch);
    arch<< descuento << endl;
}
