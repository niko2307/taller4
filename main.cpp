#include <ctime>
#include <cmath> 
#include <iostream>
#include <fstream> 
#include "arbolquad.h" 
#include "fruta.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <nombre_del_archivo>" << endl;
        return 1;
    }

    string nombreArchivo = argv[1];
    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cout << "Error al abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }
   ArbolQuad<Fruta> quadtree;
   int numFrutas;
    archivo >> numFrutas;

    for (int i = 0; i < numFrutas; ++i) {
        string clase;
        double peso;
        int color;
        archivo >> clase >> peso >> color;

        Fruta fruta(clase, peso, color);

        fruta.inarbolquad(quadtree);
       if (fruta.inarbolquad(quadtree)) {
            cout << "Fruta insertada en Quadtree: " << clase << ", Peso: " << peso << ", Color: " << color << endl;
        } else {
            cout << "Error al insertar la fruta en Quadtree" << endl;
        }
    }


    int n;
    std::clock_t init_time = std::clock();
    int freq = 99998;
    archivo >> n;

    for (int i = 2; i <= n; ++i)
        for (int j = sqrt(i); j > 1; --j)
            if (i % j == 0) {
                --freq;
                break;
            }

    std::clock_t end_time = std::clock();
    cout << "The number of primes lower than 100000 is: " << freq << endl;
    double calc_time = (end_time - init_time) / double(CLOCKS_PER_SEC);
    cout << " It took me " << calc_time << " seconds.\n";

    archivo.close(); 

    return 0;
}

