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
void preOrden();
void inOrden();
void posOrden();
void nivelOrden();
bool insert(T &val);
NodoKD<T>* insertRec(NodoKD<T> *root, Punto p, int depth);

std::string buscarFruta(NodoKD<T>* nodo, double peso, int color, double& distanciaMinima);
std::string buscarFruta(double peso, int color);
 double calcularDistancia(double x1, int y1, double x2, int y2);

int obtenerProfundidad(NodoKD<T>* nodo);


};
#include"arbolkd.hxx"

#endif//ARBOLKD_H

