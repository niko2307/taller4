#ifndef ARBOLKD_H
#define ARBOLKD_H
#include "punto.h"
#include "nodokd.h"


class ArbolKD {
protected:
NodoKD* raiz;


public:
ArbolKD();
ArbolKD(Punto val);
~ArbolKD();
Punto datoRaiz();
NodoKD* obtenerRaiz();
void fijarRaiz(NodoKD* n_raiz);
bool esVacio();
bool insertar(Punto val);
void preOrden();
void inOrden();
void posOrden();
void nivelOrden();

};
#include"arbolkd.hxx"

#endif//ARBOLKD_H

