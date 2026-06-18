//
// Created by USER on 16/06/2026.
//

#ifndef EMERGENCIASPROG2_2026_1_GESTORATENCIONES_H
#define EMERGENCIASPROG2_2026_1_GESTORATENCIONES_H
#include "Atencion.h"


class GestorAtenciones {
private:
    Atencion **atenciones;
    int cantidad_atenciones;
    // int capacidad;
public:
    GestorAtenciones();
    virtual ~GestorAtenciones();
    int get_cantidad_atenciones() const;
    void set_cantidad_atenciones(int cantidad_atenciones);

    Atencion * reservar_memoria_atencion(char tipo, ifstream &arch);
    void cargarAtenciones(const char *nombre_archivo, int hora);

    void procesar_dia(const char *fecha);
    void construir_nombre_archivo(char *destino, const char *base, int hh);
    // void agregar_atencion(Atencion *atenciones);
    // void leeAtenciones(ifstream &arch);
    void generar_reporte_diario(const char *nombre_reporte);
    void imprimirTitulosEmergencias(ofstream &arch);
    void imprimirTitulosUrgencias(ofstream &arch);
    void imprimirTitulosNoUrgencias(ofstream &arch);

    // void imprimirAtenciones(ofstream &arch);


};


#endif //EMERGENCIASPROG2_2026_1_GESTORATENCIONES_H
