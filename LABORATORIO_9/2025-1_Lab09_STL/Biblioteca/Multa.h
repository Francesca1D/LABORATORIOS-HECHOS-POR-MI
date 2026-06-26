//
// Created by USER on 24/06/2026.
//

#ifndef INC_2025_1_LAB09_STL_MULTA_H
#define INC_2025_1_LAB09_STL_MULTA_H
#include <string>
#include <fstream>

using namespace std;

class Multa {
private:
    int fecha;
    string placa;
    string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;

public:
    Multa();
    int get_fecha() const;
    void set_fecha(int fecha);
    string get_placa() const;
    void set_placa(const string &placa);
    string get_cod_multa() const;
    void set_cod_multa(const string &cod_multa);
    double get_multa() const;
    void set_multa(double multa);
    bool is_pagada() const;
    void set_pagada(bool pagada);
    int get_fecha_de_pago() const;
    void set_fecha_de_pago(int fecha_de_pago);

    void leeMulta(ifstream &arch, int dd);
    // void imprimirMultas(ofstream &arch);

    bool operator <(Multa &mul) const;
    void operator >>(ifstream &arch);
    void operator<<(ofstream &arch);

};


#endif //INC_2025_1_LAB09_STL_MULTA_H
