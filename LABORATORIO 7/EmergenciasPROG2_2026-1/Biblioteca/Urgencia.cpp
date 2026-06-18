//
// Created by USER on 16/06/2026.
//

#include "Urgencia.h"

Urgencia::Urgencia(){
    zona_lesion= nullptr;
    necesita_rx=false;
}

Urgencia:: ~Urgencia(){
    if (zona_lesion!= nullptr) delete zona_lesion;
}

bool Urgencia::is_necesita_rx() const {
    return necesita_rx;
}

void Urgencia::set_necesita_rx(bool necesita_rx) {
    this->necesita_rx = necesita_rx;
}

void Urgencia::get_zona_lesion(char *cad){
    if (zona_lesion == nullptr) cad[0]='\0';
    else strcpy(cad,zona_lesion);
}

void Urgencia::set_zona_lesion(const char *cad){
    if (zona_lesion!= nullptr) delete zona_lesion;
    zona_lesion= new char[strlen(cad)+1];
    strcpy(zona_lesion,cad);
}
// 2,2006,Pedro Huaman,Herida en Mano,Rodilla,1

void Urgencia::lee(ifstream &arch) {
    Atencion::lee(arch);
    char c,cad[100];
    arch.getline(cad,100,',');
    set_zona_lesion(cad);
    arch>>necesita_rx;

}

void Urgencia::imprimir(ofstream &arch) {
    Atencion::imprimir(arch);
    arch<<left<<setw(20)<<zona_lesion;
    if (necesita_rx==true) arch<<"SI";
    else arch<<"NO";
    arch<<setw(3)<<" ";
    arch<< "Tiempo max: 30 min"<<endl;
}

int Urgencia::obtenerPrioridad() {
    return 2;
}