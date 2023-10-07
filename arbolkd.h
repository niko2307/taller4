#ifndef ARBOLKD_H
#define ARBOLKD_H

#include "punto.h"
#include "nodokd.h"
#include "fruta.h"

template <class T>

class ArbolKD {
protected:
NodoKD<T>* raiz;

public:
ArbolKD();
ArbolKD(Punto val);
~ArbolKD();
Punto datoRaiz();
NodoKD<T>* obtenerRaiz();
void fijarRaiz(NodoKD<T>* n_raiz);
bool esVacio();
void preorden(NodoKD<T> *nodo);
void preOrden();
NodoKD<T> *buscarNodoKD(double x, int y);
NodoKD<T> *buscarNodoKD(Punto val);
void inOrden();
void posOrden();
void nivelOrden();
bool insert(T dato);




};
#include"arbolkd.hxx"

#endif//ARBOLKD_H


