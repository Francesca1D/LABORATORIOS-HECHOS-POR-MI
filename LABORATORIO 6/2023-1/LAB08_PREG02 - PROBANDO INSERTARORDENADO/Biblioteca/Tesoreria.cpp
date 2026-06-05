//
// Created by USER on 5/06/2026.
//

#include "Tesoreria.h"

Tesoreria::Tesoreria() {
    lvirtual == nullptr;
}

Tesoreria:: ~Tesoreria() {
    if (lvirtual!= nullptr)
        delete [] lvirtual;
}

void Tesoreria::cargaescalas() {
    int escala;
    double prec;
    char c;
    ifstream arch("ArchivosDeEntrada/escalas.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo de escalas.csv"<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        arch>>escala;
        if (arch.eof()) break;
        lescala[i].set_codigo(escala);
        arch>>c>>prec;
        lescala[i].set_precio(prec);
        i++;
    }

}



void Tesoreria::cargaalumnos() {
    char tipo,c;
    int cant_presencial=0,cant_semipresencial=0,cant_virtual=0;
    ifstream arch("ArchivosDeEntrada/Alumnos.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo de Alumnos.csv"<<endl;
        exit(1);
    }
    Presencial aux;
    while (true) {
        arch>>tipo;
        if (arch.eof()) break;
        arch>>c;
        if (tipo == 'P') {
            aux.leePresencial(arch);
            int posP = buscarPos(aux, cant_presencial);
            for (int i = cant_presencial; i > posP; i--)
                lpresencial[i] = lpresencial[i - 1];
            lpresencial[posP]= aux;
            cant_presencial++;
        }
        if (tipo == 'S') {
            lsemipresencial[cant_semipresencial].leeSemipresencial(arch);
            cant_semipresencial++;
        }
        if (tipo == 'V') {
            if (cant_virtual==0) {
                lvirtual = new Virtual[30];

            }
            lvirtual[cant_virtual].leeVirtual(arch);
            cant_virtual++;

        }
    }
    recorte();
}
int Tesoreria::buscarPos(Presencial aux, int cant_presencial) {
    int i=0;
    for (i=0;i<cant_presencial;i++) {
        if (lpresencial[i].get_codigo()<aux.get_codigo()) return i;
    }
    return i;
}
void Tesoreria::actualiza(int cred) {

}

void Tesoreria::imprime() {
    ofstream arch("ArchivosDeSalida/ReporteEscala.txt", ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo de ReporteEscala.txt"<<endl;
        exit(1);
    }
    for (int i=0;  i<lescala[i].get_precio()!=0 ;i++) {
        arch << right << setw(4) << lescala[i].get_codigo() << setw(8) << setprecision(2) << fixed << lescala[i].
                get_precio() << endl;
    }
    arch<<setw(50)<<left<<"Codigo     Nombre"<<"Escala    Licencia        Total"<<endl;
    for (int i=0; i<lpresencial[i].get_codigo();i++) {
        lpresencial[i].imprimePresencial(arch);
    }
    for (int i=0; i<lsemipresencial[i].get_codigo();i++) {
        lsemipresencial[i].imprimeSemipresencial(arch);
    }
    for (int i=0; i<lvirtual[i].get_codigo();i++) {
        lvirtual[i].imprimeVirtual(arch);
    }

}

void Tesoreria::recorte() {
    int n= cuentaVirtuales();
    Virtual *aux = new Virtual[n+1];
    if (not isnull()) {
        for (int i=0; i<n;i++) {
            aux[i]= lvirtual[i];
        }
        delete [] lvirtual;
        lvirtual= aux;
    }
}

bool Tesoreria::isnull() {
    if (lvirtual==nullptr) return true;
    else return false;
}

// int Tesoreria::cuentaVirtual() {
//     // char cad[20];
//     // if (lvirtual!= nullptr) {
//     //     int i;
//     //
//     //
//     //     // for (i=0; lvirtual[i].get_codigo()!=0;i++);
//     //     // for (i=0; strcmp(lvirtual[i].get_licencia(cad), nullptr)!=0;i++);
//     //     return i;
//     //
// }

int Tesoreria::cuentaVirtuales() {
    if (not isnull()) {
        int i;
        for (i=0; lvirtual[i].get_codigo()!=0;i++);
        return i;
    }
    return 0;
}