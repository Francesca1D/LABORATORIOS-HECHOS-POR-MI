//
// Created by USER on 24/06/2026.
//

#ifndef INC_2025_1_LAB09_STL_INFRACCION_H
#define INC_2025_1_LAB09_STL_INFRACCION_H
#include <string>
#include <fstream>

using namespace std;

class Infraccion {
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;

public:
    Infraccion();
    string get_codigo() const;
    void set_codigo(const string &codigo);
    double get_multa() const;
    void set_multa(double multa);
    string get_gravedad() const;
    void set_gravedad(const string &gravedad);
    string get_descripcion() const;
    void set_descripcion(const string &descripcion);

    void leeInfraccion(ifstream &arch);


    // void operator >>(ifstream &arch);
    // void operator >>(ifstream &arch, Infraccion &inf);
    void operator >>(ifstream &arch);

    bool operator <(Infraccion &inf) const;

};


#endif //INC_2025_1_LAB09_STL_INFRACCION_H
