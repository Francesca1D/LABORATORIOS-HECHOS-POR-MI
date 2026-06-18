//
// Created by USER on 16/06/2026.
//

#ifndef EMERGENCIASPROG2_2026_1_NOURGENCIA_H
#define EMERGENCIASPROG2_2026_1_NOURGENCIA_H
#include "Atencion.h"


class NoUrgencia :public Atencion {
private:
    char *especialidad;
    bool es_consulta_programada;

public:
    NoUrgencia();
    virtual ~NoUrgencia();
    bool is_es_consulta_programada() const;
    void set_es_consulta_programada(bool es_consulta_programada);
    void get_especialidad(char *cad);
    void set_especialidad(const char *cad);

    void lee(ifstream &arch);

};


#endif //EMERGENCIASPROG2_2026_1_NOURGENCIA_H
