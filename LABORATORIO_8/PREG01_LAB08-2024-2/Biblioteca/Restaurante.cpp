//
// Created by USER on 18/06/2026.
//

#include "Restaurante.h"

Restaurante::Restaurante() {

}

Restaurante:: ~Restaurante() {

}

void Restaurante::carga() {
    ifstream arch("ArchivosDeEntrada/comandas2.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo comandas2.csv"<<endl;
        exit(1);
    }
    Ccomanda.cargacola(arch);
}


// void Restaurante::elimina(int num);

void Restaurante::atiende() {
    ofstream arch("ArchivosDeSalida/Reporte.txt", ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch<<setw(5)<<" "<<"Detalle de Comandas: "<<endl;
    arch<<setw(5)<<" "<<setw(30)<<setfill('=')<<'='<<setfill(' ')<<endl;
    Ccomanda.imprimecola(arch);
}