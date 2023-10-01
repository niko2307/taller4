#include "arbolkd.h"
#include "nodokd.h"

template <class T>
bool ArbolKD<T>::insert(T &val)
{
    insertRec(obtenerRaiz(), val);
    return true;
}

template <class T>
NodoKD<T> ArbolKD<T>::insertRec(NodoKD<T> *&root, Punto p, int depth = 0)
{
    NodoKD<T> *nuevo = new NodoKD<T>();
    if (root == nullptr)
    {
        root = new NodoKD(p);
        return root;
    }

    int cd = depth % 2;
    if (cd == 0)
    {
        if (p.obtenerx() < root->obtenerDato().obtenerx())
        {
            nuevo = insertar(root->obtenerHijoIzq(), p, depth + 1);
        }
        else
        {
            nuevo = insertar(root->obtenerHijoDer(), p, depth + 1);
        }
    }
    else
    {
        if (p.obtenery() < root->obtenerDato().obtenery())
        {
            nuevo = insert(root->obtenerHijoIzq(), p, depth + 1);
        }
        else
        {
            nuevo = insert(root->obtenerHijoDer(), p, depth + 1);
        }
    }
    return nuevo;
}