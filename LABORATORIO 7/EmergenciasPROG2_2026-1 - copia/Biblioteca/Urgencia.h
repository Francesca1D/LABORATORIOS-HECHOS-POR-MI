//
// Created by USER on 16/06/2026.
//

#ifndef EMERGENCIASPROG2_2026_1_URGENCIA_H
#define EMERGENCIASPROG2_2026_1_URGENCIA_H
#include "Atencion.h"


class Urgencia:public Atencion {
private:
    char *zona_lesion;
    bool necesita_rx;

public:
    Urgencia();
    virtual ~Urgencia();
    bool is_necesita_rx() const;
    void set_necesita_rx(bool necesita_rx);
    void get_zona_lesion(char *cad);
    void set_zona_lesion(const char *cad);

    void lee(ifstream &arch);

};


#endif //EMERGENCIASPROG2_2026_1_URGENCIA_H
