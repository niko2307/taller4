#ifndef NODOKD_H
#define NODOKD_H
#include "punto.h"

template <class T>
class NodoKD
{
private:
    Punto dato;
    NodoKD *hijoIzq;
    NodoKD *hijoDer;

public:
    NodoKD();
    NodoKD(Punto val);
    ~NodoKD();
    bool esHoja();
    Punto obtenerDato();
    void fijarDato(Punto val);
    NodoKD<T> *obtenerHijoIzq();
    NodoKD<T> *obtenerHijoDer();
    void fijarHijoIzq(NodoKD<T> *izq);
    void fijarHijoDer(NodoKD<T> *der);
};

#endif // NODOKD_H
