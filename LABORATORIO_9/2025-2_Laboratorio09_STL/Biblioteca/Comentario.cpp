//
// Created by USER on 25/06/2026.
//

#include "Comentario.h"

Comentario::Comentario(){

}

Comentario:: ~Comentario(){

}

Comentario::Comentario(const Comentario &orig){
    *this = orig;
}


string Comentario::get_canal() const {
    return canal;
}

void Comentario::set_canal(const string &canal) {
    this->canal = canal;
}

string Comentario::get_comentario() const {
    return comentario;
}

void Comentario::set_comentario(const string &comentario) {
    this->comentario = comentario;
}

void Comentario::operator=(const Comentario &orig){
    canal=orig.canal;
    comentario=orig.comentario;

}

// LosPollosTV,reds
// midbeast,https://www easports com/fifa/ultimate-team/web-app/?showoffid
// yamatonjp,any good bundesliga cb or bpl for around 200k

void Comentario::operator >>(ifstream &arch){
    getline(arch,canal,',');
    if (arch.eof())return;
    getline(arch,comentario,'\n');
}

void Comentario::operator <<(ofstream &arch){
    // arch<<canal<<" "<<comentario<<endl;
    arch<<canal<<" "<<comentario<<endl;
}

bool Comentario::operator <(const Comentario &com) const {
    return canal<com.canal;
}

