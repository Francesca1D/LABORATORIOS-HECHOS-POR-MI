//
// Created by USER on 13/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Empresa.h"

Empresa::Empresa() {
    dni=0;
    nombre=nullptr;
    numPlacas=0;
    numMultas=0;
    for (int i=0;i<10;i++) {
        placas[i]=nullptr;
    }
}

Empresa::~Empresa() {
    delete nombre;
    for (int i=0;i<10;i++) {
        if (placas[i]!=nullptr)
            delete placas[i];
    }
}

// Empresa::Empresa(Empresa &orig) {
//     nombre = nullptr;
//     *this = orig;
// }

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

int Empresa::get_num_placas() const {
    return numPlacas;
}

void Empresa::set_num_placas(int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_num_multas() const {
    return numMultas;
}

void Empresa::set_num_multas(int num_multas) {
    numMultas = num_multas;
}

void Empresa::get_nombre(char *cad) {
    if (this->nombre == nullptr) cad[0]=0;
    else
        strcpy(cad, this->nombre);
}
void Empresa::set_nombre(const char *cad) {
    if (this->nombre!=nullptr)
        delete this->nombre;
    this->nombre = new char[strlen(cad)+1];
    strcpy(this->nombre, cad);
}

void Empresa::getPlacaI(char *placa, int i) {
    if (placas[i] == nullptr) placa[i]=0;
    else
        strcpy(placa, placas[i]);
}

// void Empresa::getPlacaI(char *placa, int i) {
//     if (this->placas[i] == nullptr) placa[i]=0;
//     else
//         strcpy(placa, this->placas[i]);
// }

void Empresa::setPlacaI(const char *placa, int i) {
    if (placas[i]!=nullptr)
        delete placas[i];
    placas[i] = new char[strlen(placa)+1];
    strcpy(placas[i], placa);
}

// void Empresa::setPlacaI(const char *placa, int i) {
//     if (this->placas[i]!=nullptr)
//         delete this->placas[i];
//     this->placas[i] = new char[strlen(placa)+1];
//     strcpy(this->placas[i], placa);
// }

//Hacer con return ifstream
void operator >>(ifstream &arch, Empresa &obj) {
    int dni;
    char cad[200];
    arch>>dni;
    if (arch.eof())return;
    arch.get();
    obj.set_dni(dni);
    arch.getline(cad,200,',');
    obj.set_nombre(cad);
    obj.leeplacas(arch);

}

void Empresa::leeplacas(ifstream &arch) {
    char cad[10];
    while (true) {
        arch.get(cad,9);
        setPlacaI(cad,numPlacas);
        numPlacas++;
        if (arch.get()=='\n')break;
    }
}

void Empresa::operator += (Multa &obj) {
    multas[numMultas] = obj;
    numMultas++;
}

void operator<<(ofstream &arch, Empresa &obj) {
    char cad[100], placa[10];
    Multa *multa;
    obj.get_nombre(cad);
    arch<<right<<setw(10)<<obj.get_dni()<<' ' <<left<<setw(40)<<cad;
    for (int i=0;i<obj.get_num_placas();i++) {
        obj.getPlacaI(placa,i);
        arch<<placa<<"  ";
        multa= new Multa[obj.get_num_multas()];
        for (int j=0;j<obj.get_num_multas();j++) {

            arch<<multa[j].get_multa()<<endl;
        }
    }
    arch<<endl;
}
char *placa;
int fechaDeInfraccion;
int fechaDePago;
int codigoInfraccion;
double multa;

// int dni;
// char *nombre;
// char *placas[10];
// int numPlacas;
// Multa multas[100];
// int numMultas;

