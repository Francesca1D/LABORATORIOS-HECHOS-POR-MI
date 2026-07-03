//
// Created by USER on 18/06/2026.
//

#include "MetricaCalidad.h"

MetricaCalidad::MetricaCalidad() {
    britaje_promedio_kbps=0;
    porcentaje_frames_perdidos=0;
    fps_promedio=0;
}

MetricaCalidad:: ~MetricaCalidad() {

}

int MetricaCalidad::get_britaje_promedio_kbps() const {
    return britaje_promedio_kbps;
}

void MetricaCalidad::set_britaje_promedio_kbps(int britaje_promedio_kbps) {
    this->britaje_promedio_kbps = britaje_promedio_kbps;
}

double MetricaCalidad::get_porcentaje_frames_perdidos() const {
    return porcentaje_frames_perdidos;
}

void MetricaCalidad::set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos) {
    this->porcentaje_frames_perdidos = porcentaje_frames_perdidos;
}

int MetricaCalidad::get_fps_promedio() const {
    return fps_promedio;
}

void MetricaCalidad::set_fps_promedio(int fps_promedio) {
    this->fps_promedio = fps_promedio;
}

void MetricaCalidad::leer(ifstream &arch) {
    char c;
    Metrica::leer(arch);
    arch>>britaje_promedio_kbps>>c>>porcentaje_frames_perdidos>>c>>fps_promedio; //debo leer el salto de línea?
}

void MetricaCalidad::imprimir(ofstream &arch) {
    Metrica::imprimir(arch);
    arch<<setw(6)<<britaje_promedio_kbps<<setw(6)<<setprecision(2)<<fixed<<porcentaje_frames_perdidos<<fps_promedio<<endl;
}
