#ifndef ARBOLQUAD_H
#define ARBOLQUAD_H
#include "punto.h"
#include "nodoquad.h"

class ArbolQuad {
protected:
NodoQuad* raiz;

public:
ArbolQuad();
ArbolQuad(Punto val);
~ArbolQuad();
Punto datoRaiz();
NodoQuad* obtenerRaiz();
void fijarRaiz(NodoQuad* n_raiz);
bool esVacio();
bool insertar(Punto val);
void preOrden();
void inOrden();
void posOrden();
void nivelOrden();
};

#include "arbolquad.hxx"

#endif // ARBOLQUAD.H
