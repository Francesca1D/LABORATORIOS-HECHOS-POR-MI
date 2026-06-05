//
// Created by USER on 3/06/2026.
//

#ifndef HERENCIA_LAB7_2024_2_COMANDA_H
#define HERENCIA_LAB7_2024_2_COMANDA_H
#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"
class Comanda {
public:
    Comanda();
    virtual ~Comanda();
    int get_id() const;
    void set_id(int id);
    int get_cantidad_bebidas() const;
    void set_cantidad_bebidas(int cantidad_bebidas);
    int get_cantidad_platos_fondo() const;
    void set_cantidad_platos_fondo(int cantidad_platos_fondo);
    int get_hora_atencion() const;
    void set_hora_atencion(int hora_atencion);
    int get_hora_servicio() const;
    void set_hora_servicio(int hora_servicio);
    int get_tiempo_preparacion() const;
    void set_tiempo_preparacion(int tiempo_preparacion);
    double get_total() const;
    void set_total(double total);
    void leecomanda(char tipo,ifstream &arch);
    void imprimecomandas(ofstream &arch);
    bool isnull();
    void recortarEntradas();
    int cuentaEntradas();

private:
    int id;
    Bebida bebidas[200];        //estatico
    Entrada *entradas;          //dinamico
    PlatoFondo platos_fondo[200]; //estatico
    int cantidad_bebidas;
    //int cantidad_entradas;
    int cantidad_platos_fondo;
    int hora_atencion;
    int hora_servicio;
    int tiempo_preparacion;
    double total;
    //char *estado;
};


#endif //HERENCIA_LAB7_2024_2_COMANDA_H
