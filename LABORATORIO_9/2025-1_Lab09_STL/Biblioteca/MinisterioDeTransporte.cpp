//
// Created by USER on 24/06/2026.
//

#include "MinisterioDeTransporte.h"

#include <iomanip>
#include <iostream>


MinisterioDeTransporte::MinisterioDeTransporte() {

}
// G2007,425.23,GRAVE,No conducir por el carril de extremo derecho de la calzada un vehiculo de transporte p�blico de pasajeros o de carga.
// M1029,586.45,MUY GRAVE,Conducir un vehiculo especial que no se ajuste a las exigencias reglamentarias sin la autorizacion correspondiente.
// M1018,606.11,MUY GRAVE,Desobedecer las indicaciones sobre el transito que ordene el efectivo de la Policia Nacional del Per� asignado al control del transito.

// list<class Infraccion> tablaInfracciones;


//  CAMBIAR A OPERADOR >>
// void MinisterioDeTransporte::cargaDeInfracciones(const char *nombArch) {
//     ifstream arch(nombArch, ios::in);
//     if (not arch.is_open()) {
//         cout<<"Error al abrir el archivo "<<nombArch<<endl;
//         exit(1);
//     }
//     while (true) {
//         Infraccion aux;
//         aux.leeInfraccion(arch);
//         if (arch.eof()) break;
//         tablaInfracciones.push_back(aux);
//     }
//     tablaInfracciones.sort();
// }

//OPERADOR >>
void MinisterioDeTransporte::cargaDeInfracciones(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while (true) {
        Infraccion aux;
        aux>>arch;
        if (arch.eof()) break;
        tablaInfracciones.push_back(aux);
    }
    tablaInfracciones.sort();
}

// list<class Empresa> listaEmpresas;

void MinisterioDeTransporte::cargaEmpresas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }

    while (true) {
        Empresa aux;
        aux.leeEmpresa(arch); //  CAMBIAR A OPERADOR >>
        if (arch.eof()) break;
        listaEmpresas.push_back(aux); //ordenar
    }
    listaEmpresas.sort();
}

// 12443643,M421-807,Honda,Fit
// 90467829,P985-495,Honda,HR-V
// 80310768,M982-853,Honda,Civic

// list<class Empresa> listaEmpresas;
// map<string, class Vehiculo> vehiculos; //first placa

void MinisterioDeTransporte::cargaVehiculos(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while (true) {
        int dni;
        arch >> dni;
        if (arch.eof()) break;
        arch.get();
        buscarAsigna(dni,arch);
    }
}

void MinisterioDeTransporte::buscarAsigna(int dni,ifstream &arch) {
    char cad[200];
    for (list<Empresa>::iterator it=listaEmpresas.begin();it!=listaEmpresas.end();it++ ) {
        if (it->get_dni()==dni) {
            it->cargarVehiculo(arch);
            return;
        }
    }
    arch.getline(cad,200,'\n'); //arch.getline(cad,200);
}

// 1/12/2020,G760-721,G2022,N
// 23/07/2023,P474-593,G2060,P,22/08/2023
// 18/12/2024,G938-342,G2061,P,26/01/2025
// 6/08/2021,P863-768,G2025,N

// vector<class Multa> multasRecibidas;

//ORDENAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *nombArch) {
    char cad[200],c;

    for (list<Empresa>::iterator it = listaEmpresas.begin(); it != listaEmpresas.end(); it++) {
        it->cargarMultas(nombArch,tablaInfracciones); // un vehiculo puede tener varias multas
        // it->agregarMulta(tablaInfracciones);
    }
}

// map<string, class Vehiculo> vehiculos; //first placa
// vector<class Multa> multasRecibidas;


void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<left<<setw(100)<<setfill('=')<<'='<<setfill(' ')<<endl;
    arch<<setw(25)<<" "<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    arch<<left<<setw(100)<<setfill('-')<<'-'<<setfill(' ')<<endl;

    for (list<Empresa>::iterator it=listaEmpresas.begin();it!=listaEmpresas.end();it++ ) {
        it->imprimeEmpresas(arch);
    }
}

void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
    for (list<Empresa>::iterator it=listaEmpresas.begin();it!=listaEmpresas.end();it++ ) {
        it->eliminaMultas();
    }
}

