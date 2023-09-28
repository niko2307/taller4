#include "nodoquad.h"
template <class T>
NodoQuad<T>::NodoQuad(Punto val){
dato= val;
 hijoSupIzq=NULL;
 hijoSupDer=NULL; 
 hijoInfIzq=NULL; 
 hijoInfDer=NULL;

}
template <class T>
NodoQuad<T>::NodoQuad(){
 hijoSupIzq=NULL;
 hijoSupDer=NULL; 
 hijoInfIzq=NULL; 
 hijoInfDer=NULL;
}

template <class T>
 bool NodoQuad<T>::esHoja(){
     if (hijoSupIzq == NULL && hijoSupDer == NULL &&hijoInfIzq==NULL &&hijoInfDer==NULL)
        return true;
    else
       return false;   
 }

template <class T>
Punto NodoQuad<T>::obtenerDato(){
    return dato;
}

template <class T>
void NodoQuad<T>::fijarDato(Punto val){
    dato=val;

}

template <class T>
NodoQuad<T> *NodoQuad<T>::obtenerHijoInfDer(){
    return hijoInfDer;
}

template <class T>
NodoQuad<T> *NodoQuad<T>::obtenerHijoInfIzq(){
    return hijoInfIzq;
}
template <class T>
NodoQuad<T> *NodoQuad<T>::obtenerHijoSupDer(){
    return hijoInfDer;
}
template <class T>
NodoQuad<T> *NodoQuad<T>::obtenerHijoSupIzq(){
    return hijoSupIzq;
}



template <class T>
void NodoQuad<T>:: fijarHijoSupIzq(NodoQuad* sizq){
      hijoSupIzq = sizq;

}
template <class T>
void NodoQuad<T>::fijarHijoSupDer(NodoQuad* sder) {
      hijoSupDer = sder;

}
template <class T>
void NodoQuad<T>:: fijarHijoInfIzq(NodoQuad* iizq){
     hijoInfIzq = iizq;


}
template <class T>
void NodoQuad<T>::fijarHijoInfDer(NodoQuad* ider) {
      hijoInfDer = ider;

}



