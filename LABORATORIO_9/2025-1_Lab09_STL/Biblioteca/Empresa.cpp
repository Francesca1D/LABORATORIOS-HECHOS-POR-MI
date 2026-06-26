//
// Created by USER on 24/06/2026.
//

#include "Empresa.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "Infraccion.h"

Empresa::Empresa() {
    dni=0;
}


int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

string Empresa::get_nombre() const {
    return nombre;
}

void Empresa::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

string Empresa::get_distrito() const {
    return distrito;
}

void Empresa::set_distrito(const string &distrito) {
    this->distrito = distrito;
}

// 79672079,CONTRERAS CHANG JOHANA CINTHIA,CHORRILLOS
// 77763722,FARFAN SALAZAR MARGOT,LA MOLINA
// 19568447,VEGA SORIA HENRRY,SAN JUAN DE LURIGANCHO

// int dni;
// string nombre;
// string distrito;
// map<string, class Vehiculo> vehiculos; //first placa
// vector<class Multa> multasRecibidas;

void Empresa::leeEmpresa(ifstream &arch) {
    char c;
    arch>>dni>>c;
    if (arch.eof()) return;
    getline(arch,nombre,',');
    getline(arch,distrito,'\n');

}
//CON METODO
// void Empresa::cargarVehiculo(ifstream &arch) {
//     Vehiculo aux;
//     aux.leeVehiculo(arch);
//     vehiculos[aux.get_placa()]=aux;
//
// }
//OPERADOR >>
void Empresa::cargarVehiculo(ifstream &arch) {
    Vehiculo aux;
    aux>>arch;
    vehiculos[aux.get_placa()]=aux;

}
// map<string, class Vehiculo> vehiculos; //first placa
// vector<class Multa> multasRecibidas;


// void Empresa::cargarMultas(const char *nombArch, list<class Infraccion> tablaInfracciones ) {
//     char cad[200];
//     ifstream arch(nombArch, ios::in);
//     if (not arch.is_open()) {
//         cout << "Error al abrir el archivo " << nombArch << endl;
//         exit(1);
//     }
//     int dd;
//     Multa aux;
//     while (true) {
//         arch>>dd;
//         if (arch.eof()) break;
//         aux.leeMulta(arch, dd);
//         for (map<string, class Vehiculo>::iterator it=vehiculos.begin();it!=vehiculos.end();it++ ) {
//             if (aux.get_placa() == it->second.get_placa()) {
//                 for (list<class Infraccion> ::iterator itIn= tablaInfracciones.begin();itIn!=tablaInfracciones.end();itIn++ ) {
//                     if (itIn->get_codigo()== aux.get_cod_multa()) {
//                         aux.set_multa(itIn->get_multa()); //agrega multa
//                         break;
//                     }
//                 }
//
//                 multasRecibidas.push_back(aux);
//             }
//     }
//         sort(multasRecibidas.begin(), multasRecibidas.end());
//     }
// }
//CON OPERADOR >>
void Empresa::cargarMultas(const char *nombArch, list<class Infraccion> tablaInfracciones ) {
    char cad[200];
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int dd;
    Multa aux;
    while (true) {
        // arch>>dd;
        aux>>arch;
        if (arch.eof()) break;
        for (map<string, class Vehiculo>::iterator it=vehiculos.begin();it!=vehiculos.end();it++ ) {
            if (aux.get_placa() == it->second.get_placa()) {
                for (list<class Infraccion> ::iterator itIn= tablaInfracciones.begin();itIn!=tablaInfracciones.end();itIn++ ) {
                    if (itIn->get_codigo()== aux.get_cod_multa()) {
                        aux.set_multa(itIn->get_multa()); //agrega multa
                        break;
                    }
                }

                multasRecibidas.push_back(aux);
            }
        }
        sort(multasRecibidas.begin(), multasRecibidas.end());
    }
}


    // para cada empresa, tiene su lista de vehiculos que estan en un map
    // cada empresa tiene sus multas que es un vector


// int dni;
// string nombre;
// string distrito;
// map<string, class Vehiculo> vehiculos; //first placa
// vector<class Multa> multasRecibidas;

void Empresa::imprimeEmpresas(ofstream &arch) {
    arch<<left<<"DNI: "<<right<<setw(8)<< dni<<setw(5)<<" ";
    arch<<left<<"NOMBRE: "<<setw(40)<< nombre;
    arch<<left<<"DISTRITO: "<<setw(30)<< distrito<<endl;
    arch<<"VEHICULOS DE LA EMPRESA:"<<endl;
    arch << left << setw(15) << "PLACA" << setw(20) << "MARCA" << "MODELO" << endl;
    for (map<string, class Vehiculo>::iterator it=vehiculos.begin();it!=vehiculos.end();it++ ) {
            // it->second.imprimirVehiculo(arch);
            it->second<<(arch); //OPERATOR
    }
    arch<<left<<setw(100)<<setfill('-')<<'-'<<setfill(' ')<<endl;
    arch<<left<<"MULTAS IMPUESTAS"<<endl;

    arch<<left<<setw(15)<<"PLACA"<<setw(20)<<"FECHA DE INFRACCION"<<"CODIGO DE INFRACCION "<<setw(10)<<
            "MULTA"<<"PAGADA  "<<"FECHA DE PAGO"<< endl;
    for (int i=0; i<multasRecibidas.size(); i++ ) {
        // multasRecibidas[i].imprimirMultas(arch);
        multasRecibidas[i]<<(arch);
    }
    arch<<endl;
    arch<<left<<setw(100)<<setfill('=')<<'='<<setfill(' ')<<endl;
    // arch<<left<<setw(15)<<"PLACA"<<setw(20)<<"FECHA DE INFRACCION"<<"CODIGO DE INFRACCION"<<setw(10)<<
    //     "MULTA"<<setw(8)<<"PAGADA"<<"FECHA DE PAGO"<< endl;


}

bool Empresa::operator <(Empresa &emp) const {
    return dni<emp.dni;
}

void Empresa::eliminaMultas() {
    for (vector<class Multa> ::iterator it=multasRecibidas.begin(); it!=multasRecibidas.end(); ) {
        if (it->is_pagada()) {
            multasRecibidas.erase(it);
            // it=multasRecibidas.erase(it);
        }else {
            it++;
        }
    }
}
