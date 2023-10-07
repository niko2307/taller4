#include <cmath>
#include "arbolkd.h"



template <class T>
bool ArbolKD<T>::insert(T dato) {
    NodoKD<T>* padre = this->raiz;
    NodoKD<T>* nodo = this->raiz;
    bool insertado = false;
    bool duplicado = false;
    int dimension = 1;

    if (this->esVacio()) {
        NodoKD<T>* raiz = new NodoKD<T>(dato);
        this->raiz = raiz;
        insertado = true;
    } else {
        while (padre != nullptr) {
            nodo = padre;

            if (padre->obtenerDato().obtenerx() == dato.obtenerx() && padre->obtenerDato().obtenery() == dato.obtenery()) {
                duplicado = true;
                break;
            }

            if (dimension % 2 != 0) { 
                if (dato.obtenerx() <= padre->obtenerDato().obtenerx()) {
                    padre = padre->obtenerHijoIzq();
                } else {
                    padre = padre->obtenerHijoDer();
                }
                dimension++;
            } else { 
                if (dato.obtenery() <= padre->obtenerDato().obtenery()) {
                    padre = padre->obtenerHijoIzq();
                } else {
                    padre = padre->obtenerHijoDer();
                }
                dimension++;
            }
        }

        dimension--;

        if (nodo != nullptr && !duplicado) {
            NodoKD<T>* nuevo = new NodoKD<T>(dato);

            if (dimension % 2 != 0) { // Dimensión x
                if (dato.obtenerx() <= nodo->obtenerDato().obtenerx() && nodo->obtenerHijoIzq() == nullptr) {
                    nodo->fijarHijoIzq(nuevo);
                } else if (dato.obtenerx() > nodo->obtenerDato().obtenerx() && nodo->obtenerHijoDer() == nullptr) {
                    nodo->fijarHijoDer(nuevo);
                }
                insertado = true;
            } else { // Dimensión y
                if (dato.obtenery() <= nodo->obtenerDato().obtenery() && nodo->obtenerHijoIzq() == nullptr) {
                    nodo->fijarHijoIzq(nuevo);
                } else if (dato.obtenery() > nodo->obtenerDato().obtenery() && nodo->obtenerHijoIzq() == nullptr) {
                    nodo->fijarHijoDer(nuevo);
                }
                insertado = true;
            }
        }
    }
    return insertado;
}
template <class T>
ArbolKD<T>::ArbolKD() {
    raiz = NULL;
}

template <class T>
ArbolKD<T>::ArbolKD(Punto val) {
    raiz = new NodoKD<T>(val);
}


template <class T>
ArbolKD<T>::~ArbolKD() {
   
}
template <class T>
Punto ArbolKD<T>::datoRaiz() {
    if (raiz != nullptr) {
        return raiz->valor();
    } else {
        
        return Punto(0, 0);
    }
}

template <class T>
NodoKD<T>* ArbolKD<T>::obtenerRaiz() {
    return raiz;
}

template <class T>
void ArbolKD<T>::fijarRaiz(NodoKD<T> *n_raiz) {
    raiz = n_raiz;
}

template <class T>
bool ArbolKD<T>::esVacio() {
    return raiz == NULL;
}


template <class T>
void ArbolKD<T>::preorden(NodoKD<T>* nodo) {
    if (nodo == nullptr) {
        return;
    }

   std::cout<< nodo->obtenerDato().obtenernombre();
    
   
    preorden(nodo->obtenerHijoIzq());

    
    preorden(nodo->obtenerHijoDer());
}


template <class T>
void ArbolKD<T>::preOrden() {
    preorden(this->raiz);
}

template <class T>
NodoKD<T>* ArbolKD<T>::buscar(Punto val) {
    NodoKD<T>* nodo = this->raiz;
    Punto P;
    bool comparaX = true; 

    while (nodo != nullptr) {
        P = nodo->obtenerDato();
        
        if (val.obtenerx() == P.obtenerx() && val.obtenery() == P.obtenery()) {
            return nodo;
        } else {
            // Alternamos entre X e Y
            comparaX = !comparaX;

            if (comparaX) {
                if (val.obtenerx() <= P.obtenerx())
                    nodo = nodo->obtenerHijoIzq();
                else
                    nodo = nodo->obtenerHijoDer();
            } else {
                if (val.obtenery() <= P.obtenery())
                    nodo = nodo->obtenerHijoIzq();
                else
                    nodo = nodo->obtenerHijoDer();
            }
        }
    }
    return nullptr;
}
