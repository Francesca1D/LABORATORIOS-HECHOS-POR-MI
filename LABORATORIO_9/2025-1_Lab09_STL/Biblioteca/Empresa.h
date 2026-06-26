//
// Created by USER on 24/06/2026.
//

#ifndef INC_2025_1_LAB09_STL_EMPRESA_H
#define INC_2025_1_LAB09_STL_EMPRESA_H
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <list>

#include "Vehiculo.h"
#include "Multa.h"


using namespace std;

class Empresa {
private:
    int dni;
    string nombre;
    string distrito;
    map<string, class Vehiculo> vehiculos; //first placa
    vector<class Multa> multasRecibidas;

public:
    Empresa();
    int get_dni() const;
    void set_dni(int dni);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    string get_distrito() const;
    void set_distrito(const string &distrito);

    void leeEmpresa(ifstream &arch);
    void cargarVehiculo(ifstream &arch);
    void cargarMultas(const char *nombArch, list<class Infraccion>);
    void imprimeEmpresas(ofstream &arch);
    void eliminaMultas();

    bool operator <(Empresa &emp) const;

};


#endif //INC_2025_1_LAB09_STL_EMPRESA_H
