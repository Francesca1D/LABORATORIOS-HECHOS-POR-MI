//
// Created by USER on 18/06/2026.
//

#include "Entrada.h"

Entrada::Entrada() {
    picante=false;
}

Entrada:: ~Entrada() {

}

bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}


void Entrada::lee(ifstream &arch) {
    char cad[50];
    Producto::lee(arch);
    arch.getline(cad,50,'\n');
    if (strcmp(cad,"picante")==0)
        picante=true;
}

void Entrada::imprime(ofstream &arch) {
    Producto::imprime(arch);

    if (picante) {
        arch<<setw(5)<<" "<<"Picante"<<endl;
    }
    else  arch<<setw(5)<<" "<<"Sin Picante"<<endl;

}