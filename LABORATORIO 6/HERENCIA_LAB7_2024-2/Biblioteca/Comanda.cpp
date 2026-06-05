//
// Created by USER on 3/06/2026.
//

#include "Comanda.h"

Comanda::Comanda() {
    id=0;
    entradas=nullptr;          //dinamico
    cantidad_bebidas=0;
    //int cantidad_entradas;
    cantidad_platos_fondo=0;
    hora_atencion=0;
    hora_servicio=0;
    tiempo_preparacion=0;
    total=0;
    //char *estado;
}
Comanda:: ~Comanda() {
    if (entradas!=nullptr)
        delete [] entradas;
}

int Comanda::get_id() const {
    return id;
}

void Comanda::set_id(int id) {
    this->id = id;
}

int Comanda::get_cantidad_bebidas() const {
    return cantidad_bebidas;
}

void Comanda::set_cantidad_bebidas(int cantidad_bebidas) {
    this->cantidad_bebidas = cantidad_bebidas;
}

int Comanda::get_cantidad_platos_fondo() const {
    return cantidad_platos_fondo;
}

void Comanda::set_cantidad_platos_fondo(int cantidad_platos_fondo) {
    this->cantidad_platos_fondo = cantidad_platos_fondo;
}

int Comanda::get_hora_atencion() const {
    return hora_atencion;
}

void Comanda::set_hora_atencion(int hora_atencion) {
    this->hora_atencion = hora_atencion;
}

int Comanda::get_hora_servicio() const {
    return hora_servicio;
}

void Comanda::set_hora_servicio(int hora_servicio) {
    this->hora_servicio = hora_servicio;
}

int Comanda::get_tiempo_preparacion() const {
    return tiempo_preparacion;
}

void Comanda::set_tiempo_preparacion(int tiempo_preparacion) {
    this->tiempo_preparacion = tiempo_preparacion;
}

double Comanda::get_total() const {
    return total;
}

void Comanda::set_total(double total) {
    this->total = total;
}

void Comanda::leecomanda(char tipo,ifstream &arch) {
    if (tipo == 'B') {
        bebidas[cantidad_bebidas].leebebidas(arch);
        cantidad_bebidas++;
    }
    if (tipo == 'P') {
        platos_fondo[cantidad_platos_fondo].leeplatos(arch);
        cantidad_platos_fondo++;
    }
    if (tipo == 'E') {
        if (entradas==nullptr) {
            entradas = new Entrada[20];
        }
        int i;
        for (i=0; entradas[i].get_precio()!=0;i++);
            entradas[i].leeentrada(arch);

    }
}

void Comanda::imprimecomandas(ofstream &arch) {
    if (cantidad_bebidas!=0) {
        arch<<left<<setw(40)<<"BEBIDAS: "<<endl;
        arch<<setw(70)<<setfill('_')<<'_'<<setfill(' ')<<endl;
        arch<<setw(24)<<"Nombre"<<"Precio  "<<"Tamano"<<endl;
    }
    for (int i = 0; i < cantidad_bebidas; i++) {
        bebidas[i].imprimebebida(arch);
    }
    //arch<<setw(70)<<setfill('_')<<'_'<<setfill(' ')<<endl;
    if (cantidad_platos_fondo!=0) {
        arch<<endl;
        arch<<"PLATOS FONDO: "<<endl;
        arch<<setw(70)<<setfill('_')<<'_'<<setfill(' ')<<endl;
        arch<<setw(24)<<left<<"Nombre"<<"Precio  "<<"Proteina"<<endl;
    }
    for (int i = 0; i < cantidad_platos_fondo; i++) {
        platos_fondo[i].imprimeplatos_fondo(arch);
    }
    //arch<<setw(70)<<setfill('_')<<'_'<<setfill(' ')<<endl;

    if (entradas!=nullptr) {
        arch<<endl;
        arch<<"ENTRADAS: "<<endl;
        arch<<setw(70)<<setfill('_')<<'_'<<setfill(' ')<<endl;
        arch<<setw(24)<<left<<"Nombre"<<"Precio  "<<"Picante"<<endl;
    }
    for (int i = 0; i<cuentaEntradas(); i++) {
        entradas[i].imprimeentradas(arch);
    }
    arch<<endl;
    //arch<<setw(70)<<setfill('_')<<'_'<<setfill(' ')<<endl;
}

bool Comanda::isnull() {
    if (entradas==nullptr) return true;
    else return false;
}
int Comanda::cuentaEntradas() {
    if (entradas!=nullptr) {
        int i;
        for (i=0; entradas[i].get_precio()!=0;i++);
        return i;
    }
    return 0;
}

void Comanda::recortarEntradas() {
    int n= cuentaEntradas();
    Entrada *aux = new Entrada[n+1];
    for (int i = 0; i<n; i++) {
        aux[i] = entradas[i];
    }
    delete [] entradas;
    entradas = aux;

}

