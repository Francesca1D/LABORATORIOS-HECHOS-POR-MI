//Francesca Condor, 20176818
  #include <iostream>
#include "Biblioteca/MinisterioDeTransporte.h"
int main() {
    MinisterioDeTransporte min;
    min<"ArchivosDeEntrada/TablaDeInfracciones.csv";
    min<="ArchivosDeEntrada/EmpresasRegistradas.csv";
    min>>"ArchivosDeSalida/Reporte2.txt";


    return 0;
}
