#include "arbolquad.h"
#include "fruta.h"

template <class T>
bool ArbolQuad<T>::esVacio() {
    return raiz == NULL;
}

template <class T>
NodoQuad<T>* ArbolQuad<T>::obtenerRaiz() {
    return raiz;
}

template <class T>
void ArbolQuad<T>::fijarRaiz(NodoQuad<T>* n_raiz) {
    raiz = n_raiz;
}


template <class T>
Punto ArbolQuad<T>::datoRaiz() {
    if (raiz) {
        int x = *(raiz->obtenerx());
        int y = *(raiz->obtenery());

        return Punto(x, y);
    } else {
        
        return Punto(0, 0);
    }
}

template <class T>
ArbolQuad<T>::~ArbolQuad() {  
}

template <class T>
ArbolQuad<T>::ArbolQuad() {
    this -> raiz=NULL;
}


template <class T>
bool ArbolQuad<T>:: insertar(Fruta &fruta){
  if (raiz == NULL) {
            raiz = new NodoQuad<T>(fruta);
            return true; //se logro insertar correctamente 
        }else{
             return raiz->insertar(fruta);
        }
    
 }

 

