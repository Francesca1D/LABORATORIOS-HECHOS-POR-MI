//
// Created by USER on 24/06/2026.
//

#include "Multa.h"

#include <iomanip>

Multa::Multa() {
    fecha=0;
    multa=0;
    pagada=false;
    fechaDePago=0;
}



int Multa::get_fecha() const {
    return fecha;
}

void Multa::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Multa::get_placa() const {
    return placa;
}

void Multa::set_placa(const string &placa) {
    this->placa = placa;
}

string Multa::get_cod_multa() const {
    return codMulta;
}

void Multa::set_cod_multa(const string &cod_multa) {
    codMulta = cod_multa;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}

bool Multa::is_pagada() const {
    return pagada;
}

void Multa::set_pagada(bool pagada) {
    this->pagada = pagada;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}
// 1/12/2020,G760-721,G2022,N
// 23/07/2023,P474-593,G2060,P,22/08/2023
// 18/12/2024,G938-342,G2061,P,26/01/2025
// 6/08/2021,P863-768,G2025,N




void Multa::leeMulta(ifstream &arch, int dd) {
    int mm,aa;
    char c;
    arch>>c>>mm;
    if (arch.eof()) return;
    arch>>c>>aa>>c;
    getline(arch,placa,',');
    getline(arch,codMulta,',');
    fecha= dd+mm*100+aa*10000;
    arch>>c;
    if (c=='N')
        pagada=false;
    else pagada=true;
    if (pagada) {
        arch>>c>>dd>>c>>mm>>c>>aa;
        fechaDePago= dd+mm*100+aa*10000;
    }
}

void Multa::operator >>(ifstream &arch) {
    int dd,mm,aa;
    char c;
    arch>>dd;
    if (arch.eof()) return;
    arch>>c>>mm>>c>>aa>>c;
    getline(arch,placa,',');
    getline(arch,codMulta,',');
    fecha= dd+mm*100+aa*10000;
    arch>>c;
    if (c=='N')
        pagada=false;
    else pagada=true;
    if (pagada) {
        arch>>c>>dd>>c>>mm>>c>>aa;
        fechaDePago= dd+mm*100+aa*10000;
    }
}
// int fecha;
// string placa;
// string codMulta;
// double multa;
// bool pagada;
// int fechaDePago;
// void Multa::agregarMulta(Infraccion tablaInfracciones) {
//
// }

// void Multa::imprimirMultas(ofstream &arch) {
//     int dd,mm,aa;
//     dd=fecha%100;
//     mm=(fecha%10000)/100;
//     aa=fecha/10000;
//     arch<<left<<setw(15)<<placa<<right<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<setfill(' ')<<setw(23)<<codMulta<<setw(12)<<
//             setprecision(2)<<fixed<<multa;
//     if (pagada) {
//         arch<<setw(8)<<' '<<left<<setw(5)<<"SI";
//         dd=fechaDePago%100;
//         mm=(fechaDePago%10000)/100;
//         aa=fechaDePago/10000;
//         arch<<setw(3)<<' '<<right<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<setfill(' ')<<setw(20)<<endl;
//     }else arch<<setw(8)<<' '<<left<<setw(5)<<"NO"<<endl;
//
// }

//operator >>(
void Multa::operator<<(ofstream &arch) {
    int dd,mm,aa;
    dd=fecha%100;
    mm=(fecha%10000)/100;
    aa=fecha/10000;
    arch<<left<<setw(15)<<placa<<right<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<setfill(' ')<<setw(23)<<codMulta<<setw(12)<<
            setprecision(2)<<fixed<<multa;
    if (pagada) {
        arch<<setw(8)<<' '<<left<<setw(5)<<"SI";
        dd=fechaDePago%100;
        mm=(fechaDePago%10000)/100;
        aa=fechaDePago/10000;
        arch<<setw(3)<<' '<<right<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<setfill(' ')<<setw(20)<<endl;
    }else arch<<setw(8)<<' '<<left<<setw(5)<<"NO"<<endl;

}

// 20201701
// fecha%100
// fecha%10000)/100

bool Multa::operator <(Multa &mul) const {
    return fecha>mul.fecha;
}
