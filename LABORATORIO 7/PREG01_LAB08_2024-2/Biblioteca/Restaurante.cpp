//
// Created by USER on 11/06/2026.
//

#include "Restaurante.h"


Restaurante::Restaurante() {

}

Restaurante:: ~Restaurante() {

}

void Restaurante::carga() {
    ifstream arch("ArchivosDeEntrada/comandas2.csv",ios::in);
    if(not arch.is_open()) {
        cout<<"Error al abrir el archivo comandas2.csv"<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        comandas[i].leecomandas(arch);
        if (arch.eof()) break;
        i++;
    }
}
void Restaurante::atiende() {
    ofstream arch("ArchivosDeSalida/Reporte.txt",ios::out);
    if(not arch.is_open()) {
        cout<<"Error al abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch<< "Detalle de Comandas"<<endl;
    arch<<setw(60)<<setfill('=')<<'='<<setfill(' ')<<' '<<endl;
    for (int i=0; comandas[i].get_id()!=0;i++) {
        arch<<"Codigo de comanda: "<<comandas[i].get_id()<<endl;
        comandas[i].imprime(arch);
    }
}
