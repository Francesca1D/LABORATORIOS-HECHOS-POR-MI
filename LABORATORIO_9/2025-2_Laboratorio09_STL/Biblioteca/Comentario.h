//
// Created by USER on 25/06/2026.
//

#ifndef INC_2025_2_LABORATORIO09_STL_COMENTARIO_H
#define INC_2025_2_LABORATORIO09_STL_COMENTARIO_H
#include <string>
#include <fstream>

using namespace std;

class Comentario {
private:
    string canal;
    string comentario;

public:
    Comentario();
    virtual ~Comentario();
    Comentario(const Comentario &orig);

    string get_canal() const;
    void set_canal(const string &canal);
    string get_comentario() const;
    void set_comentario(const string &comentario);

    void operator=(const Comentario &orig);
    void operator >>(ifstream &arch);
    void operator <<(ofstream &arch);
    bool operator <(const Comentario &com) const;

};


#endif //INC_2025_2_LABORATORIO09_STL_COMENTARIO_H
