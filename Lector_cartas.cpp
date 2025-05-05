#include <string>
#include <iostream>
//leer archivos
#include <fstream>
// dividir lineas con divisor;
#include <sstream>
#include "Carta.h"
using namespace std;


class lector_cartas {
private:
    Carta* array_cartas = nullptr; // Array dinámico de cartas
	int contador = 0; // Contador de cartas
	int capacidad = 0; // Capacidad del array
  

public:
    // Constructor

    lector_cartas() {
        

    }
    Carta* leer_cartas() {
	
        string nombre, puntosStr, habilidad; // Variables para almacenar los datos de cada carta
        ifstream archivo("cartas.txt");
		printf("%s", archivo.is_open() ? "Archivo abierto correctamente.\n" : "Error al abrir el archivo.\n");
        string linea;
        while (getline(archivo, linea)) {
            if (!linea.empty() && linea[0] != '#') {
                capacidad++;
            }
        }
		

		array_cartas = new Carta[capacidad]; // Crear el array dinámico de cartas

        archivo.clear();
        archivo.seekg(0);

        while (getline(archivo, linea)) {
            if (linea.empty() || linea[0] == '#') continue;
            stringstream ss(linea);
            getline(ss, nombre, ';');
            getline(ss, puntosStr, ';');
            getline(ss, habilidad, ';');

            int puntos = stoi(puntosStr);
            array_cartas[contador++] = Carta(nombre, puntos, habilidad);
           
        }

        archivo.close();
        return array_cartas;
    }
	int mostrar_cartas() {
		for (int i = 0; i < contador; i++) {
			cout << "Carta " << i + 1 << ": " << endl;
			array_cartas[i].mostrar();
            
		}
        return 1;
    }
    

    // Destructor
    ~lector_cartas() {
        delete[] array_cartas;
    }

    Carta* get_cartas() {
        return array_cartas;
    }


    int get_contador() {
        return contador;
    }

};
