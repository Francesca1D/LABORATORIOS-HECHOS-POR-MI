//
// Created by USER on 11/06/2026.
//

#include "MetricaBasica.h"

MetricaBasica::MetricaBasica() {
    horas_transmitidas=0;
    espectadores_promedio=0;
}

MetricaBasica:: ~MetricaBasica() {

}

double MetricaBasica::get_horas_transmitidas() const {
    return horas_transmitidas;
}

void MetricaBasica::set_horas_transmitidas(double horas_transmitidas) {
    this->horas_transmitidas = horas_transmitidas;
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
    arch>>horas_transmitidas>>c>>espectadores_promedio;
    arch.get();
}
// BASIC,263905,44,Sesión Games,2025-11-26,2025-12-31,6.5,1116
void MetricaBasica::imprimir(ofstream &arch) const {
    Metrica::imprimir(arch);
    arch<<setprecision(2)<<fixed<<setw(5)<<horas_transmitidas<<setw(5)<<espectadores_promedio<<endl;
}
// int MetricaBasica::obtenerID() {
//     // return get_id();
// }