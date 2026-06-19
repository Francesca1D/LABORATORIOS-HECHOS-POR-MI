//
// Created by USER on 18/06/2026.
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

void PlatoFondo::lee(ifstream &arch) {
    Producto::lee(arch);
    arch>>proteina;
}

void PlatoFondo::imprime(ofstream &arch) {
    Producto::imprime(arch);
    if (proteina==1)
        arch<<setw(5)<<" "<<"Proteina: Pollo"<<endl;
    if (proteina==2)
        arch<<setw(5)<<" "<<"Proteina: Carne"<<endl;
    if (proteina==3)
        arch<<setw(5)<<" "<<"Proteina: Pescado"<<endl;
    if (proteina==4)
        arch<<setw(5)<<" "<<"Proteina: Lacteos"<<endl;

}