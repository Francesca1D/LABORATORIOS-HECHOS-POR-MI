//
// Created by USER on 13/05/2026.
//

#include "Multa.h"

#include <cstring>

Multa::Multa() {
    placa = nullptr;
    fechaDeInfraccion=0;
    fechaDePago=0;
    codigoInfraccion=0;
    multa=0;
}

Multa:: ~Multa() {
    delete placa;
}

Multa::Multa(Multa &orig) {
    placa = nullptr;
    *this = orig;
}

int Multa::get_fecha_de_infraccion() const {
    return fechaDeInfraccion;
}

void Multa::set_fecha_de_infraccion(int fecha_de_infraccion) {
    fechaDeInfraccion = fecha_de_infraccion;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

int Multa::get_codigo_infraccion() const {
    return codigoInfraccion;
}

void Multa::set_codigo_infraccion(int codigo_infraccion) {
    codigoInfraccion = codigo_infraccion;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}

void Multa::get_placa(char *cad) {
    if (this->placa == nullptr) cad[0]=0;
    else
        strcpy(cad, this->placa);
}

void Multa::set_placa(const char *cad) {
    if (this->placa !=nullptr)
        delete this->placa;
    this->placa = new char[strlen(cad)+1];
    strcpy(this->placa, cad);
}

void Multa::operator=(Multa &obj) {
    char cad[20];
    obj.get_placa(cad);
    set_placa(cad);
    fechaDeInfraccion = obj.fechaDeInfraccion;
    fechaDePago = obj.fechaDePago;
    codigoInfraccion = obj.get_codigo_infraccion();
    multa = obj.multa;
}
// 1/12/2020,G760-721,2022
// 23/7/2023,P474-593,2060,P,22/8/2023
// 18/12/2024,G938-342,2061,P,26/1/2025
// 6/8/2021,P863-768,2025
void operator>>(ifstream &arch, Multa &obj) {
    int dd,mm,aa, codigo;
    char c, cad[10];
    arch>>dd;
    if (arch.eof())return;
    arch>>c>>mm>>aa>>c;
    obj.set_fecha_de_infraccion(aa*10000+ mm*100+dd);
    arch.getline(cad,10,',');
    obj.set_placa(cad);
    arch>>codigo;
    obj.set_codigo_infraccion(codigo);
    if (arch.get()=='\n') return;
    arch>>c>>c>>dd>>c>>mm>>c>>aa;
    obj.set_fecha_de_pago(aa*10000+ mm*100+dd);
}
