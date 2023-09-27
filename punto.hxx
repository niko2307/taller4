#include "punto.h"

Punto::Punto(int x, int y) : x(x), y(y) {}

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
