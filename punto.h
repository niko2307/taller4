#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

class Punto {

private:
    int x;
    int y;

public:
    Punto(int x, int y);  // Constructor
    Punto& operator=(const Punto& p);
    bool operator==(const Punto& p) const;
    friend std::ostream& operator<<(std::ostream& o, const Punto& p);


};

#endif // PUNTO_H
