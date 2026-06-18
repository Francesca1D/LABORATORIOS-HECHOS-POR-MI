//Francesca Condor, 20176818

#include "Biblioteca/GestorAtenciones.h"

int main() {

    GestorAtenciones gestor;

    gestor.procesar_dia("2026-06-11");
    // gestor.procesar_dia("1992-01-23");
    // gestor.procesar_dia("2026-01-01");
    gestor.generar_reporte_diario("ArchivosDeSalida/Reporte1.txt");

    return 0;
}
