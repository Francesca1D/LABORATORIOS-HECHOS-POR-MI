//
// Created by USER on 3/06/2026.
//

#include "Bebida.h"

Bebida::Bebida() {
    tamano=nullptr;
}
Bebida:: ~Bebida() {
    if (tamano!=nullptr) delete tamano;
}

void Bebida::get_tamano(char *cad) {
    if (tamano==nullptr) cad[0]='\0';
    else strcpy(cad, tamano);
}
void Bebida::set_tamano(const char *cad) {
    if (tamano!=nullptr) delete tamano;
    tamano=new char[strlen(cad)+1];
    strcpy(tamano,cad);
}
//142,B,Cafe,2,grande
//142,B,Agua Mineral,2.5,pequeno

void Bebida::leebebidas(ifstream &arch) {
    char cad[50];
    leeproducto(arch);
    arch.getline(cad,50);
    set_tamano(cad);
}

void Bebida::imprimebebida(ofstream &arch) {
    imprimeproducto(arch);
    arch<<left<<setw(12)<<tamano<<endl;
}
