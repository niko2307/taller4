#ifndef NODOKD_H
#define NODOKD_H
#include "punto.h"

template <typename T>
class NodoKD {
    
protected:
Punto dato;
NodoKD* hijoIzq;
NodoKD* hijoDer;

public:
NodoKD();
NodoKD(Punto val);
~NodoKD();
bool esHoja();
Punto obtenerDato();
void fijarDato(Punto val);
NodoKD* obtenerHijoIzq();
NodoKD* obtenerHijoDer();
void fijarHijoIzq(NodoKD* izq);
void fijarHijoDer(NodoKD* der);

};

#endif // NODOKD_H
