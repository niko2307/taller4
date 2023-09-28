#include "nodokd.h"
template <class T>

NodoKD<T>::NodoKD(Punto val){
dato= val;
hijoIzq = NULL;
hijoDer=NULL;

}
template <class T>
NodoKD<T>::NodoKD(){
hijoIzq = NULL;
hijoDer=NULL;
}

template <class T>
 bool NodoKD<T>::esHoja(){
     if (hijoDer == NULL && hijoIzq == NULL)
        return true;
    else
       return false;   
 }

template <class T>
Punto NodoKD<T>::obtenerDato(){
    return dato;
}

template <class T>
void NodoKD<T>::fijarDato(Punto val){
    dato=val;

}

template <class T>
NodoKD<T> *NodoKD<T>::obtenerHijoDer(){
    return hijoDer;
}

template <class T>
NodoKD<T> *NodoKD<T>::obtenerHijoIzq(){
    return hijoIzq;
}

template <class T>
void NodoKD<T>:: fijarHijoDer(NodoKD* der){
      hijoDer =der;

}

template <class T>
void NodoKD<T>:: fijarHijoDer(NodoKD* izq){
      hijoIzq = izq;

}
