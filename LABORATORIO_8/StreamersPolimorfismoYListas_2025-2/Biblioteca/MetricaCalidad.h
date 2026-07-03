//
// Created by USER on 18/06/2026.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_2025_2_METRICACALIDAD_H
#define STREAMERSPOLIMORFISMOYLISTAS_2025_2_METRICACALIDAD_H
#include "Metrica.h"


class MetricaCalidad: public Metrica {
private:
    int britaje_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;

public:
    MetricaCalidad();
    virtual ~MetricaCalidad();
    int get_britaje_promedio_kbps() const;
    void set_britaje_promedio_kbps(int britaje_promedio_kbps);
    double get_porcentaje_frames_perdidos() const;
    void set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos);
    int get_fps_promedio() const;
    void set_fps_promedio(int fps_promedio);

    void leer(ifstream &);
    void imprimir(ofstream &);

};


#endif //STREAMERSPOLIMORFISMOYLISTAS_2025_2_METRICACALIDAD_H
