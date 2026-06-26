//
// Created by USER on 24/06/2026.
//

#ifndef INC_2025_1_LAB09_STL_MINISTERIODETRANSPORTE_H
#define INC_2025_1_LAB09_STL_MINISTERIODETRANSPORTE_H
#include <list>
// #include <iterator>
// #include <algorithm>
#include <fstream>

#include "Empresa.h"
#include "Infraccion.h"

using namespace std;


class MinisterioDeTransporte {
private:
    list<class Infraccion> tablaInfracciones;
    list<class Empresa> listaEmpresas;
public:
    MinisterioDeTransporte();

    void cargaDeInfracciones(const char *nombArch);
    void cargaEmpresas(const char *nombArch);
    void cargaVehiculos(const char *nombArch);
    void cargaInfraccionesCometidas(const char *nombArch);
    void reporteDeEmpresasConInfracciones(const char *nombArch);
    void eliminaInfraccionesPagadas();


    void buscarAsigna(int dni,ifstream &arch);


};


#endif //INC_2025_1_LAB09_STL_MINISTERIODETRANSPORTE_H
