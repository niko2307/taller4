#include <cmath> 
#include "arbolquad.h"

template <class T>
bool ArbolQuad<T>::esVacio()
{
    return this->raiz == NULL;
}

template <class T>
NodoQuad<T> *ArbolQuad<T>::obtenerRaiz()
{
    return this->raiz;
}

template <class T>
void ArbolQuad<T>::fijarRaiz(NodoQuad<T> *n_raiz)
{
    this->raiz = n_raiz;
}

template <class T>
ArbolQuad<T>::~ArbolQuad()
{
}

template <class T>
ArbolQuad<T>::ArbolQuad()
{
    this->raiz = nullptr;
}

template <class T>
bool ArbolQuad<T>::insertar(T dato)
{
    NodoQuad<T> *nodo = this->raiz;
    NodoQuad<T> *padre = this->raiz;
    bool insertado = false;
    bool duplicado = false;
    Punto P;

    if (this->raiz == nullptr)
    {
        this->raiz = new NodoQuad<T>(dato);
        insertado = true;
        return insertado;
    }

    while (nodo != NULL)
    {
        padre = nodo;
        P = nodo->obtenerDato();
        if (dato.obtenerx() <= P.obtenerx() && dato.obtenery() > P.obtenery())
        {
            nodo = nodo->obtenerHijoSupIzq();
        }
        else if (dato.obtenerx() > P.obtenerx() && dato.obtenery() > P.obtenery())
        {
            nodo = nodo->obtenerHijoSupDer();
        }
        else if (dato.obtenerx() <= P.obtenerx() && dato.obtenery() <= P.obtenery())
        {
            nodo = nodo->obtenerHijoInfIzq();
        }
        else if (dato.obtenerx() > P.obtenerx() && dato.obtenery() <= P.obtenery())
        {
            nodo = nodo->obtenerHijoInfDer();
        }
        if (dato.obtenerx() == P.obtenerx() && dato.obtenery() == P.obtenery())
        {
            duplicado = true;
        }
    }
    if (!duplicado)
    {
        NodoQuad<T> *nuevo = new NodoQuad<T>(dato);
        if (nuevo != NULL)
        {
            if (dato.obtenerx() <= P.obtenerx() && dato.obtenery() > P.obtenery())
            {
                padre->fijarHijoSupIzq(nuevo);
            }
            else if (dato.obtenerx() > P.obtenerx() && dato.obtenery() > P.obtenery())
            {
                padre->fijarHijoSupDer(nuevo);
            }
            else if (dato.obtenerx() <= P.obtenerx() && dato.obtenery() <= P.obtenery())
            {
                padre->fijarHijoInfIzq(nuevo);
            }
            else if (dato.obtenerx() > P.obtenerx() && dato.obtenery() <= P.obtenery())
            {
                padre->fijarHijoInfDer(nuevo);
            }
        }
        insertado = true;
    }
    return insertado;
}

template <class T>
NodoQuad<T>* ArbolQuad<T>::buscarNodo(Punto val) {
    NodoQuad<T>* nodo = this->raiz;
    Punto P;
    double distanciaMinima = 9999999; // Inicializar con un valor máximo
    NodoQuad<T>* nodoMasCercano = nullptr;

    while (nodo != nullptr) {
        P = nodo->obtenerDato();

        if (val.obtenerx() <= P.obtenerx() && val.obtenery() > P.obtenery()) {
            nodo = nodo->obtenerHijoSupIzq();
        } else if (val.obtenerx() > P.obtenerx() && val.obtenery() > P.obtenery()) {
            nodo = nodo->obtenerHijoSupDer();
        } else if (val.obtenerx() < P.obtenerx() && val.obtenery() <= P.obtenery()) {
            nodo = nodo->obtenerHijoInfIzq();
        } else if (val.obtenerx() > P.obtenerx() && val.obtenery() <= P.obtenery()) {
            nodo = nodo->obtenerHijoInfDer();
        } else if (val.obtenerx() == P.obtenerx() && val.obtenery() == P.obtenery()) {
            return nodo;
        }
        // Calcular la distancia euclidiana con los nodos circundantes
        if (nodo != nullptr) {
            double distancia = std::sqrt(std::pow(val.obtenerx() - P.obtenerx(), 2) + std::pow(val.obtenery() - P.obtenery(), 2));
            if (distancia < distanciaMinima) {
                distanciaMinima = distancia;
                nodoMasCercano = nodo;
            }
        }
    }

    return nodoMasCercano;
}
template <class T>
void ArbolQuad<T>::preorden(NodoQuad<T>* nodo) {
    if (nodo == nullptr) {
        return;
    }
    std::cout<< nodo->obtenerDato().obtenernombre();
    preorden(nodo->obtenerHijoSupIzq());
    preorden(nodo->obtenerHijoSupDer());
    preorden(nodo->obtenerHijoInfIzq());
    preorden(nodo->obtenerHijoInfDer());
}

template <class T>
void ArbolQuad<T>::preOrden() {
    preorden(raiz);
}
