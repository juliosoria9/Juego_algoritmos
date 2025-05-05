#include <cstdlib>
#include "Nodo.cpp"
#include "Carta.h"
using namespace std;

class ListaCircular {
private:
    Nodo* lista;
    int n;

    Nodo* getNodo(int posicion) {
        Nodo* aux = lista;
        for (int i = 0; i < posicion; i++) {
            aux = aux->siguienteNodo;
        }
        return aux;
    }

public:
    ListaCircular() {
        lista = nullptr;
        n = 0;
    }

    // Retorna la carta en la posición indicada
    Carta getCarta(int posicion) {
        Nodo* aux = getNodo(posicion);
        return aux->elemento;
    }

    // Cambia la carta en la posición indicada
    void setCarta(int posicion, const Carta& nuevaCarta) {
        Nodo* nodo = getNodo(posicion);
        if (nodo != nullptr) {
            nodo->elemento = nuevaCarta;
        }
    }

    int getN() {
        return n;
    }

    // Inserta una nueva carta en la posición indicada
    void insertar(int posicion, const Carta& nuevaCarta) {
        Nodo* nuevo = new Nodo();
        nuevo->elemento = nuevaCarta;

        if (posicion == 0) {
            if (lista == nullptr) {
                nuevo->siguienteNodo = nuevo;
                nuevo->anteriorNodo = nuevo;
            }
            else {
                nuevo->siguienteNodo = lista;
                nuevo->anteriorNodo = lista->anteriorNodo;
                lista->anteriorNodo->siguienteNodo = nuevo;
                lista->anteriorNodo = nuevo;
            }
            lista = nuevo;
        }
        else {
            Nodo* nodoAnterior = getNodo(posicion - 1);
            if (nodoAnterior != nullptr) {
                nuevo->siguienteNodo = nodoAnterior->siguienteNodo;
                nuevo->anteriorNodo = nodoAnterior;
                nodoAnterior->siguienteNodo->anteriorNodo = nuevo;
                nodoAnterior->siguienteNodo = nuevo;
            }
        }
        n++;
    }

    void eliminar(int posicion) {
        if (posicion == 0) {
            if (lista != nullptr) {
                Nodo* nodoEliminar = lista;
                if (n == 1) {
                    lista = nullptr;
                }
                else {
                    lista = lista->siguienteNodo;
                    lista->anteriorNodo = nodoEliminar->anteriorNodo;
                    nodoEliminar->anteriorNodo->siguienteNodo = lista;
                }
                delete nodoEliminar;
                n--;
            }
        }
        else {
            Nodo* nodoEliminar = getNodo(posicion);
            if (nodoEliminar != nullptr) {
                nodoEliminar->anteriorNodo->siguienteNodo = nodoEliminar->siguienteNodo;
                nodoEliminar->siguienteNodo->anteriorNodo = nodoEliminar->anteriorNodo;
                delete nodoEliminar;
                n--;
            }
        }
    }

    void girar(int p) {
        if (p > 0) {
            for (int i = 0; i < p; i++) {
                lista = lista->siguienteNodo;
            }
        }
        else if (p < 0) {
            for (int i = 0; i < -p; i++) {
                lista = lista->anteriorNodo;
            }
        }
    }

    // Mostrar todas las cartas (útil para pruebas)
    void mostrar() {

        if (lista == nullptr) {
			printf("**ERROR** --La lista está vacía.\n");
            return;
        }
		  
        Nodo* actual = lista;
        for (int i = 0; i < n; ++i) {
			actual->elemento.mostrar();
            actual = actual->siguienteNodo;
        }
    }

    ~ListaCircular() {
        if (lista == nullptr) return;
        Nodo* actual = lista;
        for (int i = 0; i < n; ++i) {
            Nodo* siguiente = actual->siguienteNodo;
            delete actual;
            actual = siguiente;
        }
    }
	// Ordenar la lista de cartas por puntos usando el algoritmo burbuja
    void ordenar() {
        if (n <= 1 || lista == nullptr) return; //  Si la lista esta vacia o tiene solo una carta, no hay nada que ordenar

        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                 // Obtener la carta actual y la siguiente
                Carta actual = getCarta(j);
                Carta siguiente = getCarta(j + 1);

                if (actual.get_puntos() < siguiente.get_puntos()) {
                    // Intercambiar cartas
                    setCarta(j, siguiente);
                    setCarta(j + 1, actual);
                }
            }
        }
    }

    
};
