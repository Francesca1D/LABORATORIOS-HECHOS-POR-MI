//Francesca Condor, 20176818

#include "Biblioteca/GestorAtenciones.h"

int main() {

    GestorAtenciones gestor;

    gestor.cargarAtenciones("ArchivosDeDatos/00.csv");
    // gestor.procesar_dia("1992-01-23");
    // gestor.procesar_dia("1992-01-01");
    // gestor.generar_reporte_diario("Reporte.txt");

    return 0;
}
