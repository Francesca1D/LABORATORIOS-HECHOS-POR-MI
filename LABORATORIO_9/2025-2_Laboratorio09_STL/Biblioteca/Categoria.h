//
// Created by USER on 25/06/2026.
//

#ifndef INC_2025_2_LABORATORIO09_STL_CATEGORIA_H
#define INC_2025_2_LABORATORIO09_STL_CATEGORIA_H
#include <string>
#include <fstream>

using namespace std;

class Categoria {
private:
    string codigo;
    string nombre;
    string descripcion;

public:
    Categoria();
    virtual ~Categoria();
    Categoria(const Categoria& orig);

    string get_codigo() const;
    void set_codigo(const string &codigo);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    string get_descripcion() const;
    void set_descripcion(const string &descripcion);

    void operator =(const Categoria& orig);
    void operator >>(ifstream &arch);
    void operator <<(ofstream &arch);
    bool operator <(const Categoria &inf) const;

};


#endif //INC_2025_2_LABORATORIO09_STL_CATEGORIA_H
