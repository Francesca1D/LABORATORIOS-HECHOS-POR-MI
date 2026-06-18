//
// Created by USER on 16/06/2026.
//

#include "Emergencia.h"

Emergencia::Emergencia() {
    requiere_rcp=false;
    minutos_sin_pulso=0;
}

Emergencia:: ~Emergencia(){

}

bool Emergencia::is_requiere_rcp() const {
    return requiere_rcp;
}

void Emergencia::set_requiere_rcp(bool requiere_rcp) {
    this->requiere_rcp = requiere_rcp;
}

int Emergencia::get_minutos_sin_pulso() const {
    return minutos_sin_pulso;
}

void Emergencia::set_minutos_sin_pulso(int minutos_sin_pulso) {
    this->minutos_sin_pulso = minutos_sin_pulso;
}
// 1,2005,Renato Aguilar,Arritmia Grave,1,5

void Emergencia::lee(ifstream &arch) {
    Atencion::lee(arch);
    char c;
    arch>>requiere_rcp>>c;
    arch>>minutos_sin_pulso;

}

void Emergencia::imprimir(ofstream &arch) {
    Atencion::imprimir(arch);
    if (requiere_rcp==true) {
        arch<<right<<setw(7)<<"SI";
    }else arch<<right<<setw(7)<<"NO";

    arch<<setw(5)<<minutos_sin_pulso;
    arch<<setw(7)<<" "<<" Nivel: CRITICO (0 min)"<<endl;
}

int Emergencia::obtenerPrioridad() {
    return 1;
}