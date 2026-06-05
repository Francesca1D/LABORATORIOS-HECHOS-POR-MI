//
// Created by USER on 13/05/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_MULTA_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_MULTA_H
#include <fstream>

#include "Infraccion.h"

using namespace std;

class Multa {
public:
    Multa();
    virtual ~Multa();
    Multa(Multa &);
    int get_fecha_de_infraccion() const;
    void set_fecha_de_infraccion(int fecha_de_infraccion);
    int get_fecha_de_pago() const;
    void set_fecha_de_pago(int fecha_de_pago);
    int get_codigo_infraccion() const;
    void set_codigo_infraccion(int codigo_infraccion);
    double get_multa() const;
    void set_multa(double multa);
    void get_placa(char *);
    void set_placa(const char *);
    void operator=(Multa &);
private:
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;
};

void operator>>(ifstream &, Multa &);

#endif //CLASES_OBJETOS_Y_SOBRECARGAS_MULTA_H
