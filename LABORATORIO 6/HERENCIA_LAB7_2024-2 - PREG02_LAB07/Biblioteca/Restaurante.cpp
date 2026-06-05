//
// Created by USER on 3/06/2026.
//

#include "Restaurante.h"

Restaurante::Restaurante() {
    cantidad_comandas=0;
}
Restaurante:: ~Restaurante() {

}

int Restaurante::get_cantidad_comandas() const {
    return cantidad_comandas;
}

void Restaurante::set_cantidad_comandas(int cantidad_comandas) {
    this->cantidad_comandas = cantidad_comandas;
}

//738,11:40,12:43
//936,08:32,09:13
void Restaurante::cargar_comandas() {
    int id, ha, ma, hs, ms;
    char c;
    ifstream arch("ArchivosDeEntrada/atenciones.csv", ios::in);
    if (not arch.is_open()) {
        cout<< "Error al abrir archivo atenciones "<<endl;
        exit(1);
    }
    while (true) {
        arch>>id;
        if (arch.eof()) break;
        comandas[cantidad_comandas].set_id(id);
        arch>>c>>ha>>c>>ma>>c>>hs>>c>>ms;
        comandas[cantidad_comandas].set_hora_atencion(ha*60+ma);
        comandas[cantidad_comandas].set_hora_servicio(hs*60+ms);
        buscayasigna(id);
        cantidad_comandas++;
    }
    recorte();
}

void Restaurante::buscayasigna(int pid) {
    int idcom;
    char c,tipo, cad[100];
    ifstream arch("ArchivosDeEntrada/comandas.csv", ios::in);
    if (not arch.is_open()) {
        cout<< "Error al abrir archivo comandas "<<endl;
        exit(1);
    }
    while (true) {
        arch>>idcom;
        if (arch.eof()) break;
        if (pid == idcom) {
            arch>>c>>tipo>>c;
            comandas[cantidad_comandas].leecomanda(tipo,arch);
        }else {
            arch.getline(cad,100);
        }
    }
}

void Restaurante::imprimir_comandas() {
    ofstream arch("ArchivosDeSalida/Reporte2.txt", ios::out);
    if (not arch.is_open()) {
        cout<< "Error al abrir archivo Reporte "<<endl;
        exit(1);
    }
    arch<<setw(70)<<setfill('=')<<'='<<setfill(' ')<<endl;
    arch<<setw(40)<<"COMANDAS RESTAURANTE"<<endl;
    for (int i = 0; i < cantidad_comandas; i++) {
        arch<<setw(70)<<setfill('=')<<'='<<setfill(' ')<<endl;
        arch<<setw(40)<<"Comanda "<<i+1<<endl;
        arch<<setw(70)<<setfill('=')<<'='<<setfill(' ')<<endl;

        comandas[i].imprimecomandas(arch);
        //arch<<comandas[i].get_id()<<endl;

    }
    arch<<setw(70)<<setfill('=')<<'='<<setfill(' ')<<endl;

}

void Restaurante::recorte() {
    for (int i = 0; i < cantidad_comandas; i++) {
        if (not comandas[i].isnull()) {
            comandas[i].recortarEntradas();
        }
    }
}

void Restaurante::actualizar_comandas() {
    char cad[20];
    ofstream arch("ArchivosDeSalida/ReporteTotal.txt", ios::out);
    if (not arch.is_open()) {
        cout<< "Error al abrir archivo ReporteTotal "<<endl;
        exit(1);
    }
    arch<<setw(30)<<setfill('=')<<'='<<setfill(' ')<<endl;
    arch<<setw(20)<<"TOTALES"<<endl;
    arch<<setw(30)<<setfill('=')<<'='<<setfill(' ')<<endl;
    for (int i = 0; i < cantidad_comandas; i++) {
        //arch<<setw(30)<<setfill('-')<<'-'<<setfill(' ')<<endl;
        arch<<left<<"Comanda "<<i+1<<right<< "  S/" ;
        comandas[i].calcularTotal(arch);
        //arch<<comandas[i].get_id()<<endl;
        if (comandas[i].get_tiempo_preparacion()>(comandas[i].get_hora_servicio()-comandas[i].get_hora_atencion())) {
            comandas[i].set_estado("ATENDIDA CON RETRASO");
        }else comandas[i].set_estado("ATENDIDA");
        comandas[i].get_estado(cad);
        arch<< "Estado: "<<cad<<endl;
        arch<<setw(30)<<setfill('-')<<'-'<<setfill(' ')<<endl;
    }
}

