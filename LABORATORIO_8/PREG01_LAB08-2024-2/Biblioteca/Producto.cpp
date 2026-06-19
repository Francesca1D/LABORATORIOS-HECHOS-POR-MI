//
// Created by USER on 18/06/2026.
//

#include "Producto.h"

#include <cstring>

Producto::Producto() {
    nombre=nullptr;
    precio=0;
}

Producto:: ~Producto(){
    if (nombre!=nullptr) delete nombre;

}


double Producto::get_precio() const {
    return precio;
}

void Producto::set_precio(double precio) {
    this->precio = precio;
}


void Producto::get_nombre(char *cad){
    if (nombre==nullptr) cad[0] = '\0';
    else strcpy(cad, nombre);
}

void Producto::set_nombre(const char *cad){
    if (nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Producto::lee(ifstream &arch) {
    char cad[100], c;
    arch.getline(cad, 100,',');
    set_nombre(cad);
    arch>>precio>>c;
}

void Producto::imprime(ofstream &arch) {
    arch<<setw(5)<<" "<<"Nombre: "<<nombre<<endl;
    arch<<setprecision(2)<<fixed<<setw(5)<<" "<<"Precio: "<<precio<<endl;
}
