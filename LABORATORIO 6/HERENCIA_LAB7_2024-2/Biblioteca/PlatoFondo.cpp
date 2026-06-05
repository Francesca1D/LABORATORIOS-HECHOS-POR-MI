//
// Created by USER on 3/06/2026.
//

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina = nullptr;
}
PlatoFondo:: ~PlatoFondo() {  //    VERIFICAR
    if (proteina != nullptr)
        delete []proteina;
}

int * PlatoFondo::get_proteina() const {
    return proteina;
}

void PlatoFondo::set_proteina(int *proteina) {
    this->proteina = proteina;
}
//142,P,Pasta Alfredo,10,0,1,0,1
//142,P,Pollo a la Brasa,15,1,1,1,1

void PlatoFondo::leeplatos(ifstream &arch) {
    int c1,c2,c3,c4;
    char c;
    leeproducto(arch);
    arch>>c1>>c>>c2>>c>>c3>>c>>c4;
    proteina = new int[4];
    proteina[0] = c1;
    proteina[1] = c2;
    proteina[2] = c3;
    proteina[3] = c4;
}
void PlatoFondo::imprimeplatos_fondo(ofstream &arch) {
    imprimeproducto(arch);
    if (proteina[0] == 1)
        arch<<"Pollo ";
    if (proteina[1] == 1)
        arch<<"Carne ";
    if (proteina[2] == 1)
        arch<<"Pescado ";
    if (proteina[3] == 1)
        arch<<"Lacteos ";
    if (proteina[0]==0 and proteina[1]==0 and proteina[2]==0 and proteina[3]==0)
        arch<<"Sin proteina";
    arch<<endl;
}
