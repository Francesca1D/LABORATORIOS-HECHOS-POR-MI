//
// Created by USER on 11/06/2026.
//

#include "Metrica.h"
#include <cstring>

Metrica::Metrica() {
    id=0;
    descripcion= nullptr;
    fecha_calculo=0;
    fecha_expiracion=0;
    estado= true;
}

Metrica:: ~Metrica() {
    if (descripcion!=nullptr) delete descripcion;

}

int Metrica::get_id() const {
    return id;
}

void Metrica::set_id(int id) {
    this->id = id;
}

int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}

void Metrica::set_fecha_calculo(int fecha_calculo) {
    this->fecha_calculo = fecha_calculo;
}

int Metrica::get_fecha_expiracion() const {
    return fecha_expiracion;
}

void Metrica::set_fecha_expiracion(int fecha_expiracion) {
    this->fecha_expiracion = fecha_expiracion;
}

bool Metrica::is_estado() const {
    return estado;
}

void Metrica::set_estado(bool estado) {
    this->estado = estado;
}

void Metrica::get_descripcion(char *cad) {
    if (descripcion==nullptr) cad[0]='\0';
    else strcpy(cad,descripcion);
}
void Metrica::set_descripcion(const char *cad) {
    if (descripcion!=nullptr) delete descripcion;
    descripcion= new char[strlen(cad)+1];
    strcpy(descripcion,cad);
}
// ENGAGEMENT,573984,161,Q&A largo,2025-08-07,2025-12-31,1586,571,27
// BASIC,263905,44,Sesión Games,2025-11-26,2025-12-31,6.5,1116
// QUALITY,314875,3033,Bitrate consistente,2025-07-27,2025-12-31,7586,0.063,48
// ENGAGEMENT,320975,121,Maratón de chat,2025-10-17,2025-10-31,1535,553,54
void Metrica::leer(ifstream &arch) {
    char c,cad[50];
    int dd,mm,aa;
    arch>>id>>c;
    arch.getline(cad,50,',');
    set_descripcion(cad);
    arch>>aa>>c>>mm>>c>>dd>>c;
    set_fecha_calculo(dd+mm*100+aa*10000);
    arch>>aa>>c>>mm>>c>>dd>>c;
    set_fecha_expiracion(dd+mm*100+aa*10000);
    if (fecha_calculo>fecha_expiracion)
        estado =false;

}

void Metrica::imprimir(ofstream &arch) const {
    int dd,mm,aa;
    arch<<setw(8)<<right<<id<<" "<<left<<setw(30)<<descripcion<<right<<setw(10)<<
        fecha_calculo<<setw(10)<<fecha_expiracion;

    // dd= fecha_calculo

    arch<<setw(10)<<estado;
}
int Metrica::obtenerID() {
    return id;
}