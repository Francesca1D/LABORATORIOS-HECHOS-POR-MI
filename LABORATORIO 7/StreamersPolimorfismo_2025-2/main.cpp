#include <iostream>

#include "Biblioteca/AdministrarMetricas.h"

int main() {

    AdministrarMetricas met;

    met.carga("ArchivosDeEntrada/metricas.csv");
    met.generarReporte("ArchivosDeSalida/Reporte.txt");
    return 0;
}

//ArchivosDeEntrada ArchivosDeSalida