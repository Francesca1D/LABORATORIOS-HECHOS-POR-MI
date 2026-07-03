//
// Created by USER on 18/06/2026.
//

#include "Nodo.h"

Nodo::Nodo() {
    metrica=nullptr;
    anterior=nullptr;
    siguiente=nullptr;
}

Nodo:: ~Nodo() {
    metrica.leeMetricas(arch);
}

void carganodo(ifstream &arch) {

}

