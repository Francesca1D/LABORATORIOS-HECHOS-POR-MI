//
// Created by USER on 18/06/2026.
//

#include "Nodo.h"

Nodo::Nodo() {
    sig= nullptr;
}

Nodo:: ~Nodo() {

}

void Nodo::carganodo(ifstream &arch) {
    dato.leecomandas(arch);
}

void Nodo::imprimenodo(ofstream &arch) {
    dato.imprimecomandas(arch);
}