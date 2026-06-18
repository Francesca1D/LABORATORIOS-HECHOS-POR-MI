//
// Created by USER on 16/06/2026.
//

#ifndef EMERGENCIASPROG2_2026_1_ATENCION_H
#define EMERGENCIASPROG2_2026_1_ATENCION_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

class Atencion {
private:
    int codigo;
    char *paciente;
    char *descripcion;
    int hora;
public:
    Atencion();
    virtual ~Atencion();
    int get_codigo() const;
    void set_codigo(int codigo);
    int get_hora() const;
    void set_hora(int hora);
    void get_paciente(char *cad);
    void set_paciente(const char *cad);
    void get_descripcion(char *cad);
    void set_descripcion(const char *cad);

    virtual void lee(ifstream &arch);
    // void leeAtenciones(ifstream &arch);
    //
};


#endif //EMERGENCIASPROG2_2026_1_ATENCION_H
