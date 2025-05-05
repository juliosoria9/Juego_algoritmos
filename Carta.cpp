#include <string>
#include <iostream>

using namespace std;

class Carta {
private:
    string nombre;
    int puntos;
    string habilidad_especial;

public:
    // Constructor
    Carta(string nombre, int puntos, string habilidad_especial) {
        this->nombre = nombre;
        this->puntos = puntos;
        this->habilidad_especial = habilidad_especial;
    }
	// Constructor por defecto
	Carta() {
		this->nombre = "";
		this->puntos = 0;
		this->habilidad_especial = "";
	}
    // Metodo para mostrar la carta
    void mostrar() const {
        cout << "[Nombre: " << nombre
            << " | Puntos: " << puntos
            << " | Habilidad: " << (habilidad_especial.empty() ? "Ninguna" : habilidad_especial)
            << "]" << endl;
    }






	// Getters
    string get_nombre() const {
        return nombre;
    }
    int get_puntos() const {
        return puntos;
    }
    string get_habilidad_especial() const {
        return habilidad_especial;
    }
};

