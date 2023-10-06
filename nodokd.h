#ifndef NODOKD_H
#define NODOKD_H
#include "punto.h"

template <class T>
class NodoKD {
    
protected:
Punto dato;
NodoKD<T>* hijoIzq;
NodoKD<T>* hijoDer;

public:
NodoKD();
NodoKD(Punto val);
~NodoKD();
bool esHoja(int depth);
Punto obtenerDato();
void fijarDato(Punto val);

NodoKD<T> *obtenerHijoIzq();
NodoKD<T>* obtenerHijoDer();
void fijarHijoIzq(NodoKD<T>* izq);
void fijarHijoDer(NodoKD<T>* der);



};
#include "nodokd.hxx"

#endif // NODOKD_H
