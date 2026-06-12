//
// Created by USER on 11/06/2026.
//

#ifndef PREG01_LAB08_2024_2_DETALLECOMANDA_H
#define PREG01_LAB08_2024_2_DETALLECOMANDA_H
#include "Producto.h"


class DetalleComanda {
private:
    int id;
    Producto *pedido;
public:
    DetalleComanda();
    virtual ~DetalleComanda();
    int get_id() const;
    void set_id(int id);
    void leecomandas(ifstream &arch);
    void imprime(ofstream &arch);


};


#endif //PREG01_LAB08_2024_2_DETALLECOMANDA_H
