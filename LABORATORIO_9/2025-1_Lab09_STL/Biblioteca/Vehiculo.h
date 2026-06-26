//
// Created by USER on 24/06/2026.
//

#ifndef INC_2025_1_LAB09_STL_VEHICULO_H
#define INC_2025_1_LAB09_STL_VEHICULO_H
#include <string>
#include <fstream>

using namespace std;

class Vehiculo {

private:
    string placa;
    string marca;
    string modelo;
public:
    Vehiculo();
    string get_placa() const;
    void set_placa(const string &placa);
    string get_marca() const;
    void set_marca(const string &marca);
    string get_modelo() const;
    void set_modelo(const string &modelo);


    void leeVehiculo(ifstream &arch);
    void operator >>(ifstream &arch);

    // void imprimirVehiculo(ofstream &arch);
    void operator << (ofstream &arch);



};


#endif //INC_2025_1_LAB09_STL_VEHICULO_H
