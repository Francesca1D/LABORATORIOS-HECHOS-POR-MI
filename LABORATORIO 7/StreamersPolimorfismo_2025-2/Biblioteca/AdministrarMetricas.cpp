//
// Created by USER on 11/06/2026.
//

#include "AdministrarMetricas.h"



AdministrarMetricas::AdministrarMetricas() {
    cantidadStreamer=0;
}

AdministrarMetricas:: ~AdministrarMetricas() {

}
int AdministrarMetricas::get_cantidad_streamer() const {
    return cantidadStreamer;
}

void AdministrarMetricas::set_cantidad_streamer(int cantidad_streamer) {
    cantidadStreamer = cantidad_streamer;
}
void AdministrarMetricas::carga(const char *nombArch) {

    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        streamer[i].leeStreamer(arch);
        if (arch.eof()) break;
        i++;
    }
    cantidadStreamer=i;
}

void AdministrarMetricas::generarReporte(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=0;
    // while (streamer[i].obtenerIDStreamer()!=0) {
    //     streamer[i].imprimirStreamer(arch);
    //     i++;
    // }
    // if (streamer!=nullptr) {
    for (i = 0; i<cantidadStreamer; i++) {
        streamer[i].imprimirStreamer(arch);
    }


}
