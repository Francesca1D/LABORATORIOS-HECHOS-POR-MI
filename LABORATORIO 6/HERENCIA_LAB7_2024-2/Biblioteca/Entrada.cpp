//
// Created by USER on 3/06/2026.
//

#include "Entrada.h"

Entrada::Entrada() {
    picante = false;
}

bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}
//161,E,Quesadillas,5.5,sin picante
//161,E,Ensalada Cesar,6,picante

void Entrada::leeentrada(ifstream &arch) {
    char cad[20];
    leeproducto(arch);
    arch.getline(cad,20);
    if (strcmp(cad,"picante")==0) picante = true;

}

void Entrada::imprimeentradas(ofstream &arch) {
    imprimeproducto(arch);
    if (picante == true)
        arch<<"Si"<<endl;
    else arch<<"No"<<endl;
}

void Entrada::operator = (Entrada &e) {
    char cad[20];
    set_precio(e.get_precio());
    e.get_nombre(cad);
    set_nombre(cad);
}

