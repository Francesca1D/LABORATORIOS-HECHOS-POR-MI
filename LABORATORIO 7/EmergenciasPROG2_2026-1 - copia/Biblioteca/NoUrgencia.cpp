//
// Created by USER on 16/06/2026.
//

#include "NoUrgencia.h"

NoUrgencia::NoUrgencia(){
    especialidad= nullptr;
    es_consulta_programada=false;
}

NoUrgencia:: ~NoUrgencia(){
    if (especialidad!= nullptr) delete especialidad;

}

bool NoUrgencia::is_es_consulta_programada() const {
    return es_consulta_programada;
}

void NoUrgencia::set_es_consulta_programada(bool es_consulta_programada) {
    this->es_consulta_programada = es_consulta_programada;
}

void NoUrgencia::get_especialidad(char *cad){
    if (especialidad == nullptr) cad[0]='\0';
    else strcpy(cad,especialidad);
}

void NoUrgencia::set_especialidad(const char *cad){
    if (especialidad!= nullptr) delete especialidad;
    especialidad= new char[strlen(cad)+1];
    strcpy(especialidad,cad);
}

// 3,2018,Carolina Espinoza,Evaluacion Oftalmologica,Otorrinolaringologia,0


void NoUrgencia::lee(ifstream &arch) {
    Atencion::lee(arch);
    char c,cad[50];
    arch.getline(cad,50,',');
    set_especialidad(cad);
    arch>>es_consulta_programada;
}
