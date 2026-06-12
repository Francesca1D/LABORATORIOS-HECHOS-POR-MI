//
// Created by USER on 11/06/2026.
//

#include "Bebida.h"


Bebida::Bebida() {
    tamano= nullptr;

}

Bebida:: ~Bebida() {
    if (tamano != nullptr) delete tamano;
}

void Bebida::get_tamano(char * cad) {
    if (tamano == nullptr) cad[0]='\0';
    else strcpy(cad,tamano);
}

void Bebida::set_tamano(const char * cad) {
    if (tamano != nullptr) delete tamano;
    tamano = new char[strlen(cad)+1];
    strcpy(tamano,cad);
}
// 142,B,Cafe,2,grande
void Bebida::lee(ifstream &arch) {
    char cad[50];
    Producto::lee(arch);
    arch.getline(cad,50);
    set_tamano(cad);
}

void Bebida::imprimir(ofstream &arch) {
    char cad[50];
    //get_tamano(cad);
    Producto::imprimir(arch);
    arch<<"Tamano: "<<tamano<<endl;
}

