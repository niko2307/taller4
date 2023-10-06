#include "punto.h"

Punto::Punto()
{
    this->x = 0;
    this->y = 0;
}
Punto::Punto(double x, int y, std::string clasificacion)
{
    this->x = x;
    this->y = y;
    this->clasificacion = clasificacion;
}

Punto::Punto(double x, int y)
{
    this->x = x;
    this->y = y;
    this->clasificacion = "";
}
/*
Punto& Punto::operator=( Punto& p) {
    if (this == &p) {
        return *this;
    }
    x = p.x;
    y = p.y;
    return *this;
}

bool Punto::operator==(Punto& p)  {
    return (x == p.x && y == p.y);
}

std::ostream& operator<<(std::ostream& o,  Punto& p) {
    o << "(" << p.x << "," << p.y << ")";
    return o;
}
*/
double *Punto::obtenerx()
{
    return &x;
}

void Punto::fijarx(Punto sx)
{
    this->x = *sx.obtenerx();
}

int *Punto::obtenery()
{
    return &y;
}

void Punto::fijary(Punto sy)
{
    this->y = *sy.obtenery();
}

std::string Punto::obtenernombre()
{
    return this->clasificacion;
}
void Punto::fijarnombre(Punto snombre)
{
    this->clasificacion = snombre.obtenernombre();
}
