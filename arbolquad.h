
#ifndef ARBOLQUAD_H
#define ARBOLQUAD_H
#include "punto.h"
#include "nodoquad.h"
#include "fruta.h"


template <class T>
class ArbolQuad
{
private:
    NodoQuad<T> *raiz;

public:
    ArbolQuad();
    bool insertar(T val);
    ~ArbolQuad();
    Punto datoRaiz();
    NodoQuad<T> *obtenerRaiz();
    void fijarRaiz(NodoQuad<T> *n_raiz);
    NodoQuad<T> *buscarNodo(Punto val);
    void preorden(NodoQuad<T> *nodo);
    bool esVacio();
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
   
};
#include "arbolquad.hxx"
#endif // ARBOLQUAD.H
