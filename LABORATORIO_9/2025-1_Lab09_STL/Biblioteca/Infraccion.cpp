//
// Created by USER on 24/06/2026.
//

#include "Infraccion.h"

Infraccion::Infraccion() {
    multa=0;
}

string Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

string Infraccion::get_gravedad() const {
    return gravedad;
}

void Infraccion::set_gravedad(const string &gravedad) {
    this->gravedad = gravedad;
}

string Infraccion::get_descripcion() const {
    return descripcion;
}

void Infraccion::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}
// G2007,425.23,GRAVE,No conducir por el carril de extremo derecho de la calzada un vehiculo de transporte p�blico de pasajeros o de carga.
// M1029,586.45,MUY GRAVE,Conducir un vehiculo especial que no se ajuste a las exigencias reglamentarias sin la autorizacion correspondiente.
// M1018,606.11,MUY GRAVE,Desobedecer las indicaciones sobre el transito que ordene el efectivo de la Policia Nacional del Per� asignado al control del transito.

// string codigo;
// double multa;
// string gravedad;
// string descripcion;

void Infraccion::leeInfraccion(ifstream &arch) {
    getline(arch,codigo,',');
    if (arch.eof()) return;
    arch>>multa;
    arch.get();
    getline(arch,gravedad,',');
    getline(arch,descripcion,'\n');  //o getline(arch,descripcion)?;
}
// ifstream & operator >>(ifstream &arch, Infraccion &inf);
// void Infraccion::operator >>(ifstream &arch) {
//     getline(arch,inf.codigo,',');
//     if (arch.eof()) return;
//     arch>>inf.multa;
//     arch.get();
//     getline(arch,inf.gravedad,',');
//     getline(arch,inf.descripcion,'\n');  //o getline(arch,descripcion)?;
//     // return arch;
// }

void Infraccion::operator >>(ifstream &arch) {
    getline(arch,codigo,',');
    if (arch.eof()) return;
    arch>>multa;
    arch.get();
    getline(arch,gravedad,',');
    getline(arch,descripcion,'\n');  //o getline(arch,descripcion)?;
    // return arch;
}

bool Infraccion::operator <(Infraccion &inf) const{
    return codigo<inf.codigo;
}
