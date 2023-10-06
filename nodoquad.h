#ifndef NODOQUAD_H
#define NODOQUAD_H
#include "punto.h"
#include "fruta.h"

template <class T>
class NodoQuad{
private:
Punto dato; 
NodoQuad<T>* hijoSupIzq;
NodoQuad<T>* hijoSupDer; 
NodoQuad<T>* hijoInfIzq; 
NodoQuad<T>* hijoInfDer;
  public: 
NodoQuad();
NodoQuad(Punto val); 
~NodoQuad();
Punto obtenerDato(); 
void fijarDato(Punto val); 
NodoQuad<T>* obtenerHijoSupIzq(); 
NodoQuad<T>* obtenerHijoSupDer(); 
NodoQuad<T>* obtenerHijoInfIzq(); 
NodoQuad<T>* obtenerHijoInfDer(); 
void fijarHijoSupIzq(NodoQuad<T>* sizq); 
void  fijarHijoSupDer(NodoQuad<T>* sder); 
void fijarHijoInfIzq(NodoQuad<T>* iizq);
void fijarHijoInfDer(NodoQuad<T>* ider);
bool esHoja();
  
  
};
#include"nodoquad.hxx"
#endif // NODOQUAD.H
