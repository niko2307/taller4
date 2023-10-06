
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
NodoQuad<T> *ArbolQuad<T>::insertarRecursivo(NodoQuad<T> *actual, T val, Cuadrante cuadrante)
{

    if (actual == nullptr)
    {

        NodoQuad<T> *nuevoNodo = new NodoQuad<T>(val);
        actual = nuevoNodo;

        return actual;
    }

    Punto coordenadas = actual->obtenerDato();
    Cuadrante elementoCuadrante;
    double x = *coordenadas.obtenerx();
    double y = *coordenadas.obtenery();

    if (x <= *val.obtenerx() && y <= *val.obtenery())
    {
        elementoCuadrante = CUADRANTE_1;
    }
    else if (x <= *val.obtenerx() && y > *val.obtenery())
    {
        elementoCuadrante = CUADRANTE_2;
    }
    else if (x > *val.obtenerx() && y <= *val.obtenery())
    {
        elementoCuadrante = CUADRANTE_3;
    }
    else
    {
        elementoCuadrante = CUADRANTE_4;
    }

    if (cuadrante == elementoCuadrante)
    {
        switch (cuadrante)
        {
        case CUADRANTE_1:

            return insertarRecursivo(actual->obtenerHijoSupIzq(), val, cuadrante);
        case CUADRANTE_2:
            return insertarRecursivo(actual->obtenerHijoSupDer(), val, cuadrante);
        case CUADRANTE_3:
            return insertarRecursivo(actual->obtenerHijoInfIzq(), val, cuadrante);
        case CUADRANTE_4:
            return insertarRecursivo(actual->obtenerHijoInfDer(), val, cuadrante);
        }
    }
    else
    {
        switch (elementoCuadrante)
        {
        case CUADRANTE_1:
            return insertarRecursivo(actual->obtenerHijoSupIzq(), val, elementoCuadrante);
        case CUADRANTE_2:
            return insertarRecursivo(actual->obtenerHijoSupDer(), val, elementoCuadrante);
        case CUADRANTE_3:
            return insertarRecursivo(actual->obtenerHijoInfIzq(), val, elementoCuadrante);
        case CUADRANTE_4:
            return insertarRecursivo(actual->obtenerHijoInfDer(), val, elementoCuadrante);
        }
    }

    return actual;
}

template <class T>
bool ArbolQuad<T>::insertar(T &val)
{

    Punto coordenadas = val;

    if (insertarRecursivo(raiz, val, calcularCuadrante(coordenadas)))
    {

        return true;
    }
    else
    {

        return false;
    }
}

template <class T>
NodoQuad<T> *ArbolQuad<T>::buscar(Punto p)
{
    NodoQuad<T> *actual = raiz;
    while (actual != nullptr)
    {
        if (actual->estaEnCuadrante(p))
        {
            return actual;
        }
        else
        {
            actual = actual->obtenerHijo(actual->calcularCuadrante(p));
        }
    }
    return nullptr;
}

template <class T>
Cuadrante ArbolQuad<T>::calcularCuadrante(Punto coordenadas)
{
    double x = *coordenadas.obtenerx();
    int y = *coordenadas.obtenery();
    if (x <= 0.0 && y <= 0)
    {
        return CUADRANTE_1;
    }
    else if (x <= 0.0 && y > 0)
    {
        return CUADRANTE_2;
    }
    else if (x > 0.0 && y <= 0)
    {
        return CUADRANTE_3;
    }
    else
    {
        return CUADRANTE_4;
    }
}
