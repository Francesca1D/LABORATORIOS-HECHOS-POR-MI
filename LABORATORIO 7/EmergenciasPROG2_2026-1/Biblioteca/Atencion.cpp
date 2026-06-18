//
// Created by USER on 16/06/2026.
//

#include "Atencion.h"

Atencion::Atencion(){
    codigo=0;
    paciente= nullptr;
    descripcion= nullptr;
    hora=0;
}

Atencion:: ~Atencion(){
    cout << "Entrando destructor Atencion" << endl;
    if (paciente!= nullptr) delete paciente;
    if (descripcion!= nullptr) delete descripcion;

}

int Atencion::get_codigo() const {
    return codigo;
}

void Atencion::set_codigo(int codigo) {
    this->codigo = codigo;
}

int Atencion::get_hora() const {
    return hora;
}

void Atencion::set_hora(int hora) {
    this->hora = hora;
}

void Atencion::get_paciente(char *cad) {
    if (paciente == nullptr) cad[0]='\0';
    else strcpy(cad,paciente);
}

void Atencion::set_paciente(const char *cad){
    if (paciente!= nullptr) delete paciente;
    paciente= new char[strlen(cad)+1];
    strcpy(paciente,cad);
}

void Atencion::get_descripcion(char *cad){
    if (descripcion == nullptr) cad[0]='\0';
    else strcpy(cad,descripcion);
}

void Atencion::set_descripcion(const char *cad){
    if (descripcion!= nullptr) delete descripcion;
    descripcion= new char[strlen(cad)+1];
    strcpy(descripcion,cad);
}

// void Atencion::leeAtenciones(ifstream &arch) {
//
// }
// 1,2005,Renato Aguilar,Arritmia Grave,1,5
// 2,2006,Pedro Huaman,Herida en Mano,Rodilla,1
// 1,2007,Sofia Rojas,Accidente Vehicular Grave,0,0

void Atencion::lee(ifstream &arch) {
    char c, cad[100];
    arch>>codigo>>c;
    arch.getline(cad,100,',');
    set_paciente(cad);
    arch.getline(cad,100,',');
    set_descripcion(cad);

}

void Atencion::imprimir(ofstream &arch) {
    arch<<right<<setw(5)<<codigo<<"  ";
    arch<<left<<setw(20)<<paciente;
    arch<<setw(27)<<descripcion;
    // arch<<"HORA: "<<hora<<endl;
}



