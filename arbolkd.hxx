#include <cmath>
#include "arbolkd.h"
#include "fruta.h"
#include <limits>



template <class T>
bool ArbolKD<T>::insert(double peso, int color,std::string clase )
{
    std::cout<<"entroinsertar"<<std::endl;
    Punto p (peso, color, clase);
     std::cout <<"puntox: "<<*p.obtenerx()<<"puntoy: "<<*p.obtenery()<<std::endl;
   
    NodoKD<T>* nodo = this->raiz;
    NodoKD<T>* padre = this->raiz;
    bool insertado = false;
	bool duplicado = false;
    int depth=0;
    
    std::cout <<"puntox: "<<*p.obtenerx()<<"puntoy: "<<*p.obtenery()<<std::endl;
    if(this->raiz == nullptr){
        
        this->raiz = new NodoKD<T>(p);
        insertado = true;
        std::cout<<"entroifnuevoraiz"<<std::endl;
        return insertado;
    }

    while(nodo != nullptr){
        std::cout<<"entrowhilenodo"<<std::endl;
        padre = nodo;
        int cd = depth % 2;

    if (cd == 0)
    {
        std::cout<<"cuadrante1"<<std::endl;
        std::cout<<" "<<std::endl;
       if (*p.obtenerx() < *nodo->obtenerDato().obtenerx())
        {
            std::cout<<"obtener x hijo izq "<<std::endl;
           nodo = nodo -> obtenerHijoIzq();
        } 
        else if (*p.obtenerx() > *nodo->obtenerDato().obtenerx())
        {
            std::cout<<"obtener x hijo der "<<std::endl;
           nodo = nodo -> obtenerHijoDer();
           std::cout<<"obtener hijo izq "<<std::endl;
            //std::cout << "nombre: " << nodo->obtenerDato().obtenernombre()  << std::endl;
       
        }
    }else
    {
       std::cout<<"cuadrante2"<<std::endl;
        if (*p.obtenery() < *nodo->obtenerDato().obtenery())
        {
            std::cout<<"obtener y hijo izq "<<std::endl;
           nodo = nodo -> obtenerHijoIzq();
        } 
        else if (*p.obtenery() > *nodo->obtenerDato().obtenery())
        {
            std::cout<<"obtener y hijo der "<<std::endl;
            nodo = nodo -> obtenerHijoDer();
        }
    }

    if(nodo !=nullptr && *p.obtenerx() == *nodo->obtenerDato().obtenerx() &&  *p.obtenery() == *nodo->obtenerDato().obtenery()){
        duplicado = true;
        std::cout<<"es duplicado"<<std::endl;
        break;
    }

    depth++; 
    }
    if(!duplicado){
        std::cout<<"no es duplicado"<<std::endl;
       NodoKD<T>* nuevo = new NodoKD<T>(p);
       int cd = (depth-1) % 2;
        
           if (cd == 0)
            {
            if (*p.obtenerx() < *nodo->obtenerDato().obtenerx())
                {
                    std::cout<<"fijar hijo izquierdo "<<std::endl;
                padre -> fijarHijoIzq(nuevo);
                } 
                else if (*p.obtenerx() > *nodo->obtenerDato().obtenerx())
                {
                    std::cout<<"fijar hijo derecho "<<std::endl;
                    padre -> fijarHijoDer(nuevo);
                }
            }else if (cd == 1)
            {
                if (*p.obtenery() < *nodo->obtenerDato().obtenery())
                {
                    std::cout<<"fijar hijo izquierdo "<<std::endl;
                padre -> fijarHijoIzq(nuevo);
                } 
                else if (*p.obtenery() > *nodo->obtenerDato().obtenery())
                {
                    std::cout<<"fijar hijo derecho "<<std::endl;
                    padre -> fijarHijoDer(nuevo);
                }
            }

            insertado = true;

    }
    return insertado;

}
 

template <class T>
ArbolKD<T>::ArbolKD() {
    raiz = NULL;
}

template <class T>
ArbolKD<T>::ArbolKD(Punto p) {
    raiz = new NodoKD<T>(p);
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

// Método de recorrido en orden (in-order)
template <class T>
void ArbolKD<T>::inOrden(NodoKD<T>* nodo) {
    if (nodo != nullptr) {
        inOrden(nodo->obtenerHijoIzq());
        std::cout << "nombre: " << nodo->obtenerDato().obtenernombre() << " peso: " << *nodo->obtenerDato().obtenerx() << " color: " << *nodo->obtenerDato().obtenery() << std::endl;
        inOrden(nodo->obtenerHijoDer());
    }
}

// Método de recorrido preorden
template <class T>
void ArbolKD<T>::preOrden(NodoKD<T>* nodo) {
    if (nodo != nullptr) {
        std::cout << "nombre: " << nodo->obtenerDato().obtenernombre() << " peso: " << *nodo->obtenerDato().obtenerx() << " color: " << *nodo->obtenerDato().obtenery() << std::endl;
        preOrden(nodo->obtenerHijoIzq());
        preOrden(nodo->obtenerHijoDer());
    }
}

// Método de recorrido postordenArbolKD<T>::
template <class T>
void ArbolKD<T>::posOrden(NodoKD<T>* nodo) {
    if (nodo != nullptr) {
        posOrden(nodo->obtenerHijoIzq());
        posOrden(nodo->obtenerHijoDer());
        std::cout << "nombre: " << nodo->obtenerDato().obtenernombre() << " peso: " << *nodo->obtenerDato().obtenerx() << " color: " << *nodo->obtenerDato().obtenery() << std::endl;
    }
}

// Funciones públicas para iniciar los recorridos desde la raíz del Árbol KD
template <class T>
void ArbolKD<T>::inOrden() {
    inOrden(this->raiz);
}

template <class T>
void ArbolKD<T>::preOrden() {
    preOrden(this->raiz);
}

template <class T>
void ArbolKD<T>::posOrden() {
    posOrden(this->raiz);
}
