//
// Created by USER on 18/06/2026.
//

#include "Metrica.h"
#include <cstring>

Metrica::Metrica() {
    id=0;
    descripcion=nullptr;
    fecha_calculo=0;
    fecha_expiracion=0;
    estado=false;
}

Metrica:: ~Metrica(){
    if (descripcion!=nullptr) delete descripcion;

}

void Metrica::get_descripcion(char *cad){
    if (descripcion==nullptr) cad[0]='\0';
    else strcpy(cad,descripcion);
}

void Metrica::set_descripcion(const char *cad){
    if (descripcion!=nullptr) delete descripcion;
    descripcion = new char[strlen(cad)+1];
    strcpy (descripcion,cad);
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

void Metrica::leer(ifstream &arch) {
    int dd,mm,aa;
    char c,cad[100];
    arch>>id>>c;
    arch.getline(cad,100,',');
    set_descripcion(cad);
    arch>>aa>>c>>mm>>c>>dd>>c;
    set_fecha_calculo(dd+mm*100+aa*10000);
    arch>>aa>>c>>mm>>c>>dd>>c;
    set_fecha_expiracion(dd+mm*100+aa*10000);
    if (fecha_calculo>fecha_expiracion)
        estado=false;
    else estado=true;

}
// ENGAGEMENT,573984,161,Q&A largo,2025-08-07,2025-12-31,1586,571,27
// BASIC,263905,44,Sesión Games,2025-11-26,2025-12-31,6.5,1116
// QUALITY,314875,3033,Bitrate consistente,2025-07-27,2025-12-31,7586,0.063,48

void Metrica::imprimir(ofstream &arch) {
    arch<<setw(4)<<right<<setfill('0')<<id<<setfill(' ');
    arch<<setw(20)<<fecha_calculo;
    arch<<setw(20)<<fecha_expiracion;
    if (estado)
        arch<<setw(20)<<"ACTIVA";
    else arch<<setw(20)<<"EXPIRADA";

}


