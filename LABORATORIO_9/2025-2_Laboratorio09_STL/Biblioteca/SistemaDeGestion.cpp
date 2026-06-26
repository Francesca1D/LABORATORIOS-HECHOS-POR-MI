//
// Created by USER on 25/06/2026.
//

#include "SistemaDeGestion.h"

#include <iomanip>
#include <iostream>


SistemaDeGestion::SistemaDeGestion(){

}

SistemaDeGestion:: ~SistemaDeGestion(){

}

// list<class Categoria> categorias;

void SistemaDeGestion::cargarCategorias(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }

    while (true) {
        Categoria aux;
        aux>>arch;
        if (arch.eof())break;
        categorias.push_back(aux);
    }
    categorias.sort();
}
    // list<class Comentario> comentarios;

void SistemaDeGestion::cargarComentarios(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }


    while (true) {
        Comentario aux;
        aux>>arch;
        if (arch.eof())break;
        comentarios.push_back(aux);
    }
    comentarios.sort();
}
// map<string, class Etiqueta> etiquetas;
void SistemaDeGestion::cargaEtiquetas(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }

    while (true) {
        Etiqueta aux;
        aux>>arch;
        if (arch.eof())break;
        etiquetas[aux.get_codigo()]=aux;
    }
}

// list<class Streamer> Streamers;

void SistemaDeGestion::cargaStreamers(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }

    while (true) {
        Streamer aux;
        aux>>arch;
        if (arch.eof())break;
        Streamers.push_back(aux);
    }
    Streamers.sort(); //verificar!!!!!!!!!!!!!!!
}
    // list<class Streamer> Streamers;

void SistemaDeGestion::completarStreamers() {
    for (list<class Streamer> ::iterator it= Streamers.begin(); it!= Streamers.end(); ++it) {
        it->buscaryAsignarCategoria(categorias);
        it->buscarYAsignarEtiqueta(etiquetas);
        it->buscarYAsignarComentarios(comentarios);
    }

}

void SistemaDeGestion::reporteDeStreamers(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<setw(100)<<setfill('=')<<'='<<setfill(' ')<<endl;
    arch<<setw(40)<<' '<<"RELACION DE STREAMERS"<<endl;
    arch<<setw(100)<<setfill('=')<<'='<<setfill(' ')<<endl;
    for (list<class Streamer> ::iterator it= Streamers.begin(); it!= Streamers.end(); ++it) {
        *it<<arch;
        arch<<endl;
        arch<<setw(100)<<setfill('-')<<'-'<<setfill(' ')<<endl;

    }

}


//APRENDER ESTO!!!!!!!!!!!!!!!!!!!
void SistemaDeGestion::eliminaStremaers(string idi) {
    for (list<class Streamer> ::iterator it= Streamers.begin(); it!= Streamers.end(); ) {
        bool esidioma= it->isIdioma(idi);
        if (esidioma) {
            it = Streamers.erase(it);
        }else {
            it++;
        }
    }
}
