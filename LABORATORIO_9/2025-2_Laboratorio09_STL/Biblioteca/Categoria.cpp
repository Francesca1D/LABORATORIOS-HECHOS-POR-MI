//
// Created by USER on 25/06/2026.
//

#include "Categoria.h"

Categoria::Categoria(){

}

Categoria:: ~Categoria(){

}

Categoria::Categoria(const Categoria& orig){
    *this = orig;
}

string Categoria::get_codigo() const {
    return codigo;
}

void Categoria::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Categoria::get_nombre() const {
    return nombre;
}

void Categoria::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

string Categoria::get_descripcion() const {
    return descripcion;
}

void Categoria::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

void Categoria::operator =(const Categoria& orig){
    codigo= orig.codigo;
    nombre= orig.nombre;
    descripcion= orig.descripcion;
}

// UM1000,Just Chatting,Casual conversations; reactions; and hangouts without a main game.
// DN1001,League of Legends,5v5 MOBA; ranked climbs; pro play analysis; and coaching

void Categoria::operator >>(ifstream &arch){
    getline(arch,codigo,',');
    if (arch.eof())return;
    getline(arch,nombre,',');
    getline(arch,descripcion,'\n');

}

void Categoria::operator <<(ofstream &arch){
    arch<<codigo<<" "<<nombre<<" "<<descripcion<<endl;
}
