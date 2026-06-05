//Francesca Condor, 20176818

#include "Biblioteca/Tesoreria.h"
using namespace std;

int main() {
    Tesoreria caja;
    caja.cargaescalas();
    caja.cargaalumnos();
    caja.actualiza(20); //FALTA ACTUALIZAR
    caja.imprime();

    return 0;
}

//ArchivosDeEntrada ArchivosDeSalida