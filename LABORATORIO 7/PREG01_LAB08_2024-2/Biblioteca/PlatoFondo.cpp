//
// Created by USER on 11/06/2026.
//

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina=0;
}

PlatoFondo:: ~PlatoFondo() {

}

int PlatoFondo::get_proteina() const {
    return proteina;
}

void PlatoFondo::set_proteina(int proteina) {
    this->proteina = proteina;
}
// 180,P,Ceviche,9,3
// 191,B,Cafe,2,pequeno
void PlatoFondo::lee(ifstream &arch) {
    char cad[50];
    Producto::lee(arch);
    arch>>proteina;
}

void PlatoFondo::imprimir(ofstream &arch) {
    Producto::imprimir(arch);
    if (proteina==1)
        arch<<"Proteina: Pollo"<<endl;
    if (proteina==2)
        arch<<"Proteina: Carne"<<endl;
    if (proteina==3)
        arch<<"Proteina: Pescado"<<endl;
    if (proteina==4)
        arch<<"Proteina: Lacteos"<<endl;
}
