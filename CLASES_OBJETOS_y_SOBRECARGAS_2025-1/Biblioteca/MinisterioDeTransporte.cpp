//
// Created by USER on 13/05/2026.
//

#include "MinisterioDeTransporte.h"

#include <iomanip>
#include <iostream>
#include <cstring>

MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones=nullptr;
    numInf=0;
    numEmp=0;
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
    if (infracciones!=nullptr)
        delete []infracciones;
}

int MinisterioDeTransporte::get_num_inf() const {
    return numInf;
}

void MinisterioDeTransporte::set_num_inf(int num_inf) {
    numInf = num_inf;
}

int MinisterioDeTransporte::get_num_emp() const {
    return numEmp;
}

void MinisterioDeTransporte::set_num_emp(int num_emp) {
    numEmp = num_emp;
}

void MinisterioDeTransporte::operator<(const char *nombArch) {
    Infraccion buffer[200];
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        arch>>buffer[i];
        if (arch.eof()) break;
        i++;
    }
    infracciones=new Infraccion[i+1];

    for (int j=0; j<i; j++) {
        infracciones[j]=buffer[j];
    }
    numInf=i;
}

void MinisterioDeTransporte::operator<=(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        arch>>empresas[i];
        if (arch.eof()) break;
        i++;
    }
    numEmp=i;
}

void MinisterioDeTransporte::operator <<= (const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    // Infraccion aux;
    // Empresa auxEmp;
    Multa aux;
    int i=0,posInfra, posEmp;
    while (true) {
        arch>>aux;
        if (arch.eof()) break;

            posInfra = buscarInfraccion(aux.get_codigo_infraccion(),infracciones);
            // posEmp = buscarEmpresas(aux.get_placa(), empresas);
        i++;
    }

}

int MinisterioDeTransporte::buscarInfraccion(int codigo,Infraccion *infracciones) {
    for (int i=0; i<numInf; i++) {
        if (codigo==infracciones[i].get_codigo()) return i;
    }
    return -1;
}

// int MinisterioDeTransporte::buscarEmpresas(char *placa, Empresa *empresas) {
//     char *placa[10];
//     for (int i=0; i<numEmp; i++) {
//         if (strcmp(placa, empresas[i].getPlacaI(placa[i],i))==0) {
//             return i;
//         }
//     }
//     return -1;
// }

void MinisterioDeTransporte::operator >>(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<left<<setw(30)<<' '<<"MINISTERIO DE TRANSPORTE"<<endl;
    arch<<setw(100)<<setfill('-')<<'-'<<setfill(' ')<<endl;
    arch<<setw(30)<<' '<<"TABLA DE INFRACCIONES"<<endl<<endl;
    arch<<setw(10)<<"  CODIGO  "<<setw(10)<<"MULTA  "<<setw(15)<<"GRAVEDAD"<<"DESCRIPCION"<<endl;
    arch<<setw(100)<<setfill('-')<<' '<<setfill(' ')<<endl;
   for (int i=0; i<numInf; i++) {
       arch<<infracciones[i];
   }
    arch<<setw(100)<<setfill('-')<<' '<<setfill(' ')<<endl;
    arch<<left<<setw(30)<<' '<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    arch<<setw(100)<<setfill('-')<<'-'<<setfill(' ')<<endl;
    arch<<setw(10)<<"  DNI  "<<setw(60)<<"NOMBRE  "<<setw(15)<<"PLACAS DE SUS VEHICULOS"<<endl;
    arch<<setw(100)<<setfill('-')<<'-'<<setfill(' ')<<endl;
    for (int j=0; j<numEmp; j++) {
        arch<<empresas[j];
    }

}