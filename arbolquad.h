
#ifndef ARBOLQUAD_H
#define ARBOLQUAD_H
#include "punto.h"
#include "nodoquad.h"
#include "fruta.h"
typedef enum
{
    CUADRANTE_1,
    CUADRANTE_2,
    CUADRANTE_3,
    CUADRANTE_4
} Cuadrante;

template <class T>
class ArbolQuad
{
private:
    NodoQuad<T> *raiz;

public:
    ArbolQuad();
    bool insertar(T &val);
    Cuadrante calcularCuadrante(Punto coordenadas);
    NodoQuad<T> *insertarRecursivo(NodoQuad<T> *actual, T val, Cuadrante cuadrante);
    ~ArbolQuad();
    Punto datoRaiz();
    NodoQuad<T> *obtenerRaiz();
    void fijarRaiz(NodoQuad<T> *n_raiz);
    NodoQuad<T> *buscar(Punto p);
    bool esVacio();
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    std::string buscarQuad(T &val);
    void buscarRecursivo(NodoQuad<T> *actual, double peso, std::string color, std::string &nombreFrutaCercana, double &pesoFrutaCercana, double &distanciaMinima);
};
#include "arbolquad.hxx"
#endif // ARBOLQUAD.H
