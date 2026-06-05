//
// Created by USER on 5/06/2026.
//

#include "Escala.h"

Escala::Escala() {
    codigo=0;
    precio=0;
}
// Escala:: ~Escala() {
//
// }

int Escala::get_codigo() const {
    return codigo;
}

void Escala::set_codigo(int codigo) {
    this->codigo = codigo;
}

double Escala::get_precio() const {
    return precio;
}

void Escala::set_precio(double precio) {
    this->precio = precio;
}
