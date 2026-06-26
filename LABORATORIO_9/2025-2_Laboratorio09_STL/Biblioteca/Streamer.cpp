//
// Created by USER on 25/06/2026.
//

#include "Streamer.h"

#include <iomanip>

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


// string canal;
// int fecha;
// Categoria categoria;
// string etiquetasStr;
// vector<class Etiqueta> etiquetasVector;
// string idioma;

// vector<class Etiqueta> etiquetasVector;


// summit1g,12/11/2021,MK1092,HTR108-UPK123-SWT139-LWC105,English
// Gaules,15/02/2022,CY1025,KRH188-BBY119,Portuguese
// ESL_CSGO,16/11/2023,DQ1021,UFK146-CUV131-EHZ179,English

void Streamer::operator >>(ifstream &arch) {
    int dd,mm,aa;
    char c,guion, etiqueta[7];
    string cat;
    getline(arch,canal,',');
    if (arch.eof())return;;
    arch>>dd>>c>>mm>>c>>aa>>c;
    fecha = dd+mm*100+aa*10000;
    getline(arch,cat,',');
    categoria.set_codigo(cat);

    getline(arch,etiquetasStr,',');
    int i=0;
    for (int j=0;etiquetasStr[j]!='\0';) {
        Etiqueta aux;
        for (i=0; i<6;i++,j++) {
            etiqueta[i]= etiquetasStr[j];
        }
        etiqueta[i]='\0';
        if (etiquetasStr[j]=='-') j++;

        aux.set_codigo(etiqueta);
        etiquetasVector.push_back(aux);
    }

    getline(arch, idioma,'\n');

}

// MK1092,HTR108-UPK123-SWT139-LWC105



// Categoria categoria;
void Streamer::operator <<(ofstream &arch){
    int dd,mm,aa;
    dd= fecha%100;
    mm= (fecha%10000)/100;
    aa= fecha/10000;
    arch<<"CANAL: "<<canal<<endl;
    arch<<"FECHA: "<<setfill('0')<<setw(2)<<right<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<setfill(' ')<<endl;
    arch<<"LENGUAJE: "<<idioma<<endl;
    arch<<"CATEGORIA:"<<endl;
    categoria<<arch;
    arch<<"ETIQUETAS STR: "<<etiquetasStr<<endl;
    // for (vector<class Etiqueta> ::iterator itV= etiquetasVector.begin();itV!=etiquetasVector.end();itV++) {
    //     *itV<<arch;
    // }
    for (int i=0;i<etiquetasVector.size();i++) {
        arch<<setw(3)<<' '<<i+1<<") ";
        etiquetasVector[i]<<arch;
    }
    arch<<"COMENTARIOS:"<<endl;
    // for (int i=0;i<coment.size();i++) {
    //     arch<<setw(3)<<' '<<i+1<<") ";
    //     arch<<coment[i]<<endl;
    // }

    //vector<string> coment;
    int i=0;
    for (vector<string> ::iterator it=coment.begin(); it!=coment.end(); it++ ) {
        arch<<setw(3)<<' '<<i+1<<") ";
        i++;
        arch<<*it;
        arch<<endl;
    }
}

//vector<class Etiqueta> etiquetasVector;

bool Streamer::operator <(const Streamer &st) const {
    if (categoria.get_codigo() == st.categoria.get_codigo())
        return fecha < st.fecha;
    return categoria< st.categoria;
}

void Streamer::buscaryAsignarCategoria(list<class Categoria> categorias) {
    for (list<class Categoria> ::iterator it=categorias.begin(); it!=categorias.end(); it++) {
        if (categoria.get_codigo()==it->get_codigo()) {
            categoria.set_nombre(it->get_nombre());
            categoria.set_descripcion(it->get_descripcion());
            break;
        }

    }
}

// vector<class Etiqueta> etiquetasVector;
void Streamer::buscarYAsignarEtiqueta(map<string, class Etiqueta, less<string>> etiquetas) {
    for (int i = 0; i < etiquetasVector.size(); i++) {
        for (map<string, class Etiqueta, less<string> >::iterator it = etiquetas.begin(); it != etiquetas.end(); it++) {
            if (it->first == etiquetasVector[i].get_codigo()) {
                etiquetasVector[i].set_nombre(it->second.get_nombre());
                break;
            }
        }
    }

}

// list<class Comentario> comentarios;

void Streamer::buscarYAsignarComentarios(list<class Comentario>comentarios) {
    for (list<class Comentario>::iterator it=comentarios.begin(); it!=comentarios.end(); it++) {
        if (it->get_canal()==canal) {
            coment.push_back(it->get_comentario());
        }
    }
}

bool Streamer::isIdioma(string idi) {
    if (idi==idioma) {
        return true;
    }else return false;
}
