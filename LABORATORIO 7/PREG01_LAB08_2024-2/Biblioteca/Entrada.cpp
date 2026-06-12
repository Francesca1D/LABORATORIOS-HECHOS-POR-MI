//
// Created by USER on 11/06/2026.
//

#include "Entrada.h"

Entrada::Entrada() {
    picante = false;
}

Entrada:: ~Entrada() {

}

bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}
// 142,E,Quesadillas,5.5,sin picante
// 142,E,Bruschetta,4,picante
void Entrada::lee(ifstream &arch) {
    char cad[50];
    Producto::lee(arch);
    arch.getline(cad,50);

    if (strcmp(cad,"picante")==0) {
        picante = true;
    }
}

void Entrada::imprimir(ofstream &arch) {
    Producto::imprimir(arch);
    if (picante==true)
        arch<<"Picante"<<endl;
    else
        arch<<"Sin picante"<<endl;
}
