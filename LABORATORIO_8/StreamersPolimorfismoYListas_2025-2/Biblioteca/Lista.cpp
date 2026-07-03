//
// Created by USER on 18/06/2026.
//

#include "Lista.h"

Lista::Lista() {
    listaDoblementeLigada=nullptr;
}

Lista:: ~Lista() {
    if (listaDoblementeLigada==nullptr) delete listaDoblementeLigada;
}

void Lista::crearLista(ifstream &arch) {
    char tipo[50];


    while (true) {
        Nodo *nuevo;
        nuevo = new Nodo();
        nuevo->carganodo(arch);
        // arch.getline(tipo,50,',');
        if (arch.eof()) break;
        // insertarNodo(nuevo);
    }
}

void Lista::insertarNodo() {

}

void Lista::crearReporte() {

}

void Lista::actualizar() {

}