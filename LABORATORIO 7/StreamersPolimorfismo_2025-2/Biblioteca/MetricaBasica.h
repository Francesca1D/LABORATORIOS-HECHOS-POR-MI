//
// Created by USER on 11/06/2026.
//

#ifndef STREAMERSPOLIMORFISMO_2025_2_METRICABASICA_H
#define STREAMERSPOLIMORFISMO_2025_2_METRICABASICA_H
#include "Metrica.h"


class MetricaBasica: public Metrica {
private:
    double horas_transmitidas;
    int espectadores_promedio;

public:
    MetricaBasica();
    virtual ~MetricaBasica();
    double get_horas_transmitidas() const;
    void set_horas_transmitidas(double horas_transmitidas);
    int get_espectadores_promedio() const;
    void set_espectadores_promedio(int espectadores_promedio);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch) const;
    // int obtenerID();
};


#endif //STREAMERSPOLIMORFISMO_2025_2_METRICABASICA_H
