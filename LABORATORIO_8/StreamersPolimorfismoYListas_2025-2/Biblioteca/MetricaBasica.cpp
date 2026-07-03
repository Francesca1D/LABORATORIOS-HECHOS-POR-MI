//
// Created by USER on 18/06/2026.
//

#include "MetricaBasica.h"

MetricaBasica::MetricaBasica() {
    horas_trasmitidas=0;
    espectadores_promedio=0;
}

MetricaBasica:: ~MetricaBasica() {

}

double MetricaBasica::get_horas_trasmitidas() const {
    return horas_trasmitidas;
}

void MetricaBasica::set_horas_trasmitidas(double horas_trasmitidas) {
    this->horas_trasmitidas = horas_trasmitidas;
}

int MetricaBasica::get_espectadores_promedio() const {
    return espectadores_promedio;
}

void MetricaBasica::set_espectadores_promedio(int espectadores_promedio) {
    this->espectadores_promedio = espectadores_promedio;
}

void MetricaBasica::leer(ifstream &arch) {
    char c;
    Metrica::leer(arch);
    arch>>horas_trasmitidas>>c>>espectadores_promedio; //debo leer el salto de línea?
}

void MetricaBasica::imprimir(ofstream &arch) {
    Metrica::imprimir(arch);
    arch<<setprecision(2)<<fixed<<setw(6)<<horas_trasmitidas<<espectadores_promedio<<"m"<<endl;
}