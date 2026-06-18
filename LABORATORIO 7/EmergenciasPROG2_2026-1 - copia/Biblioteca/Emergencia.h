//
// Created by USER on 16/06/2026.
//

#ifndef EMERGENCIASPROG2_2026_1_EMERGENCIA_H
#define EMERGENCIASPROG2_2026_1_EMERGENCIA_H
#include "Atencion.h"


class Emergencia:public Atencion {
private:
    bool requiere_rcp;
    int minutos_sin_pulso;

public:
    Emergencia();
    virtual ~Emergencia();
    bool is_requiere_rcp() const;
    void set_requiere_rcp(bool requiere_rcp);
    int get_minutos_sin_pulso() const;
    void set_minutos_sin_pulso(int minutos_sin_pulso);

    void lee(ifstream &arch);

};


#endif //EMERGENCIASPROG2_2026_1_EMERGENCIA_H
