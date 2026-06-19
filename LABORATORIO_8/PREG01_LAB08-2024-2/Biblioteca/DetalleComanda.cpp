//
// Created by USER on 18/06/2026.
//

#include "DetalleComanda.h"

#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"


DetalleComanda::DetalleComanda() {
    id=0;
    pedido=nullptr;
}

DetalleComanda:: ~DetalleComanda() {
    if (pedido!=nullptr) delete pedido;
}

int DetalleComanda::get_id() const {
    return id;
}

void DetalleComanda::set_id(int id) {
    this->id = id;
}
// 142,B,Agua Mineral,2.5,pequeno
// 142,E,Quesadillas,5.5,sin picante
// 142,E,Bruschetta,4,picante
// 142,P,Pasta Alfredo,10,4
void DetalleComanda::leecomandas(ifstream &arch) {
    char c,tipo;
    arch>>id;
    if (arch.eof()) return;
    arch>>c>>tipo>>c;
    if (tipo=='B')
        pedido= new Bebida;
    if (tipo=='E')
        pedido= new Entrada;
    if (tipo=='P')
        pedido= new PlatoFondo;
    pedido->lee(arch);
}

void DetalleComanda::imprimecomandas(ofstream &arch) {
    arch<<setw(5)<<" "<<"Codigo de comanda: "<<id<<endl;
    pedido->imprime(arch);
    arch<<endl;
}
