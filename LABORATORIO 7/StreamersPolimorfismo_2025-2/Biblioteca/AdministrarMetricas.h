//
// Created by USER on 11/06/2026.
//

#ifndef STREAMERSPOLIMORFISMO_2025_2_ADMINISTRARMETRICAS_H
#define STREAMERSPOLIMORFISMO_2025_2_ADMINISTRARMETRICAS_H
#include "GestorStreamer.h"


class AdministrarMetricas {
    private:
    GestorStreamer streamer[210];
    int cantidadStreamer;

public:
    int get_cantidad_streamer() const;

    void set_cantidad_streamer(int cantidad_streamer);

    AdministrarMetricas();
    virtual ~AdministrarMetricas();
    void carga(const char *nombArch);
    void generarReporte(const char *nombArch);
    void imprimirStreamer(ofstream &arch);
};


#endif //STREAMERSPOLIMORFISMO_2025_2_ADMINISTRARMETRICAS_H
