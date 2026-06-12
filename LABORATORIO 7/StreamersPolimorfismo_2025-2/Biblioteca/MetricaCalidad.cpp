//
// Created by USER on 11/06/2026.
//

#include "MetricaCalidad.h"

MetricaCalidad::MetricaCalidad() {
    bitraje_promedio_kbps=0;
    porcentaje_frames_perdidos=0;
    fps_promedio=0;
}

MetricaCalidad:: ~MetricaCalidad() {

}


int MetricaCalidad::get_bitraje_promedio_kbps() const {
    return bitraje_promedio_kbps;
}

void MetricaCalidad::set_bitraje_promedio_kbps(int bitraje_promedio_kbps) {
    this->bitraje_promedio_kbps = bitraje_promedio_kbps;
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
// QUALITY,314875,3033,Bitrate consistente,2025-07-27,2025-12-31,7586,0.063,48
void MetricaCalidad::leer(ifstream &arch) {
    char c;
    Metrica::leer(arch);
    arch>>bitraje_promedio_kbps>>c>>porcentaje_frames_perdidos>>c>>fps_promedio;
    arch.get();
}

void MetricaCalidad::imprimir(ofstream &arch) const {
    Metrica::imprimir(arch);
    arch<<setprecision(2)<<fixed<<setw(5)<<bitraje_promedio_kbps<<setw(5)<<porcentaje_frames_perdidos<<
        fps_promedio<<endl;
}

// int MetricaCalidad::obtenerID() {
//     return get_id();
// }
