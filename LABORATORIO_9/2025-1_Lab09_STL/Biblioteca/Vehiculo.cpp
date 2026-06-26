//
// Created by USER on 24/06/2026.
//

#include "Vehiculo.h"

#include <iomanip>

Vehiculo::Vehiculo() {

}


string Vehiculo::get_placa() const {
    return placa;
}

void Vehiculo::set_placa(const string &placa) {
    this->placa = placa;
}

string Vehiculo::get_marca() const {
    return marca;
}

void Vehiculo::set_marca(const string &marca) {
    this->marca = marca;
}

string Vehiculo::get_modelo() const {
    return modelo;
}

void Vehiculo::set_modelo(const string &modelo) {
    this->modelo = modelo;
}
// 12443643,M421-807,Honda,Fit
// 90467829,P985-495,Honda,HR-V
// 80310768,M982-853,Honda,Civic

void Vehiculo::leeVehiculo(ifstream &arch) {
    getline(arch, placa,',');
    if (arch.eof()) return;
    getline(arch, marca,',');
    getline(arch, modelo,'\n');
}

void Vehiculo::operator >>(ifstream &arch) {
    getline(arch, placa,',');
    if (arch.eof()) return;
    getline(arch, marca,',');
    getline(arch, modelo,'\n');
}


// string placa;
// string marca;
// string modelo;

// void Vehiculo::imprimirVehiculo(ofstream &arch) {
//     arch<<left<<setw(15)<<placa<<setw(20)<<marca<<modelo<<endl;
// }

void Vehiculo::operator << (ofstream &arch) {
    arch<<left<<setw(15)<<placa<<setw(20)<<marca<<modelo<<endl;
}


