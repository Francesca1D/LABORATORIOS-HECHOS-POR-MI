//
// Created by USER on 25/06/2026.
//

#ifndef INC_2025_2_LABORATORIO09_STL_SISTEMADEGESTION_H
#define INC_2025_2_LABORATORIO09_STL_SISTEMADEGESTION_H
#include <string>
#include <fstream>
#include <list>
#include <map>

#include "Categoria.h"
#include "Comentario.h"

using namespace std;

class SistemaDeGestion {
private:
    list<class Categoria> categorias;
    list<class Comentario> comentarios;
    map<string, class Etiqueta> etiquetas;
    list<class Streamer> Streamers;

};


#endif //INC_2025_2_LABORATORIO09_STL_SISTEMADEGESTION_H
