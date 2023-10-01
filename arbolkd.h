#ifndef ARBOLKD_H
#define ARBOLKD_H
#include "punto.h"
#include "nodokd.h"

template <class T>

class ArbolKD
{
private:
    NodoKD<T> *raiz;

public:
    ArbolKD();
    ArbolKD(Punto val);
    ~ArbolKD();
    Punto datoRaiz();
    NodoKD<T> *obtenerRaiz();
    void fijarRaiz(NodoKD<T> *n_raiz);
    bool esVacio();
    bool insert(T &val);
    NodoKD<T> insertRec(NodoKD<T> *&root, Punto p, int depth = 0);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};
#include "arbolkd.hxx"

#endif // ARBOLKD_H
