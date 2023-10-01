#include "fruta.h"

Fruta::Fruta(std::string &tipo, double p, int col)
{
    clase = tipo;
    peso = p;
    color = col;
}
Fruta::Fruta()
{
}

std::string Fruta::obtenerClase()
{
    return clase;
}

double Fruta::obtenerPeso()
{
    return peso;
}

int Fruta::obtenerColor()
{
    return color;
}

void Fruta::fijarClase(std::string &tipo)
{
    clase = tipo;
}

void Fruta::fijarPeso(double p)
{
    peso = p;
}

void Fruta::fijarColor(int col)
{
    color = col;
}

// bool Fruta::inarbolquad(ArbolQuad<Fruta> &quad)
// {
//     Fruta &frutaActual = *this; // Crear una referencia a la fruta actual  para insertarlo en el arbol de quad
//     if (quad.insertar(frutaActual))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool Fruta::inarbolkd(ArbolKD<Fruta> &kd)
// {
//     Fruta &frutaActual = *this; // Crear una referencia a la fruta actual  para insertarlo en el arbol de quad
//     if (kd.insertar(frutaActual))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
