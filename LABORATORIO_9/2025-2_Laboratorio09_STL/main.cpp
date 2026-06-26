//Francesca Condor, 20176818
#include "Biblioteca/SistemaDeGestion.h"
int main() {

    SistemaDeGestion sis;

    sis.cargarCategorias("ArchivosDeDatos/Categorias.csv");
    sis.cargarComentarios("ArchivosDeDatos/Comentarios.csv");
    sis.cargaEtiquetas("ArchivosDeDatos/Etiquetas.csv");
    sis.cargaStreamers("ArchivosDeDatos/Streamers.csv");

    sis.completarStreamers();
    sis.reporteDeStreamers("ArchivosDeReporte/Reporte1.txt");
    sis.eliminaStremaers("French");
    sis.reporteDeStreamers("ArchivosDeReporte/Reporte2.txt");




    return 0;
}



//ArchivosDeDatos ArchivosDeReporte