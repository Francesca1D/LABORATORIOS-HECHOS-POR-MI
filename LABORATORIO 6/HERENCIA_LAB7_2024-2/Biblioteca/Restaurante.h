//
// Created by USER on 3/06/2026.
//

#ifndef HERENCIA_LAB7_2024_2_RESTAURANTE_H
#define HERENCIA_LAB7_2024_2_RESTAURANTE_H
#include "Comanda.h"
#include "fstream"
#include "iostream"
#include "iomanip"

using namespace std;

class Restaurante {
private:
    Comanda comandas[100];  //Estatico
    int cantidad_comandas;

public:

    Restaurante();
    virtual ~Restaurante();
    int get_cantidad_comandas() const;
    void set_cantidad_comandas(int cantidad_comandas);
    void cargar_comandas();
    void buscayasigna(int id);
    void imprimir_comandas();
    void recorte();
    void actualizar_comandas();

};


#endif //HERENCIA_LAB7_2024_2_RESTAURANTE_H
