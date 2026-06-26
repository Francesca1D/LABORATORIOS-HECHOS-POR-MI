//
// Created by USER on 25/06/2026.
//

#ifndef INC_2025_2_LABORATORIO09_STL_ETIQUETA_H
#define INC_2025_2_LABORATORIO09_STL_ETIQUETA_H
#include <string>
#include <fstream>

using namespace std;

class Etiqueta {
private:
    string codigo;
    string nombre;

public:
    Etiqueta();
    virtual ~Etiqueta();
    Etiqueta(const Etiqueta &);
    string get_codigo() const;
    void set_codigo(const string &codigo);
    string get_nombre() const;
    void set_nombre(const string &nombre);

    void operator = (const Etiqueta &orig);
    void operator >>(ifstream &arch);
    void operator <<(ofstream &arch);


};


#endif //INC_2025_2_LABORATORIO09_STL_ETIQUETA_H
