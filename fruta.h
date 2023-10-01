#ifndef FRUTA_H
#define FRUTA_H

#include <string>

class Fruta
{
private:
    std::string clase;
    double peso;
    int color;

public:
    Fruta();
    Fruta(std::string &tipo, double p, int col);
    std::string obtenerClase();
    double obtenerPeso();
    int obtenerColor();
    void fijarClase(std::string &tipo);
    void fijarPeso(double p);
    void fijarColor(int col);
};

#endif // FRUTA_H
