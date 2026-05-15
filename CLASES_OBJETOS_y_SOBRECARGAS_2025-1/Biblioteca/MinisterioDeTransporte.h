//
// Created by USER on 13/05/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_MINISTERIODETRANSPORTE_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_MINISTERIODETRANSPORTE_H
#include "Infraccion.h"
#include "Empresa.h"
#include <fstream>

using namespace std;

class MinisterioDeTransporte {
public:
    MinisterioDeTransporte();
    virtual ~MinisterioDeTransporte();
    int get_num_inf() const;
    void set_num_inf(int num_inf);
    int get_num_emp() const;
    void set_num_emp(int num_emp);
    void operator<(const char *);
    void operator<=(const char *);
    void operator <<= (const char *);
    int buscarInfraccion(int codigo,Infraccion *infracciones);
    // int buscarEmpresas(char *placa, Empresa *empresas);
    void operator >>(const char *nombArch);

private:
        Infraccion *infracciones;
        int numInf;
        Empresa empresas[50];
        int numEmp;
};


#endif //CLASES_OBJETOS_Y_SOBRECARGAS_MINISTERIODETRANSPORTE_H
