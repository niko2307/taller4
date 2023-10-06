
#include <ctime>
#include <cmath> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "arbolquad.h" 
#include "arbolkd.h"
#include "fruta.h"

#include "punto.h"

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


      ArbolQuad<Punto> arbolQuad;
      ArbolKD<Punto> arbolkd;
      

 std::string linea;
         std::clock_t start_arbolQuad = std::clock();
         std::clock_t start_arbolkd = std::clock();
    while(getline(archivo, linea)){
     
        std::istringstream iss (linea);
        //Fruta fruta;
        string clase;
        double peso;
        int color;
        archivo >> clase >> peso >> color;
        Punto val(peso, color, clase);

       
          bool insertQUAD=arbolQuad.insertar(val);
          bool insertkd= arbolkd.insert(val);
          


          cout<<"se insero correctamente en los arboles quad y kd  "<<endl;
    }

    double pesoBusqueda, colorBusqueda;
    std::cout << "Ingrese el peso que desea buscar: ";
    std::cin >> pesoBusqueda;
    std::cout << "Ingrese el color que desea buscar: ";
    std::cin >> colorBusqueda;

 // Realizar la búsqueda y medir el tiempo de ejecución
  

    arbolkd.posOrden();
    std::string nombreFruta = arbolkd.buscarFruta( pesoBusqueda,colorBusqueda) ;
    
    std::cout << "La fruta encontrada es: " << nombreFruta << std::endl;
    

           std::clock_t end_arbolQuad = std::clock();
           std::clock_t end_arbolkd = std::clock();
           double tiempo_arbolQuad = static_cast<double>(end_arbolQuad - start_arbolQuad) / CLOCKS_PER_SEC;
           double tiempo_arbolkd = static_cast<double>(end_arbolkd - start_arbolkd) / CLOCKS_PER_SEC;
    
        
           std::cout << "Tiempo transcurrido en arbolQuad: " << tiempo_arbolQuad << " segundos" << std::endl;
           std::cout << "Tiempo transcurrido en arbolkd: " << tiempo_arbolkd << " segundos" << std::endl;  
       

    archivo.close(); 
    return 0;
}

