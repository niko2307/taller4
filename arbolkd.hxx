#include <cmath>
#include "arbolkd.h"
#include "fruta.h"
#include <limits>

template <class T>
bool ArbolKD<T>::insert(T &val)
{
    insertRec(this->raiz, val,0);
    return true;
}

template <class T>
NodoKD<T>* ArbolKD<T>::insertRec(NodoKD<T> *root, Punto p, int depth )
{
    
    NodoKD<T> *nuevo = new NodoKD<T>();
    if (root == NULL)
    {
        root = new NodoKD<T>(p);
        return root;
    }

    int cd = depth % 2;
    if (cd == 0)
    {
        if (p.obtenerx() < root->obtenerDato().obtenerx())
        {
            nuevo = insertRec(root->obtenerHijoIzq(), p, depth + 1);
        }
        else
        {
            nuevo = insertRec(root->obtenerHijoDer(), p, depth + 1);
        }
    }
    else
    {
        if (p.obtenery() < root->obtenerDato().obtenery())
        {
            nuevo = insertRec(root->obtenerHijoIzq(), p, depth + 1);
        }
        else
        {
            nuevo = insertRec(root->obtenerHijoDer(), p, depth + 1);
        }
    }
    return nuevo;
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
std::string ArbolKD<T>::buscarFruta(NodoKD<T>* nodo, double peso, int color, double& distanciaMinima) {
    if (nodo == nullptr) {
        return "";
    }
    double distancia = calcularDistancia(*nodo->obtenerDato().obtenerx(), *nodo->obtenerDato().obtenery(), peso, color);
    if (distancia < distanciaMinima) {
        distanciaMinima = distancia;
        return nodo->obtenerDato().obtenernombre();
    }
    int profundidad = obtenerProfundidad(nodo);
    int cd = profundidad % 2;
    if (cd == 0) {
        if (peso < *nodo->obtenerDato().obtenerx()) {
            return buscarFruta(nodo->obtenerHijoIzq(), peso, color, distanciaMinima);
        } else {
            return buscarFruta(nodo->obtenerHijoDer(), peso, color, distanciaMinima);
        }
    } else {
        if (color < *nodo->obtenerDato().obtenery()) {
            return buscarFruta(nodo->obtenerHijoIzq(), peso, color, distanciaMinima);
        } else {
            return buscarFruta(nodo->obtenerHijoDer(), peso, color, distanciaMinima);
        }
    }
}

template <class T>
std::string ArbolKD<T>::buscarFruta(double peso, int color) {
    double distanciaMinima = std::numeric_limits<double>::max();
    return buscarFruta(this->raiz, peso, color, distanciaMinima);
}

template <class T>
double ArbolKD<T>::calcularDistancia(double x1, int y1, double x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}



template <class T>
int ArbolKD<T>::obtenerProfundidad(NodoKD<T>* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    int profundidadIzq = obtenerProfundidad(nodo->obtenerHijoIzq());
    int profundidadDer = obtenerProfundidad(nodo->obtenerHijoDer());
    return std::max(profundidadIzq, profundidadDer) + 1;
}