//
// Created by USER on 18/06/2026.
//

#include "Bebida.h"

Bebida::Bebida() {
    tamano=nullptr;
}

Bebida:: ~Bebida(){
    if (tamano!=nullptr) delete tamano;

}

void Bebida::get_tamano(char *cad){
    if (tamano==nullptr) cad[0] = '\0';
    else strcpy(cad, tamano);
}

void Bebida::set_tamano(const char *cad){
    if (tamano!=nullptr) delete tamano;
    tamano = new char[strlen(cad)+1];
    strcpy(tamano,cad);
}

void Bebida::lee(ifstream &arch) {
    char cad[100], c;
    Producto::lee(arch);
    arch.getline(cad, 100,'\n');
    set_tamano(cad);
}

void Bebida::imprime(ofstream &arch) {
    Producto::imprime(arch);

    arch<<setw(5)<<" "<<"Tamano: "<<tamano<<endl;

}
