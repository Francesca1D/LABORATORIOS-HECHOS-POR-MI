//Francesca Condor, 20176818
#include "Biblioteca/SistemaDeGestion.h"
int main() {

    SistemaDeGestion sis;

    sis.cargarCategorias("ArchivosDeDatos/Categorias.csv");
    sis.cargarComentaros();
    sis.cargaEtiquetas();
    sis.cargaStreamers();

    sis.completarStreamers();
    sis.reporteDeStreamers();
    sis.eliminaStremaers(string);

    


    return 0;
}



//ArchivosDeDatos ArchivosDeReporte