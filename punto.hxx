#include "punto.h"

Punto::Punto(int x, int y)  {
   this->x = x;
    this->y = y;
}

Punto& Punto::operator=(const Punto& p) {
    if (this == &p) {
        return *this;  
    }
    x = p.x;
    y = p.y;
    return *this;
}

bool Punto::operator==(const Punto& p) const {
    return (x == p.x && y == p.y);
}

std::ostream& operator<<(std::ostream& o, const Punto& p) {
    o << "(" << p.x << "," << p.y << ")";
    return o;
}

int* Punto::obtenerx(){
    return &x ;
}

void Punto::fijarx(Punto sx) {
    x = *sx.obtenerx();
}

int* Punto::obtenery() {
    return &y;
}

void Punto::fijary(Punto sy) {
    y = *sy.obtenery();
}
