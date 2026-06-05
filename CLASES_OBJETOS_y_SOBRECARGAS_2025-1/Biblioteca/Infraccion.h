//
// Created by USER on 13/05/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_INFRACCION_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_INFRACCION_H
#include <fstream>

using namespace std;

class Infraccion {
public:
    Infraccion();
    virtual ~Infraccion();
    Infraccion(Infraccion &);
    int get_codigo() const;
    void set_codigo(int codigo);
    double get_multa() const;
    void set_multa(double multa);
    void get_descripcion(char *cad);
    void set_descripcion(const char *cad);
    void get_gravedad(char *cad);
    void set_gravedad(const char *cad);
    void operator=(Infraccion &);
private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
};

void operator>>(ifstream &, Infraccion &);
// void operator<<(ofstream &, Infraccion &);

ofstream &operator<<(ofstream &, Infraccion &);
#endif //CLASES_OBJETOS_Y_SOBRECARGAS_INFRACCION_H
