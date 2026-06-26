//
// Created by USER on 25/06/2026.
//

#include "Streamer.h"

Streamer::Streamer() {

}

Streamer:: ~Streamer(){

}

string Streamer::get_canal() const {
    return canal;
}

void Streamer::set_canal(const string &canal) {
    this->canal = canal;
}

int Streamer::get_fecha() const {
    return fecha;
}

void Streamer::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Streamer::get_etiquetas_str() const {
    return etiquetasStr;
}

void Streamer::set_etiquetas_str(const string &etiquetas_str) {
    etiquetasStr = etiquetas_str;
}

string Streamer::get_idioma() const {
    return idioma;
}

void Streamer::set_idioma(const string &idioma) {
    this->idioma = idioma;
}


// summit1g,12/11/2021,MK1092,HTR108-UPK123-SWT139-LWC105,English
// Gaules,15/02/2022,CY1025,KRH188-BBY119,Portuguese
// ESL_CSGO,16/11/2023,DQ1021,UFK146-CUV131-EHZ179,English

// string canal;
// int fecha;
// Categoria categoria;
// string etiquetasStr;
// vector<class Etiqueta> etiquetasVector;
// string idioma;

void Streamer::operator >>(ifstream &arch) {
    int dd,mm,aa;
    char c;
    string cat;
    getline(arch,canal,',');
    if (arch.eof())return;;
    arch>>dd>>c>>mm>>c>>aa>>c;
    fecha = dd+mm*100+aa*10000;
    getline(arch,cat,',');
    categoria.set_codigo(cat);
//falta

}

void Streamer::operator <<(ofstream &arch){

}

