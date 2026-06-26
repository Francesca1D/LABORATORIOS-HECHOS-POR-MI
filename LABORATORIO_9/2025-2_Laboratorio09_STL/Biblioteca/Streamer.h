//
// Created by USER on 25/06/2026.
//

#ifndef INC_2025_2_LABORATORIO09_STL_STREAMER_H
#define INC_2025_2_LABORATORIO09_STL_STREAMER_H

#include <fstream>
#include <vector>

#include "Categoria.h"
#include "Comentario.h"
#include "Etiqueta.h"

using namespace std;

class Streamer {
private:
    string canal;
    int fecha;
    Categoria categoria;
    string etiquetasStr;
    vector<class Etiqueta> etiquetasVector;
    string idioma;

    vector<string> comentarios;


public:
    Streamer();
    virtual ~Streamer();

    string get_canal() const;
    void set_canal(const string &canal);
    int get_fecha() const;
    void set_fecha(int fecha);
    string get_etiquetas_str() const;
    void set_etiquetas_str(const string &etiquetas_str);
    string get_idioma() const;
    void set_idioma(const string &idioma);

    void operator >>(ifstream &arch);
    void operator <<(ofstream &arch);

};


#endif //INC_2025_2_LABORATORIO09_STL_STREAMER_H
