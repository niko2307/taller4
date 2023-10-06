#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

class Punto
{

private:
    double x; // peso
    int y;    // color
    std::string clasificacion;

public:
    Punto();
    Punto(double x, int y, std::string clasificacion);
    Punto(double x, int y);
    /*
    Punto& operator=( Punto& p);
    bool operator==( Punto& p) ;
    friend std::ostream& operator<<(std::ostream& o, Punto& p);
   */
    double obtenerx();
    int obtenery();
    std::string obtenernombre();
    void fijarx(Punto sx);
    void fijary(Punto sy);
    void fijarnombre(Punto snombre);
};
#include "punto.cxx"

#endif // PUNTO_H
