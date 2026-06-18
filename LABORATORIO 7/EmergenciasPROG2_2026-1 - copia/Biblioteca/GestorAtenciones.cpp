//
// Created by USER on 16/06/2026.
//

#include "GestorAtenciones.h"
#include "Emergencia.h"
#include "Urgencia.h"
#include "NoUrgencia.h"


GestorAtenciones::GestorAtenciones() {
    // atenciones=nullptr;
    cantidad_atenciones=0;
}

GestorAtenciones:: ~GestorAtenciones() {
    // if (atenciones!=nullptr) delete [] atenciones;
}

int GestorAtenciones::get_cantidad_atenciones() const {
    return cantidad_atenciones;
}

void GestorAtenciones::set_cantidad_atenciones(int cantidad_atenciones) {
    this->cantidad_atenciones = cantidad_atenciones;
}
// procesar_dia("2026-06-11");  or aux[i]!='\0'
void GestorAtenciones::procesar_dia(const char *fecha) {
    // char c,dd[3],mm[3],aa[5], *nombreArchivo;
    // int i=0,j=0,l=0, k=5, m=8;
    // for (i=0;i<4;i++)
    //     aa[i]=fecha[i];
    // aa[i]='\0';
    // for (j=0;j<2;j++,k++)
    //     mm[j]=fecha[k];
    // dd[j]='\0';
    // for (l=0;l<2;l++,m++)
    //     dd[l]=fecha[m];
    // dd[l]='\0';
    // nombreArchivo= new char[50];
    // strcpy(nombreArchivo,"ArchivosDeDatos");
    // strcat(nombreArchivo,"/");
    // strcat(nombreArchivo,aa);
    // strcat(nombreArchivo,"/");
    // strcat(nombreArchivo,mm);
    // strcat(nombreArchivo,"/");
    // strcat(nombreArchivo,dd);
    // strcat(nombreArchivo,"/");
    // for (int h=0; h<24;h++)
    //     cargarAtenciones(nombreArchivo,h);
}
// cout<<nombreArchivo<<endl;
//concateno el name y la hora y csv
void GestorAtenciones::construir_nombre_archivo(char *destino, const char *base, int hh) {
    strcpy(destino, base);

    char buffer_hh[10];
    sprintf(buffer_hh, "%02d", hh);

    strcat(destino, buffer_hh);
    strcat(destino, ".csv");
}

void GestorAtenciones::cargarAtenciones(const char *nombre_archivo) {
    char c;
    atenciones = new Atencion*[15];
    // construir_nombre_archivo(nombFinal,nombre_archivo,hora);
    // cout<<nombFinal<<endl;
    ifstream arch(nombre_archivo,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombre_archivo<<endl;
        exit(1);
    }
    char tipo;
    int tip;
    while (true) {
        arch>>tip;
        if (arch.eof()) break;
        arch>>c;
        if (tip==1) tipo = 'E';
        if (tip==2) tipo = 'U';
        if (tip==3) tipo = 'N';

        atenciones[cantidad_atenciones]= reservar_memoria_atencion(tipo,arch);
        // atenciones[cantidad_atenciones].lee(arch);
        atenciones[cantidad_atenciones]->set_hora(0);
        cantidad_atenciones++;
    }
}
//atenciones[cantidad_atenciones].leeAtenciones(arch);
// esto es si es dinamico incremental agregar_atencion(atenciones[cantidad_atenciones]);

//
// 1,2005,Renato Aguilar,Arritmia Grave,1,5
// 2,2006,Pedro Huaman,Herida en Mano,Rodilla,1
// 1,2007,Sofia Rojas,Accidente Vehicular Grave,0,0





Atencion * GestorAtenciones::reservar_memoria_atencion(char tipo, ifstream &arch) {
    Atencion *ate;
    if (tipo == 'E')
        ate = new Emergencia;
    if (tipo == 'U')
        ate = new Urgencia;
    if (tipo == 'N')
        ate = new NoUrgencia;
    // return atenciones;
    ate->lee(arch);
    return ate;
}

void GestorAtenciones::generar_reporte_diario(const char *nombre_reporte) {
    ofstream arch(nombre_reporte,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombre_reporte<<endl;
        exit(1);
    }
    //i<atenciones[cantidad_atenciones].get_hora()
    for (int i=0; i<cantidad_atenciones;i++);
        // atenciones[i].imprimirAtenciones(arch);
}

// void imprimirAtenciones(ofstream &arch,int h);
