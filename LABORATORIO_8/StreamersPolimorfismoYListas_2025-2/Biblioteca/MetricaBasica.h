//
// Created by USER on 18/06/2026.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_2025_2_METRICABASICA_H
#define STREAMERSPOLIMORFISMOYLISTAS_2025_2_METRICABASICA_H
#include <iosfwd>

#include "Metrica.h"


class MetricaBasica: public Metrica {
private:
    double horas_trasmitidas;
    int espectadores_promedio;

public:
    MetricaBasica();
    virtual ~MetricaBasica();
    double get_horas_trasmitidas() const;
    void set_horas_trasmitidas(double horas_trasmitidas);
    int get_espectadores_promedio() const;
    void set_espectadores_promedio(int espectadores_promedio);

    void leer(ifstream &);
    void imprimir(ofstream &);

};


#endif //STREAMERSPOLIMORFISMOYLISTAS_2025_2_METRICABASICA_H
