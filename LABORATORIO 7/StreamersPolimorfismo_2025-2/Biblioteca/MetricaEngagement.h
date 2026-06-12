//
// Created by USER on 11/06/2026.
//

#ifndef STREAMERSPOLIMORFISMO_2025_2_METRICAENGAGEMENT_H
#define STREAMERSPOLIMORFISMO_2025_2_METRICAENGAGEMENT_H

#include "Metrica.h"


class MetricaEngagement: public Metrica{
public:
    MetricaEngagement();
    virtual ~MetricaEngagement();
    int get_mensajes_chat() const;
    void set_mensajes_chat(int mensajes_chat);
    int get_usuarios_unicos_chat() const;
    void set_usuarios_unicos_chat(int usuarios_unicos_chat);
    int get_clips_generados() const;
    void set_clips_generados(int clips_generados);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch) const;
    int obtenerID();


private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;

};


#endif //STREAMERSPOLIMORFISMO_2025_2_METRICAENGAGEMENT_H
