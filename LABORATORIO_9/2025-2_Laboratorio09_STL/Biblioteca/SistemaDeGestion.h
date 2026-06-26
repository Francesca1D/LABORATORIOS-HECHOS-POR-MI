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
#include "Etiqueta.h"
#include "Streamer.h"

using namespace std;

class SistemaDeGestion {
private:
    list<class Categoria> categorias;
    list<class Comentario> comentarios;
    map<string, class Etiqueta, less<string>> etiquetas;
    list<class Streamer> Streamers;

public:
    SistemaDeGestion();
    virtual ~SistemaDeGestion();

    void cargarCategorias(const char *nombArch);
    void cargarComentarios(const char *nombArch);
    void cargaEtiquetas(const char *nombArch);
    void cargaStreamers(const char *nombArch);

    void completarStreamers();
    void reporteDeStreamers(const char *nombArch);
    void eliminaStremaers(string idioma);

};


#endif //INC_2025_2_LABORATORIO09_STL_SISTEMADEGESTION_H
