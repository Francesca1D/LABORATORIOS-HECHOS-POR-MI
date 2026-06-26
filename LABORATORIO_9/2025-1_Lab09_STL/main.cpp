// Francesca Condor, 20176818


// #include <iostream>
// #include <list>
// #include <map>
// #include <algorithm>
// #include <vector>

#include "Biblioteca/MinisterioDeTransporte.h"

using namespace std;

// struct alunotas {
//     int codigo;
//     int notas[10];
// };

int main() {
    MinisterioDeTransporte min;

    min.cargaDeInfracciones("ArchivosDeEntrada/TablaDeInfracciones.csv");
    min.cargaEmpresas("ArchivosDeEntrada/EmpresasRegistradas.csv");
    min.cargaVehiculos("ArchivosDeEntrada/VehiculosRegistrados.csv");
    min.cargaInfraccionesCometidas("ArchivosDeEntrada/InfraccionesCometidas.csv");
    min.reporteDeEmpresasConInfracciones("ArchivosDeSalida/Reporte4.txt");
    min.eliminaInfraccionesPagadas();
    min.reporteDeEmpresasConInfracciones("ArchivosDeSalida/ReporteSinMultasPagadas2.txt");

    return 0;
}
//ArchivosDeSalida

/*
 *int notas[]={11,5,14,20,16};
    int n = sizeof(notas)/sizeof(notas[0]);
    // ////////////////////////////////
    // ///            VECTOR
    // /////////////////////////////////
    vector<int> vnotas;

    // cout<< vnotas.size() <<endl;

    vnotas.insert(vnotas.begin(), notas, notas+n);
    // cout<< vnotas.size() <<endl;
    vnotas.push_back(20);
    // cout<< vnotas.size() <<endl;
    vnotas.erase(vnotas.begin()+1);
    // cout<< vnotas.size() <<endl;

    // for (int i=0; i<vnotas.size();i++)
    //     cout<< vnotas[i] << " ";
    ////////////////////////////////
    ///             LIST
    /////////////////////////////////

    // list<int>lnotas;
    // for (int i=0; i<n; i++)
    //     lnotas.push_back(notas[i]);
    // // for (int i=0; i<n; i++)
    // //     lnotas.push_back(vnotas[i]);
    // cout<<endl<< "Ahora imprimo lista"<<endl;
    // for (list<int>::iterator it= lnotas.begin(); it!= lnotas.end(); ++it)
    //     cout<<*it<<" ";

    ////////////////////////////////
    ///             MAP
    /////////////////////////////////
    alunotas registro[] {
        {20221918, {9,19,8,10,2}},{20240929,{12,13,9,10,3}},
        {20230817,{4,5,12,13,18}}};
    int m= sizeof(registro)/sizeof(registro[0]);

    map<int,double>mnotas;

    for (int i=0; i<m;i++) {
        double prom;
        int sum=0;
        for (int j=0; j<5; j++)
            sum+= registro[i].notas[j];
        prom = sum/5;
        mnotas[registro[i].codigo]=prom;
    }
    cout<<endl;
    // cout<<endl<< "Ahora imprimo map"<<endl;
    // for (map<int,double>::iterator it= mnotas.begin(); it!= mnotas.end();it++)
    //     cout<<it->first<<" "<<it->second<<endl;

    map<int, vector<int>> mvnotas;
    // for (int i=0; i<vnotas.size();i++)
    //     cout<< vnotas[i] << " ";

    for (int i=0; i<m;i++) {
        vnotas.clear();
        vnotas.insert(vnotas.begin(), registro[i].notas, registro[i].notas+5);
        mvnotas[registro[i].codigo] = vnotas;

    }
    cout << endl;

    // for (int i=0; i<vnotas.size();i++)
    //     cout<< vnotas[i] << " ";

    for (map<int, vector<int>>::iterator it = mvnotas.begin(); it != mvnotas.end(); it++) {
        cout << it->first << ": ";
        for (int j=0; j<it->second.size(); j++)
            cout<< it->second[j]<<" ";
        cout << endl;
    }
    cout << endl;
 */