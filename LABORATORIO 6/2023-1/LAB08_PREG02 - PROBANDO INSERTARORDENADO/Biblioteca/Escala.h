//
// Created by USER on 5/06/2026.
//

#ifndef LAB08_PREG02_ESCALA_H
#define LAB08_PREG02_ESCALA_H


class Escala {
public:
    Escala();
    // virtual ~Escala();
    int get_codigo() const;
    void set_codigo(int codigo);
    double get_precio() const;
    void set_precio(double precio);

private:
    int codigo;
    double precio;
};


#endif //LAB08_PREG02_ESCALA_H
