//
// Created by USER on 11/06/2026.
//

#ifndef STREAMERSPOLIMORFISMO_2025_2_METRICACALIDAD_H
#define STREAMERSPOLIMORFISMO_2025_2_METRICACALIDAD_H
#include "Metrica.h"


class MetricaCalidad:public Metrica {
private:
    int bitraje_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;

public:
    MetricaCalidad();
    virtual ~MetricaCalidad();
    int get_bitraje_promedio_kbps() const;
    void set_bitraje_promedio_kbps(int bitraje_promedio_kbps);
    double get_porcentaje_frames_perdidos() const;
    void set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos);
    int get_fps_promedio() const;
    void set_fps_promedio(int fps_promedio);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch) const;
    // int obtenerID();

};


#endif //STREAMERSPOLIMORFISMO_2025_2_METRICACALIDAD_H
