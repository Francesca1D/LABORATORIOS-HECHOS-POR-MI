//
// Created by USER on 11/06/2026.
//

#include "GestorStreamer.h"

#include "MetricaBasica.h"
#include "MetricaCalidad.h"
#include "MetricaEngagement.h"

GestorStreamer::GestorStreamer() {
    ptrmetrica= nullptr;
}

GestorStreamer:: ~GestorStreamer() {
    if (ptrmetrica != nullptr) delete ptrmetrica;

}

void GestorStreamer::leeStreamer(ifstream &arch) {
    char cad[20], c;
    int id_stream;

    arch.getline(cad,20,',');
    if (arch.eof()) return;
    arch>>id_stream>>c;
    if (strcmp("QUALITY",cad)==0)
        ptrmetrica = new MetricaCalidad;
    if (strcmp("BASIC",cad)==0)
        ptrmetrica = new MetricaBasica;
    if (strcmp("ENGAGEMENT",cad)==0)
        ptrmetrica = new MetricaEngagement;
    ptrmetrica->leer(arch);
}

int GestorStreamer::obtenerIDStreamer() {
    return ptrmetrica->obtenerID();
}

void GestorStreamer::imprimirStreamer(ofstream &arch) {
    ptrmetrica->imprimir(arch);
}


// QUALITY,497201,3030,Calidad estable,2025-09-06,2025-12-31,7208,0.074,50
// BASIC,921675,101,Clips del evento,2025-09-11,2025-12-31,1.36,19
// ENGAGEMENT