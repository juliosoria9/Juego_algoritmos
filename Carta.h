#ifndef CARTA_H
#define CARTA_H

#include <string>
#include <iostream>
using namespace std;

class Carta {
private:
    string nombre;
    float puntos;
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
        cout << "Nombre: " << nombre
            << ", Puntos: " << puntos
            << ", Habilidad: " << habilidad_especial << endl;
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
    //setters
	void set_nombre(string nombre) {
		this->nombre = nombre;
	}
	void set_puntos(int puntos) {
		this->puntos = puntos;
	}
	void set_habilidad_especial(string habilidad_especial) {
		this->habilidad_especial = habilidad_especial;
	}
};

#endif // CARTA_H